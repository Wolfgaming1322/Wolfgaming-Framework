/*
    File: fn_lockerFilter.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Used as a refresher for the locker inventory.   
*/
private["_bad","_display","_ammo","_index","_item","_classname","_count","_lInv","_pInv","_items","_inInventory","_data","_type","_cargo","_section","_primaryCargo","_secondaryCargo","_handgunCargo","_uniformCargo","_vestCargo","_backpackCargo","_helmet","_facewear","_val","_name","_var","_icon"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
disableSerialization;

_cargo = getUnitLoadout player;
_primaryCargo = _cargo select 0;
_secondaryCargo = _cargo select 1;
_handgunCargo = _cargo select 2;
_uniformCargo = _cargo select 3;
_vestCargo = _cargo select 4;
_backpackCargo = _cargo select 5;
_helmet = _cargo select 6;
_facewear = _cargo select 7;
_items = [];
_inInventory = [];
_bad = false;
_type = _this select 1;
_display = findDisplay 5000;
_lInv = _display displayCtrl 5002;
_pInv = _display displayCtrl 5003;
_val = 0;
_name = "";
_var = "";
_icon = "";
lbClear _lInv;
lbClear _pInv;
_display setVariable ["type",_type];

(_display displayCtrl 5004) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Weight"))+ " %1/%2",((locker getVariable "Trunk") select 1),lockerTotalWeight];
_data = locker getVariable ["Trunk",[]];
if (count _data isEqualTo 0) then {locker setVariable ["Trunk",[[],0,0,-1],false]; _data = [];} else {_data = (_data select 0);};

switch (_type) do {
    default {
        if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
            _items = ("true" configClasses (missionConfigFile >> "VirtualItems"));
        } else {
            _items = life_inv_items;
        };      
    };
    case 1: {
        {
            if (!(_x isEqualTo [])) then {
                if (((_x select 1) isEqualTo "") && ((_x select 2) isEqualTo "") && ((_x select 3) isEqualTo "") && ((_x select 4) isEqualTo []) && ((_x select 5) isEqualTo []) && ((_x select 6) isEqualTo "")) then {
                    _items pushBack [(_x select 0),1];
                } else {
                    _bad = true;
                };
            }
        } forEach [_primaryCargo,_secondaryCargo,_handgunCargo];
        _cargo = [];
        {
            if (!(_x isEqualTo [])) then {
                if (typeName(_x) == "ARRAY") then {
                    for "_i" from 0 to ((count (_x select 1))-1) do {
                        _cargo pushBack ((_x select 1) select _i);
                    };
                };
            };
        } forEach [_uniformCargo,_vestCargo,_backpackCargo];
        if (_bad) then {
            systemChat format[(getText(missionConfigFile >> "Cation_Locker" >> "WarningWeapon"))];
        };
        {
            if (!(isNil {_x})) then {
                if (typeName(_x select 0) != "ARRAY") then {
                    _inInventory pushBack [_x select 0,_x select 1];
                } else { 
                    _inInventory pushBack [(_x select 0 select 0),_x select 1];
                };
            };
        } forEach _cargo;
        {
            if (isClass (configFile >> "CfgWeapons" >> (_x select 0))) then {
                if (getNumber(configFile >> "CfgWeapons" >> (_x select 0) >> "type") in [1,2,4]) then {
                    _count = _x select 1;
                    _classname = _x select 0;
                    _index = [_classname,_items,-1] call cat_locker_fnc_index;
                    if (_index isEqualTo -1) then {
                        _items pushBack [_classname,_count];
                    } else {
                        _item = _items select _index;
                        _items set[_index,[(_item select 0),(_item select 1) + _count]];
                    };
                };
            };
        } forEach _inInventory;         
    };
    case 2: {
        _cargo = [];
        {
            if (!(_x isEqualTo [])) then {
                if ((typeName(_x) == "ARRAY")) then {
                    for "_i" from 0 to ((count (_x select 1))-1) do {
                        _cargo pushBack ((_x select 1) select _i);
                    };
                };
            };
        } forEach [_uniformCargo,_vestCargo,_backpackCargo];
        {
            if (!(isNil {_x})) then {
                if (typeName(_x select 0) != "ARRAY") then {
                    if (isClass (configFile >> "CfgMagazines" >> (_x select 0))) then {
                        _inInventory pushBack [_x select 0,_x select 1,_x select 2];
                    };
                };
            };
        } forEach _cargo;
        {
            _count = _x select 1;
            _ammo = _x select 2;
            _classname = _x select 0;
            _index = [_classname,_items,_ammo] call cat_locker_fnc_index;
            if (_index isEqualTo -1) then {
                _items pushBack [_classname,_count,_ammo];
            } else {
                _item = _items select _index;
                _items set[_index,[(_item select 0),(_item select 1) + _count,_ammo]];
            };
        } forEach _inInventory;  
    };
    case 3: {
        _cargo = [];
        {
            if (!(_x isEqualTo [])) then {
                if ((typeName(_x) == "ARRAY")) then {
                    for "_i" from 0 to ((count (_x select 1))-1) do {
                        _cargo pushBack ((_x select 1) select _i);
                    };
                };
            };
        } forEach [_uniformCargo,_vestCargo,_backpackCargo];
        {
            if (!(isNil {_x})) then {
                if (typeName(_x select 0) != "ARRAY") then {
                    if (isClass (configFile >> "CfgWeapons" >> (_x select 0))) then {
                        _base = [(configfile >> "CfgWeapons" >> (_x select 0)),true ] call BIS_fnc_returnParents;
                        if (!(("H_HelmetB" in _base) || ("Uniform_Base" in _base) || ("HelmetBase" in _base) || ("Vest_Camo_Base" in _base) || ("Vest_NoCamo_Base" in _base))) then {
                            if (("ItemCore" in _base) || ("Binocular" in _base)) then {
                                _inInventory pushBack [_x select 0,_x select 1];
                            };
                        };
                    };
                } else {
                    if (isClass (configFile >> "CfgWeapons" >> (_x select 0) select 0)) then {
                        _base = [(configfile >> "CfgWeapons" >> (_x select 0) select 0),true ] call BIS_fnc_returnParents;
                        if (!(("H_HelmetB" in _base) || ("Uniform_Base" in _base) || ("HelmetBase" in _base) || ("Vest_Camo_Base" in _base) || ("Vest_NoCamo_Base" in _base))) then {
                            if (("ItemCore" in _base) || ("Binocular" in _base)) then {
                                _inInventory pushBack [(_x select 0) select 0,_x select 1];
                            };
                        };
                    };
                };
            };
        } forEach _cargo;
        {
            _count = _x select 1;
            _classname = _x select 0;
            _index = [_classname,_items,-1] call cat_locker_fnc_index;
            if (_index isEqualTo -1) then {
                _items pushBack [_classname,_count];
            } else {
                _item = _items select _index;
                _items set[_index,[(_item select 0),(_item select 1) + _count]];
            };
        } forEach _inInventory;  
    };
    case 4: {
        _cargo = [];
        {
            if (!(_x isEqualTo [])) then {
                if ((_x select 1) isEqualTo []) then {
                    _inInventory pushBack [(_x select 0),1];
                } else {
                    _bad = true;
                    for "_i" from 0 to ((count (_x select 1))-1) do {
                        _cargo pushBack ((_x select 1) select _i);
                    };
                };
            };
        } forEach [_uniformCargo,_vestCargo,_backpackCargo];
        if (_bad) then {
            systemChat format[(getText(missionConfigFile >> "Cation_Locker" >> "WarningClothing"))]; 
        };
        {
            if (!(_x isEqualTo "")) then {
                _inInventory pushBack [_x,1];
            };
        } forEach [_facewear,_helmet];
        {
            if (!(isNil {_x})) then {
                if (typeName(_x select 0) != "ARRAY") then {
                    if (isClass (configFile >> "CfgWeapons" >> (_x select 0))) then {
                        _base = [(configfile >> "CfgWeapons" >> (_x select 0)),true ] call BIS_fnc_returnParents;
                        if (("H_HelmetB" in _base) || ("Uniform_Base" in _base) || ("HelmetBase" in _base) || ("Vest_Camo_Base" in _base) || ("Vest_NoCamo_Base" in _base)) then {
                            _inInventory pushBack [_x select 0,1];
                        };
                    } else {
                        if (isClass (configFile >> "CfgGlasses" >> (_x select 0))) then {
                            _inInventory pushBack [_x select 0,1];
                        } else {
                            if (isClass (configFile >> "CfgVehicles" >> (_x select 0))) then {
                                _inInventory pushBack [_x select 0,1];
                            };
                        };
                    };
                };
            };
        } forEach _cargo;
        {
            _count = _x select 1;
            _classname = _x select 0;
            _index = [_classname,_items,-1] call cat_locker_fnc_index;
            if (_index isEqualTo -1) then {
                _items pushBack [_classname,_count];
            } else {
                _item = _items select _index;
                _items set[_index,[(_item select 0),(_item select 1) + _count]];
            };
        } forEach _inInventory; 
    };
};
//Player Inventory Items
{    
    switch (_type) do {
        case 0 : {
            if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
                _val = missionNamespace getVariable [format["life_inv_%1",(getText(missionConfigFile >> "VirtualItems" >> (configName _x) >> "variable"))],0];
            } else {
                _val = missionNamespace getVariable [_x,0];
            };
            if (_val > 0) then {
                if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
                    _name = localize (getText(_x >> "displayName"));
                    _var = configName _x;
                } else {
                    _name = [_x] call life_fnc_varToStr;
                    _var = [_x,1] call life_fnc_varHandle;
                };
                _pInv lbAdd format["[%1] - %2",_val,_name];
                _pInv lbSetData [(lbSize _pInv)-1,_var];
                _pInv lbSetTooltip [lbSize(_pInv)-1,format ["%1 - %3: %2",_name,_val,(getText(missionConfigFile >> "Cation_Locker" >> "Amount"))]];
                _pInv lbSetValue [(lbSize _pInv)-1,_val];
                if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
                    _icon = (getText(_x >> "icon"));
                };
                if (!(_icon isEqualTo "")) then {
                    _pInv lbSetPicture [(lbSize _pInv)-1,_icon];
                };
            };
        };
        default {
            _section = switch (true) do {
                case (isClass(configFile >> "CfgMagazines" >> (_x select 0))): {"CfgMagazines"};
                case (isClass(configFile >> "CfgWeapons" >> (_x select 0))): {"CfgWeapons"};
                case (isClass(configFile >> "CfgVehicles" >> (_x select 0))): {"CfgVehicles"};
                case (isClass(configFile >> "CfgGlasses" >> (_x select 0))): {"CfgGlasses"};
                default {"CfgWeapons"};
            };
            if (!(_section isEqualTo "CfgMagazines")) then {
                _pInv lbAdd format["[%2] - %1",(getText(configFile >> _section >> (_x select 0) >> "displayName")),(_x select 1)];
                _pInv lbSetTooltip [lbSize(_pInv)-1,format ["%1 - %3: %2",(getText(configFile >> _section >> (_x select 0) >> "displayName")),(_x select 1),(getText(missionConfigFile >> "Cation_Locker" >> "Amount"))]];
                _pInv lbSetData [(lbSize _pInv)-1,(_x select 0)];
            } else {
                _pInv lbAdd format["[%2] - (%3) %1",(getText(configFile >> _section >> (_x select 0) >> "displayName")),(_x select 1),(_x select 2)];
                _pInv lbSetTooltip [lbSize(_pInv)-1,format ["%1 - %4: %2 - %5: %3",(getText(configFile >> _section >> (_x select 0) >> "displayName")),(_x select 1),(_x select 2),(getText(missionConfigFile >> "Cation_Locker" >> "Amount")),(getText(missionConfigFile >> "Cation_Locker" >> "AmmoCount"))]];
                _pInv lbSetData [(lbSize _pInv)-1,format ["%1,%2",(_x select 0),(_x select 2)]];
            };
            _pInv lbSetValue [(lbSize _pInv)-1,(_x select 1)];
			_icon = (getText(configFile >> _section >> (_x select 0) >> "picture"));
            if (!(_icon isEqualTo "")) then {
                _pInv lbSetPicture [(lbSize _pInv)-1,_icon];
            };
        };
    };
} forEach _items;

//Locker Inventory Items
{
    switch (_type) do {
        case 0: {
            if ((_x select 0) isEqualTo _type) then {
                if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
                    _name = getText(missionConfigFile >> "VirtualItems" >> (_x select 1) >> "displayName");
                    _name = localize _name;
                } else {
                    _name = [([(_x select 1),0] call life_fnc_varHandle)] call life_fnc_varToStr;
                };
                _val = (_x select 2);

                if (_val > 0) then {
                    _lInv lbAdd format["[%1] - %2",_val,_name];
                    _lInv lbSetData [(lbSize _lInv)-1,(_x select 1)];
                    _lInv lbSetTooltip [lbSize(_lInv)-1,format ["%1 - %3: %2",_name,_val,(getText(missionConfigFile >> "Cation_Locker" >> "Amount"))]];
                    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 3) then {
                        _icon = getText(missionConfigFile >> "VirtualItems" >> (_x select 1) >> "icon");
                        if (!(_icon isEqualTo "")) then {
                            _lInv lbSetPicture [(lbSize _lInv)-1,_icon];
                        };
                    };
                    _lInv lbSetValue [(lbSize _lInv)-1,_val];
                };
            };
        };
        default {
            if ((_x select 0) isEqualTo _type) then {
                _section = switch (true) do {
                    case (isClass(configFile >> "CfgMagazines" >> (_x select 1))): {"CfgMagazines"};
                    case (isClass(configFile >> "CfgWeapons" >> (_x select 1))): {"CfgWeapons"};
                    case (isClass(configFile >> "CfgVehicles" >> (_x select 1))): {"CfgVehicles"};
                    case (isClass(configFile >> "CfgGlasses" >> (_x select 1))): {"CfgGlasses"};
                    default {"CfgWeapons"};
                };
                _name = (getText(configFile >> _section >> (_x select 1) >> "displayName"));
                _val = (_x select 2);
                if (!(_section isEqualTo "CfgMagazines")) then {
                    if (_val > 0) then {
                        _lInv lbAdd format["[%1] - %2",_val,_name];
                        _lInv lbSetData [(lbSize _lInv)-1,(_x select 1)];
                        _lInv lbSetTooltip [lbSize(_lInv)-1,format ["%1 - %3: %2",_name,_val,(getText(missionConfigFile >> "Cation_Locker" >> "Amount"))]];
                        _icon = (getText(configFile >> _section >> (_x select 1) >> "picture"));
                        if (!(_icon isEqualTo "")) then {
                            _lInv lbSetPicture [(lbSize _lInv)-1,_icon];
                        };
                        _lInv lbSetValue [(lbSize _lInv)-1,_val];
                    };
                } else {
                    if (_val > 0) then {
                        _lInv lbAdd format["[%1] - (%3) %2",_val,_name,(_x select 3)];
                        _lInv lbSetData [(lbSize _lInv)-1,(_x select 1)];
                        _lInv lbSetTooltip [lbSize(_lInv)-1,format ["%1 - %3: %2 - %5: %3",_name,_val,(_x select 3),(getText(missionConfigFile >> "Cation_Locker" >> "Amount")),(getText(missionConfigFile >> "Cation_Locker" >> "AmmoCount"))]];
                        _icon = (getText(configFile >> _section >> (_x select 1) >> "picture"));
                        if (!(_icon isEqualTo "")) then {
                            _lInv lbSetPicture [(lbSize _lInv)-1,_icon];
                        };
                        _lInv lbSetValue [(lbSize _lInv)-1,(_x select 3)];
                    };
                };
            };
        };
    };
} forEach _data;

if((lbSize(_pInv) - 1) isEqualTo -1) then {
    _pInv lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "NoItems"))];
    _pInv lbSetData [(lbSize _pInv)-1,"leer"];
};
if((lbSize(_lInv) - 1) isEqualTo -1) then {
    _lInv lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "NoItems"))];
    _lInv lbSetData [(lbSize _lInv)-1,"leer"];
};