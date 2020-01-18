
class Life_Inventar_management {
   idd = 9992;
   name = "Life_Inventar_management";
   movingenable = 0;
   enablesimulation = 1;
   onload = "[]spawn life_fnc_inventarmenu;";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenuInventar.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class ButtonClose : Life_RscPictureButton
       {
           text = "menus\zv4\closebutton.paa";
           tooltip = "Schliessen";
           onbuttonclick = "closeDialog 0;";
           colorbackground[] = {0, 0, 0, 0};
           x = 0.422916666666667 * safezoneW + safezoneX;
           y = 0.769230769230769 * safezoneH + safezoneY;
           w = 0.0786458333333333 * safezoneW;
           h = 0.00584225900681564 * safezoneH;
           idc = 1004;
       };
       class Player_Wight : Life_RscTitle
       {
           idc = 2009;
           style = 1;
           text = "";
           x = 0.380729166666667 * safezoneW + safezoneX;
           y = 0.320447906523856 * safezoneH + safezoneY;
           w = 0.0515625 * safezoneW;
           h = 0.0164556962025317 * safezoneH;
       };
       class itemList : Life_RscListBox
       {
           idc = 2005;
           sizeex = 0.030;
           x = 0.380729166666667 * safezoneW + safezoneX;
           y = 0.340895813047712 * safezoneH + safezoneY;
           w = 0.163020833333333 * safezoneW;
           h = 0.122590068159688 * safezoneH;
       };
       class itemEdit : Life_RscEdit
       {
           idc = 2010;
           text = "1";
           sizeex = 0.030;
           x = 0.4028125 * safezoneW + safezoneX;
           y = 0.504839337877312 * safezoneH + safezoneY;
           w = 0.0289583333333333 * safezoneW;
           h = 0.0160954235637784 * safezoneH;
       };
       class iNearPlayers : Life_RscCombo
       {
           idc = 2023;
           x = 0.380729166666667 * safezoneW + safezoneX;
           y = 0.540866601752677 * safezoneH + safezoneY;
           w = 0.102083333333334 * safezoneW;
           h = 0.0219376825705939 * safezoneH;
       };
       class DropButton : Life_RscButtonMenu
       {
           idc = 2002;
           text = "$STR_Global_Give";
           onbuttonclick = "[] call life_fnc_giveItem;";
           x = 0.392708333333333 * safezoneW + safezoneX;
           y = 0.594839337877313 * safezoneH + safezoneY;
           w = 0.13125 * safezoneW;
           h = 0.0234664070107108 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class UseButton : Life_RscButtonMenu
       {
           text = "$STR_Global_Use";
           onbuttonclick = "[] call life_fnc_useItem;";
           x = 0.392708333333333 * safezoneW + safezoneX;
           y = 0.56952288218111 * safezoneH + safezoneY;
           w = 0.13125 * safezoneW;
           h = 0.0234664070107108 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class RemoveButton : Life_RscButtonMenu
       {
           text = "$STR_Global_Remove";
           onbuttonclick = "[] call life_fnc_removeItem;";
           x = 0.392708333333333 * safezoneW + safezoneX;
           y = 0.619182083739045 * safezoneH + safezoneY;
           w = 0.13125 * safezoneW;
           h = 0.0234664070107108 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
   };
};

