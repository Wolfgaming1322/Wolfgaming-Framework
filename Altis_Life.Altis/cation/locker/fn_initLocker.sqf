/*
    File: fn_initLocker.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description:
    initializes locker inventory.
*/
params [
    "_inv"
];

if (_inv isEqualTo []) then {_inv = [[],0,0,-1];};

locker = "Supply500" createVehicle [10,10,10];
locker setVariable ["Trunk",_inv,false];
lockerTotalWeight = (_inv select 2);
locker setVariable ["trunk_in_use",false,false];