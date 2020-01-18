/*
    File: fn_upgradeLocker.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Used as a refresher for the locker inventory.   
*/
private["_old","_next","_locker_size_price","_price","_size","_action","_locker"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};

_locker = (locker getVariable ["Trunk",[[],0,0,-1]]);
_next = (_locker select 3) + 1;
_locker_size_price = (getArray(missionConfigFile >> "Cation_Locker" >> "locker_size_price"));
if (_next >= count _locker_size_price) exitWith {};

_size = _locker_size_price select _next select 0;
if (_size isEqualType "") then {
    _size = parseNumber _size;
};
_price = _locker_size_price select _next select 1;
if (_price isEqualType "") then {
    _price = parseNumber _price;
};
_old = _locker select 2;
if (_old isEqualType "") then {
    _old = parseNumber _size;
};

_action = [
    format [(getText(missionConfigFile >> "Cation_Locker" >> "UpgradeLockerMSG")),[_price] call BIS_fnc_numberText,[_size] call BIS_fnc_numberText,[_old] call BIS_fnc_numberText],
    (getText(missionConfigFile >> "Cation_Locker" >> "UpgradeLocker")),
    (getText(missionConfigFile >> "Cation_Locker" >> "Yes")),
    (getText(missionConfigFile >> "Cation_Locker" >> "No"))
] call BIS_fnc_guiMessage;

if (_action) then {
    if (_price > life_cash) exitWith { hint format[(getText(missionConfigFile >> "Cation_Locker" >> "NotEnoughCash"))]; };
    if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
        if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
    };
    life_cash = life_cash - _price;
    hint format [(getText(missionConfigFile >> "Cation_Locker" >> "UpgradeSuccess")),_price,_size];
    locker setVariable ["Trunk",[(_locker select 0),(_locker select 1),_size,_next],false];
    _locker = (locker getVariable "Trunk");
    lockerTotalWeight = _size;
    if (getNumber(missionConfigFile >> "Cation_Locker" >> "HeadlessSupport") isEqualTo 0) then {
        [_locker,(getPlayerUID player),playerSide] remoteExec ["cat_locker_fnc_updateLockerTrunk",2];
    } else {
        if (life_HC_isActive) then {
            [_locker,(getPlayerUID player),playerSide] remoteExec ["cat_locker_fnc_updateLockerTrunkHC",HC_Life];
        } else {
            [_locker,(getPlayerUID player),playerSide] remoteExec ["cat_locker_fnc_updateLockerTrunk",2];
        };
    };

    closeDialog 0;
    sleep 0.1;
    [] spawn cat_locker_fnc_openLocker;

};
