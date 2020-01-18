/*
    File: fn_openVendor.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: opens dialog for vendor
*/
private ["_uid","_pricebox","_listbox","_checkbox","_veh","_color","_text","_name","_pic","_vInfo"];
_receiver = param [0,objNull,[objNull]];
if (isNull _receiver || !alive _receiver || isNull player || !alive player || (player getVariable ["restrained",false]) || (player getVariable ["Escorting",false]) || life_istazed || life_action_inUse) exitWith {closeDialog 0;}; //If null / dead exit menu
if ((getNumber(missionConfigFile >> "Cation_VehicleTrade" >> "version")) > 4) then {
    if ((player getVariable ["playerSurrender",false]) || life_isknocked) exitWith {closeDialog 0;};
};
if (!(cursorObject isEqualTo _receiver)) exitWith {};
closeDialog 0;
if (dialog) exitWith {};
if (!createDialog "Cat_vehicleTrade_vendor") exitWith {}; //Couldn't create the menu?
disableSerialization;

_display = findDisplay 9600;
(_display displayCtrl 9601) ctrlSetText format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "treaty"))];
(_display displayCtrl 9602) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "buyer"))];
(_display displayCtrl 9603) ctrlSetText format["%1",name _receiver];
(_display displayCtrl 9604) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "vendor"))];
(_display displayCtrl 9605) ctrlSetText format["%1",name player];
(_display displayCtrl 9606) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "price"))];
_pricebox = _display displayCtrl 9607;
(_display displayCtrl 9608) ctrlSetText format["%1:",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "vehicle"))];
_listbox = _display displayCtrl 9609;
_checkbox = _display displayCtrl 9610;
(_display displayCtrl 9611) ctrlSetText format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "accept"))];
(_display displayCtrl 9612) ctrlSetStructuredText parseText format["<t align='center' valign='middle'>%1</t>",(getText(missionConfigFile >> "Cation_VehicleTrade" >> "sign"))];

lbClear _listbox;
for "_i" from 0 to (count life_vehicles) do {
    _veh = life_vehicles select _i;
    if (!isNull _veh && alive _veh && {_veh isKindOf "LandVehicle" || _veh isKindOf "Ship" || _veh isKindOf "Air"}) then {
        _vInfo = _veh getVariable ["dbInfo",[]];
        if (count _vInfo > 0) then {
            _uid = _vInfo select 0;
        };
        if (_uid isEqualTo (getPlayerUID player)) then {
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

            _name = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "displayName");
            _pic = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "picture");
            _listbox lbAdd format ["%1 %3 - [%4: %2m]",_name,round(player distance _veh),_text,getText(missionConfigFile >> "Cation_VehicleTrade" >> "distance")];
            if (_pic != "pictureStaticObject") then {
                _listbox lbSetPicture [(lbSize _listbox)-1,_pic];
            };
            _listbox lbSetData [(lbSize _listbox)-1,str(_i)];
        };
    };
};
if (((lbSize _listbox)-1) isEqualTo -1) then {
    _listbox lbAdd format[(getText(missionConfigFile >> "Cation_VehicleTrade" >> "noVehOwned"))];
    _listbox lbSetData [(lbSize _listbox)-1,""];
};
_listbox lbSetCurSel 0;

_checkbox ctrlSetChecked false;

_display setVariable ["receiver",_receiver];