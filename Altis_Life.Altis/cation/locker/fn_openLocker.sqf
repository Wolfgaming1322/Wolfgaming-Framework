/*
    File: fn_openLocker.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: opens locker    
*/
private ["_display","_inv","_locker","_next","_locker_size_price"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
if (dialog) exitWith {};
locker setVariable["trunk_in_use",true,true];
if (!createDialog "LockerMenu") exitWith {}; //Couldn't create the menu?
disableSerialization;

_display = findDisplay 5000;
(_display displayCtrl 5001) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Locker"))];
(_display displayCtrl 5009) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "LockerInventory"))];
(_display displayCtrl 5010) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "PlayerInventory"))];
(_display displayCtrl 5011) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Take"))];
(_display displayCtrl 5012) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Store"))];
(_display displayCtrl 5013) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Close"))];
(_display displayCtrl 5008) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Upgrade"))];
(_display displayCtrl 5004) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Weight"))+ " %1/%2",((locker getVariable "Trunk") select 1),lockerTotalWeight];

_locker = (locker getVariable ["Trunk",[[],0,0,-1]]);
_next = (_locker select 3) + 1;
_locker_size_price = (getArray(missionConfigFile >> "Cation_Locker" >> "locker_size_price"));
if (_next >= count _locker_size_price) then {
    ctrlShow [5008,false];
};
_display setVariable ["type",0];
hint format[(getText(missionConfigFile >> "Cation_Locker" >> "Warning"))];

[] call cat_locker_fnc_lockerInventory;

locker spawn {
    waitUntil {isNull (findDisplay 5000)};
    [3] call SOCK_fnc_updatePartial;
    _this setVariable["trunk_in_use",false,false];
    _inv = locker getVariable ["Trunk",[[],0,0,-1]];
    [_inv,(getPlayerUID player),playerSide] remoteExecCall ["cat_locker_fnc_updateLockerTrunk",2];
};