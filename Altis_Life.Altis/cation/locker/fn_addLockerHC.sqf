/*
    File: fn_addLockerHC.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description:
    Inserts the players locker in the database.
*/
private["_query"];
params [
    "_pid",
    "_side",
    "_sender"
]; 
if (_pid isEqualTo "" || _side isEqualTo "") exitWith {};
if (isNull _sender) exitWith {};
if (!hasInterface && !isDedicated) then {

    _query = format ["SELECT locker.civ_locker, locker.cop_locker, locker.med_locker, locker.east_locker FROM locker WHERE playerid='%1'",_pid];
    _queryResult = [_query,2] call HC_fnc_asyncCall;
    if (_queryResult isEqualType "") exitWith {[_pid,_side,_sender] call cat_locker_fnc_fetchLockerTrunkHC;};
    if !(count _queryResult isEqualTo 0) exitWith {[_pid,_side,_sender] call cat_locker_fnc_fetchLockerTrunkHC;};
    _query = format ["DELETE FROM locker WHERE playerid='%1'",_pid];
    [_query,1] call DB_fnc_asyncCall;
    _query = format["INSERT INTO locker (playerid, civ_locker, cop_locker, med_locker, east_locker) VALUES('%1', '""[]""','""[]""','""[]""','""[]""')",_pid];
    [_query,1] call HC_fnc_asyncCall;

    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "DebugMode")) isEqualTo 1) then {
        diag_log "------------- Add Locker To Database -----------";
        diag_log format ["QUERY: %1",_query];
        diag_log format ["Result: %1",_queryResult];
        diag_log "------------------------------------------------";
    };

    [_pid,_side,_sender] call cat_locker_fnc_fetchLockerTrunkHC;
};