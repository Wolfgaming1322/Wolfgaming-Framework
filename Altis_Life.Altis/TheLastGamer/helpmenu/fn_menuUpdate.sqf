#include "..\..\script_macros.hpp"
/*
	author: Risk
	description: opens some nasty menu
	returns: nothing
*/
disableSerialization;

//Setup control vars.
private _item_list = CONTROL(60700,67001);
ctrlShow [60704,false];
ctrlShow [60708,false];
ctrlShow [60709,false];

//Purge list & sorts it.
lbClear _item_list;
if(LIFE_SETTINGS(getNumber,"isSorting") isEqualTo 1) then{
    lbSort _item_list;
};
if (!isClass(missionConfigFile >> "TLG_help_Menu" >> "TLG_help")) exitWith {closeDialog 0; hint localize "STR_NOTF_ConfigDoesNotExist";};
private _textItems = M_CONFIG(getArray,"TLG_help_Menu","TLG_help","texts");

{
    private _displayName = M_CONFIG(getText,"TLG_help_text",_x,"displayName");
		_item_list lbAdd format ["%1",_displayName];
        _item_list lbSetData [(lbSize _item_list)-1,_x];
        _icon = M_CONFIG(getText,"TLG_help_text",_x,"icon");
        if (!(_icon isEqualTo "")) then {
            _item_list lbSetPicture [(lbSize _item_list)-1,_icon];
        };        
} forEach _textItems;