/*
    File: fn_signVendor.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: checks vendor's informations
*/
private ["_dialog","_list","_sel","_vehicle","_unit","_price","_priceValue"];
disableSerialization;

_dialog = findDisplay 9600;
_list = _dialog displayCtrl 9609;
_checkbox = _dialog displayCtrl 9610;
_price = ctrlText 9607;

_sel = lbCurSel _list;
if ((_list lbData _sel) isEqualTo "") exitWith {hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "didNotSelectVehicle"))];};
_vehicle = _list lbData _sel;
_vehicle = life_vehicles select parseNumber(_vehicle);

_unit = _dialog getVariable ["receiver",objNull];
if (isNull _unit || isNil "_unit") exitWith {};
if (_unit isEqualTo player) exitWith {};

if (!([_price] call cat_vehicleTrade_fnc_isNumber)) exitWith {hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "notNumberFormat"))];};
_priceValue = parseNumber(_price);
if (_priceValue <= 0) exitWith {hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "moneyTooLow"))];};


if (cbChecked _checkbox) then {
    closeDialog 0;
    [_vehicle,player,_price] remoteExecCall ["cat_vehicleTrade_fnc_openBuyer",_unit];
} else {
    hint format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "notAccepted"))];
};