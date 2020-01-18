/*
    File: fn_fetchLockerTrunkHC.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description:
    Fetches locker inventory from database.
*/
private["_query","_queryResult","_inv"];
params [
    "_pid",
    "_side",
    "_sender"
];

//Stop bad data being passed.
if (_pid isEqualTo "" || _side isEqualTo "") exitWith {};
if (!hasInterface && !isDedicated) then {

    _query = switch (_side) do {
        case civilian: { format["SELECT locker.civ_locker FROM locker WHERE playerid='%1'",_pid]; };
        case west: { format["SELECT locker.cop_locker FROM locker WHERE playerid='%1'",_pid]; };
        case independent: { format["SELECT locker.med_locker FROM locker WHERE playerid='%1'",_pid]; };
        case east: { format["SELECT locker.east_locker FROM locker WHERE playerid='%1'",_pid]; };
    };
    _queryResult = [_query,2] call HC_fnc_asyncCall;

    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "DebugMode")) isEqualTo 1) then {
        diag_log "------------- Fetch Locker From Database -------";
        diag_log format ["QUERY: %1",_query];
        diag_log format ["Result: %1",_queryResult];
        diag_log "------------------------------------------------";
    };

    if (_queryResult isEqualType "") exitWith {
        [_pid,_side,_sender] call cat_locker_fnc_addLockerHC;
    };

    if (count _queryResult isEqualTo 0) exitWith {
        [_pid,_side,_sender] call cat_locker_fnc_addLockerHC;
    };

    _inv = [_queryResult select 0] call HC_fnc_mresToArray;
    if (_inv isEqualType "") then {_inv = call compile format["%1", _inv];};

    if ((getNumber(missionConfigFile >> "Cation_Locker" >> "DebugMode")) isEqualTo 1) then {
        diag_log format ["Inventory: %1",_inv];
        diag_log "------------------------------------------------";
    };

    [_inv] remoteExec ["cat_locker_fnc_initLocker",_sender];
};