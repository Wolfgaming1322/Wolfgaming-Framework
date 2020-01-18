#include "..\..\script_macros.hpp"
/*
    File: fn_p_updateMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Updates the player menu (Virtual Interaction Menu)
*/
private ["_inv","_lic","_licenses","_near","_near_units","_mstatus","_shrt","_side","_struct"];
disableSerialization;

if (FETCH_CONST(life_adminlevel) < 1) then {
    ctrlShow[2021,false];
};