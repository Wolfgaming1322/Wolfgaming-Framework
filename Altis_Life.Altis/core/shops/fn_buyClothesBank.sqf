if(getNumber(missionConfigFile >> "Life_Settings" >> "colthing_buy_bank") isEqualTo 0) then {
  hint "Diese Funktion muss von einem Admin Freigeschalten werden";
} else {
  #include "..\..\script_macros.hpp"
  /*
  File: fn_buyClothesBank.sqf
  Author: Bryan "Tonic" Boardwine edit by Deathman

  Description:
  Buys the current set of clothes and closes out of the shop interface.
  */
  private ["_price"];
  if ((lbCurSel 3101) isEqualTo -1) exitWith {titleText[localize "STR_Shop_NoClothes","PLAIN"];};

    _price = 0;
    {
      if (!(_x isEqualTo -1)) then {
        _price = _price + _x;
      };
    } forEach life_clothing_purchase;

    if (_price > BANK) exitWith {titleText[localize "STR_Shop_NotEnoughClothes","PLAIN"];};
      BANK = BANK - _price;
      [1] call SOCK_fnc_updatePartial;

      life_clothesPurchased = true;
      [] call life_fnc_playerSkins;
      closeDialog 0;
};
