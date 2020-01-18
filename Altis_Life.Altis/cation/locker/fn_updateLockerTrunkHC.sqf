/*
    File: fn_updateLockerTrunk.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description:
    Updates locker inventory in database.
*/
private["_query","_update"];
params [
    "_inv",
    "_pid",
    "_side"
]; 

//Stop bad data being passed.
if (_pid isEqualTo "" || _side isEqualTo "") exitWith {};
if (!hasInterface && !isDedicated) then {

    if (_inv isEqualTo "") then {_inv = [[],0,0,-1];};

    _inv = [_inv] call HC_fnc_mresArray;
    _query = switch (_side) do {
        case civilian: { format["UPDATE locker SET civ_locker='%1' WHERE playerid='%2'",_inv,_pid]; };
        case west: { format["UPDATE locker SET cop_locker='%1' WHERE playerid='%2'",_inv,_pid]; };
        case independent: { format["UPDATE locker SET med_locker='%1' WHERE playerid='%2'",_inv,_pid]; };
        case east: { format["UPDATE locker SET east_locker='%1' WHERE playerid='%2'",_inv,_pid]; };
    };
    _update = [_query,1] call HC_fnc_mresArray;

    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "DebugMode")) isEqualTo 1) then {
        diag_log "------------- Update Locker To Database --------";
        diag_log format ["QUERY: %1",_query];
        diag_log format ["Update: %1",_update];
        diag_log "------------------------------------------------";
        diag_log format ["Inventory: %1",_inv];
        diag_log "------------------------------------------------";
    };
};