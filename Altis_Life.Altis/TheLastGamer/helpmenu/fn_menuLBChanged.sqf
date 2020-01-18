#include "..\..\script_macros.hpp"
/*
	author: Risk
	description: Ändert jedes mal den Text jenachdem was man auswählt.
	returns: nothing
*/
params[
    "_menuControl",
    "_menuIndex"
];
//Fetch some information.
private _tName = _menuControl lbData _menuIndex;
hint format["%1",_tName];
private _dName = M_CONFIG(getText,"TLG_help_text",_tName,"displayName");
private _tDescrip = M_CONFIG(getText,"TLG_help_text",_tName,"description");

ctrlShow [60704,true];
ctrlShow [60708,true];
ctrlShow [60709,true];
ctrlShow [60710,true];
ctrlSetText [60704, _dName];
(CONTROL(60700,60709)) ctrlSetStructuredText parseText format["%1",_tDescrip];