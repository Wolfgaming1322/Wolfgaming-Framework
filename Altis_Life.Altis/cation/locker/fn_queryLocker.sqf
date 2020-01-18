/*
    File: fn_queryLocker.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description:
    Sends a request out to the server to check for locker information.
*/
[] spawn {
    if (!hasInterface) exitWith {};
	waitUntil {!isNull (findDisplay 46)};
    private["_uid","_side","_sender"];
    _sender = player;
    _uid = getPlayerUID _sender;
    _side = playerSide;

    if (getNumber(missionConfigFile >> "Cation_Locker" >> "HeadlessSupport") isEqualTo 0) then {
        [_uid,_side,_sender] remoteExec ["cat_locker_fnc_fetchLockerTrunk",2];
    } else {
        if (life_HC_isActive) then {
            [_uid,_side,_sender] remoteExec ["cat_locker_fnc_fetchLockerTrunkHC",HC_Life];
        } else {
            [_uid,_side,_sender] remoteExec ["cat_locker_fnc_fetchLockerTrunk",2];
        };
    };
};