#define ctrlSelData(ctrl) (lbData[##ctrl,(lbCurSel ##ctrl)])
/*
    File: fn_lockerStoreItem.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: stores things into locker    
*/
private["_max","_array","_details","_itemOnIndex","_count","_magazinesAmmo","_ammo","_dataArray","_display","_type","_ctrl","_num","_itemWeight","_locker_data","_inv","_index","_val"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
disableSerialization;

_ctrl = ctrlSelData(5003);
if (_ctrl isEqualTo "leer") exitWith {};
if (_ctrl isEqualTo "") exitWith {};
_num = ctrlText 5006;
_display = findDisplay 5000;
_type = _display getVariable ["type",-1];
if (!([_num] call cat_locker_fnc_isNumber)) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "WrongNumFormat"))];};
_num = parseNumber(_num);
_max = lbValue [5003,(lbCurSel 5003)];
if (_num > _max) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};
if (_num < 1) exitWith {hint format[(getText(missionConfigFile >> "Cation_Locker" >> "Under1"))];};
_locker_data = locker getVariable ["Trunk",[[],0,0,-1]];
_inv = _locker_data select 0;
_itemWeight = 0;

switch (_type) do {
    case 0: { 
        _itemWeight = ([_ctrl] call life_fnc_itemWeight);
        if (_itemWeight isEqualTo 0) then {
            _itemWeight = 1;
        };
        _itemWeight = _itemWeight * _num;

        if ((((locker getVariable "Trunk") select 1) + _itemWeight) > lockerTotalWeight) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};

        if (!([false,_ctrl,_num] call life_fnc_handleInv)) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "CouldNotRemoveItemsToPutInVeh"))];};
        _index = [_ctrl,_inv,-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) then {
            _inv pushBack [_type,_ctrl,_num];
        } else {
            _val = _inv select _index select 2;
            _inv set[_index,[_type,_ctrl,(_val + _num)]];
        };
    };
    case 1: {
        _itemWeight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "WeaponSlotsInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_itemWeight isEqualTo 0) then {
            _itemWeight = 1;
        };
        _itemWeight = _itemWeight * _num;

        if ((((locker getVariable "Trunk") select 1) + _itemWeight) > lockerTotalWeight) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};

        for "_i" from 0 to (_num -1) do {
            [_ctrl,false] call life_fnc_handleItem;
        };
        _index = [_ctrl,_inv,-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) then {
            _inv pushBack [_type,_ctrl,_num];
        } else {
            _val = _inv select _index select 2;
            _inv set[_index,[_type,_ctrl,(_val + _num)]];
        };
    };
    case 2: {
        _dataArray = _ctrl splitString ",";
        _ctrl = (_dataArray select 0);
        _ammo = parseNumber (_dataArray select 1);
        _itemWeight = round ((getNumber(configfile >> "CfgMagazines" >> _ctrl >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_itemWeight isEqualTo 0) then {
            _itemWeight = 1;
        };
        _itemWeight = _itemWeight * _num;

        if ((((locker getVariable "Trunk") select 1) + _itemWeight) > lockerTotalWeight) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};

        for "_i" from 0 to (_num -1) do {
            _magazinesAmmo = magazinesAmmo player;
            _count = (count _magazinesAmmo) - 1;
            _index = -1;
            for "_i" from 0 to _count do {
                _itemOnIndex = (_magazinesAmmo select _i); 
                if ((_ctrl in _itemOnIndex) && (_index isEqualTo -1)) then {
                    if (_ammo isEqualTo (_itemOnIndex select 1)) then {
                        _index = _i;
                    };
                };
            };
            if (!(_index isEqualTo -1)) then {
                _magazinesAmmo deleteAt _index;
            };
            { player removeMagazine _x } forEach magazines player;
            { player addMagazine [(_x select 0),(_x select 1)] } forEach _magazinesAmmo;
        };
        _array = [];
        {
            _array pushBack [_x select 1,_x select 2,_x select 3];
        } forEach _inv;
        _index = [_ctrl,_array,_ammo] call cat_locker_fnc_index;
        if (_index isEqualTo -1) then {
            _inv pushBack [_type,_ctrl,_num,_ammo];
        } else {
            _val = _inv select _index select 2;
            _inv set[_index,[_type,_ctrl,(_val + _num),_ammo]];
        };
    };
    case 3: {
        _itemWeight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "ItemInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
        if (_itemWeight isEqualTo 0) then {
            _itemWeight = round ((getNumber(configfile >> "CfgWeapons" >> _ctrl >> "WeaponSlotsInfo" >> "mass")) * (getNumber(missionConfigFile >> "Cation_Locker" >> "weightMultiplier")));
            if (_itemWeight isEqualTo 0) then {
                _itemWeight = 1;
            };
        };
        _itemWeight = _itemWeight * _num;

        if ((((locker getVariable "Trunk") select 1) + _itemWeight) > lockerTotalWeight) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};

        for "_i" from 0 to (_num -1) do {
            _details = [_ctrl] call life_fnc_fetchCfgDetails;
            switch (_details select 6) do {
                case "CfgWeapons": {
                    if ((_details select 4) in [1,2,4,5,4096]) then {
                        if ((_details select 4) isEqualTo 4096) then {
                            if ((_details select 5) isEqualTo -1) then {
                                switch (true) do {
                                    case (_ctrl in (uniformItems player)): {[_ctrl,false] call life_fnc_handleItem;};
                                    case (_ctrl in (vestItems player)) : {[_ctrl,false] call life_fnc_handleItem;};
                                    case (_ctrl in (backpackItems player)) : {[_ctrl,false] call life_fnc_handleItem;};
                                    default {player removeWeapon _ctrl;};
                                };
                            } else {
                                [_ctrl,false] call life_fnc_handleItem;
                            };
                        } else {
                            [_ctrl,false] call life_fnc_handleItem;
                        };
                    } else {
                        [_ctrl,false] call life_fnc_handleItem;
                    };
                };
                default {
                    [_ctrl,false] call life_fnc_handleItem;
                };
            };
        };
        _index = [_ctrl,_inv,-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) then {
            _inv pushBack [_type,_ctrl,_num];
        } else {
            _val = _inv select _index select 2;
            _inv set[_index,[_type,_ctrl,(_val + _num)]];
        };
    };
    case 4: {
        _itemWeight = switch (true) do {
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
        if (_itemWeight isEqualTo 0) then {
            _itemWeight = 1;
        };
        _itemWeight = _itemWeight * _num;

        if ((((locker getVariable "Trunk") select 1) + _itemWeight) > lockerTotalWeight) exitWith {_itemWeight = 0; hint format[(getText(missionConfigFile >> "Cation_Locker" >> "VehicleFullOrInsufCap"))];};

        for "_i" from 0 to (_num -1) do {
            [_ctrl,false] call life_fnc_handleItem;
        };
        _index = [_ctrl,_inv,-1] call cat_locker_fnc_index;
        if (_index isEqualTo -1) then {
            _inv pushBack [_type,_ctrl,_num];
        } else {
            _val = _inv select _index select 2;
            _inv set[_index,[_type,_ctrl,_val + _num]];
        };
    };
};

locker setVariable["Trunk",[_inv,((_locker_data select 1) + _itemWeight),(_locker_data select 2),(_locker_data select 3)],false];
[] call cat_locker_fnc_lockerInventory;
[0,_type] call cat_locker_fnc_lockerFilter;