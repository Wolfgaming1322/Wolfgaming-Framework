/*
    File: fn_lockerInventory.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Used as a refresher for the locker inventory.   
*/
private["_filterIndex","_display","_lInv","_pInv","_filter"];
if (isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_Locker" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
disableSerialization;

if (isNull (findDisplay 5000)) exitWith {};

_display = findDisplay 5000;
_lInv = _display displayCtrl 5002;
_pInv = _display displayCtrl 5003;
_filter = _display displayCtrl 5007;
_filterIndex = _display getVariable ["type",0];
lbClear _lInv;
lbClear _pInv;
lbClear _filter;

(_display displayCtrl 5004) ctrlSetText format[(getText(missionConfigFile >> "Cation_Locker" >> "Weight"))+ " %1/%2",((locker getVariable "Trunk") select 1),lockerTotalWeight];

_filter lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "VItems"))];
_filter lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "Weapons"))];
_filter lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "Magazines"))];
_filter lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "Items"))];
_filter lbAdd format[(getText(missionConfigFile >> "Cation_Locker" >> "Equipment"))];
_filter lbSetCurSel _filterIndex;