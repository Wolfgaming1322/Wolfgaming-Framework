#include "..\..\script_macros.hpp"
/*
	File: fn_license_update.sqf
	Author: Deathman
	
	Description:
	Updated and Loade you Licences + Price Display
*/
disableSerialization;

_lic = CONTROL(3110,3111);
_side = switch (playerSide) do {case west:{"cop"}; case civilian:{"civ"}; case independent:{"med"};};

	{
		private _imBesitz = (LICENSE_VALUE(configName _x,_side));
		private _lis = _lic	lnbAddRow [localize(getText(_x >> "displayName"))];
		private _illegal = if (getNumber(_x >> "illegal") isEqualTo 0) then {false} else {true};
		_lic lnbSetColor [[_lis,0], if (_illegal) then {[1,0,0,1]} else {[1,1,1,1]}];
		_lic lnbSetPicture [[_lis,1], if !(_imBesitz) then {"icons\icon_nichtimbesitz.paa"} else {"icons\icon_imbesitz.paa"}];
	} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_side] configclasses (missionconfigfile >> "Licenses"));