#include "..\..\script_macros.hpp"
/*
 File: fn_jail.sqf
 Author: Bryan "Tonic" Boardwine

 Description:
 Starts the initial process of jailing.
*/
params [
 ["_unit",objNull,[objNull]],
 ["_bad",false,[false]],
 ["_time",15,[0]]
];

if (isNull _unit) exitWith {}; //Dafuq?
if !(_unit isEqualTo player) exitWith {}; //Dafuq?
if (life_is_arrested) exitWith {}; //Dafuq i'm already arrested
if !((_unit getVariable ["JailTime",0]) isEqualTo 0) then {_time = (_unit getVariable ["JailTime",0])};
private _illegalItems = LIFE_SETTINGS(getArray,"jail_seize_vItems");

player setVariable ["restrained",false,true];
player setVariable ["Escorting",false,true];
player setVariable ["transporting",false,true];

titleText[localize "STR_Jail_Warn","PLAIN"];
player setPos (getMarkerPos "jail_marker");

if (_bad) then {
 waitUntil {alive player};
 sleep 1;
};

//Check to make sure they goto check
if (player distance (getMarkerPos "jail_marker") > 40) then {
 player setPos (getMarkerPos "jail_marker");
};

life_is_arrested = true;

if (LIFE_SETTINGS(getNumber,"jail_seize_inventory") isEqualTo 1) then {
 [] spawn life_fnc_seizeClient;
} else {
 removeAllWeapons player;
 {player removeMagazine _x} forEach (magazines player);
};

if (life_HC_isActive) then {
 [player,_bad,_time] remoteExecCall ["HC_fnc_jailSys",HC_Life];
} else {
 [player,_bad,_time] remoteExecCall ["life_fnc_jailSys",RSERV];
};

[5] call SOCK_fnc_updatePartial;
