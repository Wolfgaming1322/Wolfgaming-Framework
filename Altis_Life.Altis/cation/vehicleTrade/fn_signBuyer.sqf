/*
    File: fn_signBuyer.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: checks buyer's informations
*/
private ["_dialog","_vehicle","_owners","_index","_vendor","_uid","_price"];
disableSerialization;

_dialog = findDisplay 9600;
_checkbox = _dialog displayCtrl 9610;
_vehicle = _dialog getVariable ["vehicle",objNull];
_price = _dialog getVariable ["price",0];
_vendor = _dialog getVariable ["vendor",objNull];

if (isNull _vendor || isNil "_vendor") exitWith {};

if (_price > life_cash) exitWith {hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "noMoney"))];};

if (cbChecked _checkbox) then {
    life_cash = life_cash - _price;
    closeDialog 0;
    [_vehicle,player,_price] remoteExecCall ["cat_vehicleTrade_fnc_delVendor",_vendor];
} else {
    hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "notAccepted"))];
};