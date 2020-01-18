#define ctrlSelData(ctrl) (lbData[##ctrl,(lbCurSel ##ctrl)])
/*
    File: fn_lockerTakeItem.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: loads things from server    
*/
private["_count","_array","_assignedItems","_base","_bad","_number","_display","_type","_ctrl","_num","_index","_data","_old","_value","_weight","_diff"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
disableSerialization;
if (!alive player) exitWith {closeDialog 0;};

if ((lbCurSel 5002) isEqualTo -1) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NoSelection"))];};
_ctrl = ctrlSelData(5002);
if (_ctrl isEqualTo "leer") exitWith {};
_num = ctrlText 5005;
_display = findDisplay 5000;
_type = _display getVariable ["type",-1];
if (!([_num] call cat_locker_fnc_isNumber)) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))];};
_num = parseNumber(_num);
if (_num < 1) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "Under1"))];};
_data = (locker getVariable "Trunk") select 0;
_old = locker getVariable "Trunk";

switch (_type) do {
    case 0: {
        _index = [_ctrl,((locker getVariable "Trunk") select 0),-1] call cat_locker_fnc_index;        
        if (_index isEqualTo -1) exitWith {};
        _value = _data select _index select 2;
        if (_num > _value) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnough"))]};
        _num = [_ctrl,_num,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
        if (_num isEqualTo 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "InvFull"))]};
        _weight = ([_ctrl] call life_fnc_itemWeight) * _num;
        if ([true,_ctrl,_num] call life_fnc_handleInv) then {
            if (_num == _value) then {
                _data deleteAt _index;
            } else {
                _data set[_index,[_type,_ctrl,(_value - _num)]];
            };
            locker setVariable["Trunk",[_data,(_old select 1) - _weight,(_old select 2),(_old select 3)],true];
            [] call cat_locker_fnc_lockerInventory;
        } else {
            hint format[(getText(missionConfigFile >> "Cation_Locker" >> "InvFull"))];
        };
    };
    case 1: {
        _index = [_ctrl,((locker getVariable "Trunk") select 0),-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) exitWith {};        
        _value = _data select _index select 2;
        if (_num > _value) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnough"))]};
        _weight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "WeaponSlotsInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_weight isEqualTo 0) then {
            _weight = 1;
        };
        _number = 0;
        _bad = false;
        for "_i" from 1 to _num do {
            switch (getNumber(configFile >> "CfgWeapons" >> _ctrl >> "type")) do {
                case 1: {
                    if ((primaryWeapon player) isEqualTo "") then {
                        player addWeapon _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
                case 2: {
                    if ((handGunWeapon player) isEqualTo "") then {
                        player addWeapon _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
                case 4: {
                    if ((secondaryWeapon player) isEqualTo "") then {
                        player addWeapon _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
                if (_bad) exitWith {};
            };
            _number = _i;
        };
        if (_number isEqualTo 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))]};
        _weight = _weight * _number;
        if (_number == _value) then {
            _data deleteAt _index;
        } else {
            _data set[_index,[_type,_ctrl,(_value - _number)]];
        };
        locker setVariable["Trunk",[_data,(_old select 1) - _weight,(_old select 2),(_old select 3)],true];
        [] call cat_locker_fnc_lockerInventory;
    };
    case 2: {
        _ammo = lbValue[5002,lbCurSel(5002)];
        _array = [];
        {
            _array pushBack [_x select 1,_x select 2,_x select 3];
        } forEach ((locker getVariable "Trunk") select 0);
        _index = [_ctrl,_array,_ammo] call cat_locker_fnc_index;
        if (_index isEqualTo -1) exitWith {};        
        _value = _data select _index select 2;
        if (_num > _value) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnough"))]};
        _weight = round ((getNumber(configfile >> "CfgMagazines" >> _ctrl >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_weight isEqualTo 0) then {
            _weight = 1;
        };
        _number = 0;
        _bad = false;
        for "_i" from 1 to _num do {
            if (player canAdd _ctrl) then {
                player addMagazine [_ctrl,_ammo];
            } else {
                if (true) exitWith {_bad = true;};
            };
            if (_bad) exitWith {};
            _number = _i;
        };
        if (_number isEqualTo 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))]};
        _weight = _weight * _number;
        if (_number == _value) then {
            _data deleteAt _index;
        } else {
            _data set[_index,[_type,_ctrl,(_value - _number),_ammo]];
        };
        locker setVariable["Trunk",[_data,(_old select 1) - _weight,(_old select 2),(_old select 3)],true];
        [] call cat_locker_fnc_lockerInventory;
    };
    case 3: {
        _index = [_ctrl,((locker getVariable "Trunk") select 0),-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) exitWith {};        
        _value = _data select _index select 2;
        if (_num > _value) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnough"))]};
        _weight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "ItemInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_weight isEqualTo 0) then {
            _weight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "WeaponSlotsInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
            if (_weight isEqualTo 0) then {
                _weight = 1;
            };
        };
        _number = 0;
        _bad = false;
        for "_i" from 1 to _num do {
            _base = [(configfile >> "CfgWeapons" >> _ctrl),true ] call BIS_fnc_returnParents;
            if ("Binocular" in _base) then {
                if ((binocular player) isEqualTo "") then {
                    player addWeapon _ctrl;
                } else { 
                    if (player canAdd _ctrl) then {
                        player addItem _ctrl;
                    } else {
                        if (true) exitWith {_bad = true;};
                    };
                };
            } else {
                _assignedItems = assignedItems player;
                _count = count _assignedItems;
                player linkItem _ctrl;
                if ((count _assignedItems) isEqualTo (count (assignedItems player))) then {
                    {
                        player linkItem _x;
                    } forEach _assignedItems;
                    if (player canAdd _ctrl) then {
                        player addItem _ctrl;
                    } else {
                        if (true) exitWith {_bad = true;};
                    };
                };
            };
            if (_bad) exitWith {};
            _number = _i;
        };
        if (_number isEqualTo 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))]};
        _weight = _weight * _number;
        if (_number == _value) then {
            _data deleteAt _index;
        } else {
            _data set[_index,[_type,_ctrl,(_value - _number)]];
        };
        locker setVariable["Trunk",[_data,(_old select 1) - _weight,(_old select 2),(_old select 3)],true];
        [] call cat_locker_fnc_lockerInventory;
    };
    case 4: {
        _index = [_ctrl,((locker getVariable "Trunk") select 0),-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) exitWith {};        
        _value = _data select _index select 2;
        if (_num > _value) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnough"))]};
        _weight = switch (true) do {
            case (isClass(configFile >> "CfgWeapons" >> _ctrl)): {
                round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "ItemInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
            };
            case (isClass(configFile >> "CfgGlasses" >> _ctrl)): {
                round ((getNumber(configfile >> "CfgGlasses" >> _ctrl >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
            };
            case (isClass(configFile >> "CfgVehicles" >> _ctrl)): {
                round ((getNumber(configfile >> "CfgVehicles" >> _ctrl >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
            };
        };
        if (_weight isEqualTo 0) then {
            _weight = 1;
        };
        _number = 0;
        _bad = false;
        for "_i" from 1 to _num do {
            _base = [(configfile >> "CfgWeapons" >> _ctrl),true ] call BIS_fnc_returnParents;
            if (isClass(configfile >> "CfgVehicles" >> _ctrl)) then {
                if ((backpack player) isEqualTo "") then {
                    player addBackpack _ctrl;
                } else {
                    if (player canAdd _ctrl) then {
                        player addItem _ctrl;
                    } else {
                        if (true) exitWith {_bad = true;};
                    };
                };
            };
            if (isClass(configfile >> "CfgWeapons" >> _ctrl)) then {
                if (("Vest_Camo_Base" in _base) || ("Vest_NoCamo_Base" in _base)) then {
                    if ((vest player) isEqualTo "") then {
                        player addVest _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
                if ("Uniform_Base" in _base) then {
                    if ((uniform player) isEqualTo "") then {
                        player addUniform _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
                if (("H_HelmetB" in _base) || ("HelmetBase" in _base)) then {
                    if ((headgear player) isEqualTo "") then {
                        player addHeadgear _ctrl;
                    } else {
                        if (player canAdd _ctrl) then {
                            player addItem _ctrl;
                        } else {
                            if (true) exitWith {_bad = true;};
                        };
                    };
                };
            };
            if (isClass(configfile >> "CfgGlasses" >> _ctrl)) then {
                if ((goggles player) isEqualTo "") then {
                    player addGoggles _ctrl;
                } else {
                    if (player canAdd _ctrl) then {
                        player addItem _ctrl;
                    } else {
                        if (true) exitWith {_bad = true;};
                    };
                };
            };
            if (_bad) exitWith {};
            _number = _i;
        };
        if (_number isEqualTo 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))]};
        _weight = _weight * _number;
        if (_number == _value) then {
            _data deleteAt _index;
        } else {
            _data set[_index,[_type,_ctrl,(_value - _number)]];
        };
        locker setVariable["Trunk",[_data,(_old select 1) - _weight,(_old select 2),(_old select 3)],true];
        [] call cat_locker_fnc_lockerInventory;
    };
};
[0,_type] call cat_locker_fnc_lockerFilter;