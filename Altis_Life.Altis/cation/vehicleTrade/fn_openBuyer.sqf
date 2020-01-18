/*
    File: fn_openBuyer.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: opens dialog for buyer
*/
private ["_listbox","_checkbox","_color","_text","_name","_pic"];
params [
    ["_vehicle",objNull,[objNull]],
    ["_vendor",objNull,[objNull]],
    ["_price","",[""]]
];
if (isNull _vendor || !alive _vendor || isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
closeDialog 0;
if (dialog) exitWith {};
if (!createDialog "Cat_vehicleTrade_buyer") exitWith {}; //Couldn't create the menu?
disableSerialization;

_display = findDisplay 9600;
(_display displayCtrl 9601) ctrlSetText format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "treaty"))];
(_display displayCtrl 9602) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "buyer"))];
(_display displayCtrl 9603) ctrlSetText format["%1",name player];
(_display displayCtrl 9604) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "vendor"))];
(_display displayCtrl 9605) ctrlSetText format["%1",name _vendor];
(_display displayCtrl 9606) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "price"))];
(_display displayCtrl 9607) ctrlSetText _price;
(_display displayCtrl 9608) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "vehicle"))];
if ((getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "version")) > 3) then {
    _color = ((getArray(missionConfigFile >> "LifeCfgVehicles" >> (typeOf _veh) >> "textures") select (_veh getVariable "Life_VEH_color")) select 0);
} else {
    _color = [(typeOf _veh),(_veh getVariable "Life_VEH_color")] call life_fnc_vehicleColorStr;
};
if (isNil "_color") then {_color = ""};
_text = format ["(%1)",_color];
if (_text == "()") then {
    _text = "";
};
_name = getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName");
(_display displayCtrl 9609) ctrlSetText format ["%1 %3 - [%4: %2m]",_name,round(player distance _vehicle),_text,getText(missionConfigFile >> "Cation_VehicleTrade" >> "distance")];
_checkbox = _display displayCtrl 9610;
(_display displayCtrl 9611) ctrlSetText format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "accept"))];
(_display displayCtrl 9612) ctrlSetText format["%1",name _vendor];
(_display displayCtrl 9613) ctrlSetStructuredText parseText format["<t align='center' valign='middle'>%1</t>",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "sign"))];
(_display displayCtrl 9614) ctrlSetStructuredText parseText format["<t align='center' valign='middle'>%1</t>",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "abort"))];

_checkbox ctrlSetChecked false;

_display setVariable ["vehicle",_vehicle];
_display setVariable ["vendor",_vendor];
_display setVariable ["price",parseNumber(_price)];