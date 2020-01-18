/*
    File: fn_init.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Initializes vehicle trade system
*/
[] spawn {
    private ["_exit","_keyDown","_shift","_ctrlKey","_alt"];
    waitUntil {!(isNull (findDisplay 46))};
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        _keyDown = _this select 1;
        _shift = switch (_this select 2) do { case true: {1}; case false: {0}; default {0};};
        _ctrlKey = switch (_this select 3) do { case true: {1}; case false: {0}; default {0};};
        _alt = switch (_this select 4) do { case true: {1}; case false: {0}; default {0};};
        if (!(_keyDown isEqualTo (getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "key")))) exitWith {false};
        if (!(_shift isEqualTo (getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "shift")))) exitWith {false};
        if (!(_ctrlKey isEqualTo (getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "ctrl")))) exitWith {false};
        if (!(_alt isEqualTo (getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "alt")))) exitWith {false};
        if (!(isPlayer cursorObject)) exitWith {false};
        if (!(playerSide isEqualTo (side cursorObject))) exitWith {false};
        [cursorObject] call cat_vehicleTrade_fnc_openVendor;
        true;
    }];
};