/*
    File: fn_addBuyer.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: adds vehicle to buyer's keychain
*/
private ["_arr","_owners","_index"];
params [
    ["_vehicle",objNull,[objNull]]
];
_owners = _vehicle getVariable "vehicle_info_owners";
_index = _owners find (getPlayerUID player);
if (_index isEqualTo -1) then  {
    _owners pushBack [(getPlayerUID player),player getVariable ["realname",name player]];
    _vehicle setVariable ["vehicle_info_owners",_owners,true];
};
if(!(_vehicle in life_vehicles)) then {
    life_vehicles pushBack _vehicle;
};
_arr = missionNamespace getVariable [format ["%1_KEYS_%2",(getPlayerUID player),playerSide],[]];
_arr pushBack _vehicle;
_arr = _arr - [objNull];
missionNamespace setVariable [format ["%1_KEYS_%2",(getPlayerUID player),playerSide],_arr];
hint format[getText(missionConfigFile >> "Cation_VehicleTrade" >> "gotVehicle"),getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")];