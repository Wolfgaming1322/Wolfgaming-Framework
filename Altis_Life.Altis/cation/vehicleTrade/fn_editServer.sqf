/*
    File: fn_editServer.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Updates vehicle in database
*/
if(!isServer) exitWith {};
private ["_data","_plate","_uid","_buyerUID"];
params [
    ["_vehicle",objNull,[objNull]],
    ["_buyer",objNull,[objNull]]
];
_data = _vehicle getVariable ["dbInfo",[]];
_uid = _data select 0;
_plate = _data select 1;
_class = typeOf _vehicle;
_buyerUID = getPlayerUID _buyer;

_query = format ["UPDATE vehicles SET pid='%1' WHERE pid='%2' AND plate='%3' AND classname='%4'",_buyerUID,_uid,_plate,_class];
if ((getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "DebugMode")) isEqualTo 1) then {
    diag_log "------------- Update Vehicle PID----------------";
    diag_log format ["QUERY: %1",_query];
    diag_log "------------------------------------------------";
};
[_query,1] call DB_fnc_asyncCall;

_data = [_buyerUID,_data select 1];
_vehicle setVariable ["dbInfo",_data,true];

[_vehicle] remoteExecCall ["cat_vehicleTrade_fnc_addBuyer",owner _buyer];