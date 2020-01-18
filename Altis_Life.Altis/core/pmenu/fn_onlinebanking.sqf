#include "..\..\script_macros.hpp"
/*
    File: fn_onlinebanking.sqf
    Author: Deathman

    Description:
    Online Banking Menu Updater
*/
private ["_near","_near_units","_mstatus"];
disableSerialization;

_near = CONTROL(9991,2022);
_mstatuskonto = CONTROL(9991,2015);
_mstatusgeld = CONTROL(9991,9995);
lbClear _near;

//Near players
_near_units = [];
{ if (player distance _x < 10) then {_near_units pushBack _x};} forEach playableUnits;
{
    if (!isNull _x && alive _x && player distance _x < 10 && !(_x isEqualTo player)) then {
        _near lbAdd format ["%1 - %2",_x getVariable ["realname",name _x], side _x];
        _near lbSetData [(lbSize _near)-1,str(_x)];
    };
} forEach _near_units;

_mstatuskonto ctrlSetStructuredText parseText format ["<t size='0.8px'>$%1</t>",[BANK] call life_fnc_numberText];
_mstatusgeld ctrlSetStructuredText parseText format ["<t size='0.8'>$%1</t>",[CASH] call life_fnc_numberText];
