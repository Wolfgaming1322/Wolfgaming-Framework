/*
    File: fn_abortBuyer.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: sends messeges after buyer canceled treaty.
*/
private ["_vendor","_dialog"];
disableSerialization;

_dialog = findDisplay 9600;
_vendor = _dialog getVariable ["vendor",objNull];
hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "aborted"))];
[(name player)] remoteExecCall ["cat_vehicleTrade_fnc_abortVendor",_vendor];

closeDialog 0;