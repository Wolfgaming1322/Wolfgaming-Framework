/*
    File: fn_delVendor.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: removes vehicle from vendor
*/
private ["_owners"];
params [
    ["_vehicle",objNull,[objNull]],
    ["_buyer",objNull,[objNull]],
    ["_price",0,[0]]
];
_owners = _vehicle getVariable "vehicle_info_owners";

_index = _owners find [(getPlayerUID player),player getVariable ["realname",name player]];
life_vehicles = life_vehicles - [_vehicle];
_owners deleteAt _index;
_vehicle setVariable ["vehicle_info_owners",_owners,true];

life_cash = life_cash + _price;

hint format[getText(missionConfigFile >> "Cation_VehicleTrade" >> "soldVehicle"),getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")];

[_vehicle,_buyer] remoteExecCall ["cat_vehicleTrade_fnc_editServer",2];