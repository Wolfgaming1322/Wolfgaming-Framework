
class Life_Onlinebaning_management {
   idd = 9991;
   name = "Life_Onlinebaning_management";
   movingenable = 0;
   enablesimulation = 1;
   onload = "[]spawn life_fnc_onlinebanking;";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexOnlinebanking.paa";
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
       class moneyStatusInfoOben : Life_RscStructuredText
       {
           idc = 2015;
           sizeex = 0.020;
           colorbackground[] = {0,0,0,0};
           x = 0.38625 * safezoneW + safezoneX;
           y = 0.363193768257059 * safezoneH + safezoneY;
           w = 0.1325 * safezoneW;
           h = 0.0223953261927945 * safezoneH;
       };
       class moneyStatusInfoUnten : Life_RscStructuredText
       {
           idc = 9995;
           sizeex = 0.020;
           colorbackground[] = {0,0,0,0};
           x = 0.38625 * safezoneW + safezoneX;
           y = 0.410418695228821 * safezoneH + safezoneY;
           w = 0.1325 * safezoneW;
           h = 0.0223953261927945 * safezoneH;
       };
       class moneyEdit : Life_RscEdit
       {
           idc = 2018;
           text = "1";
           sizeex = 0.030;
           x = 0.38625 * safezoneW + safezoneX;
           y = 0.5056864654333 * safezoneH + safezoneY;
           w = 0.1325 * safezoneW;
           h = 0.0152482960077904 * safezoneH;
       };
       class NearPlayers : Life_RscCombo
       {
           idc = 2022;
           x = 0.38625 * safezoneW + safezoneX;
           y = 0.540408958130477 * safezoneH + safezoneY;
           w = 0.1325 * safezoneW;
           h = 0.0220642648490751 * safezoneH;
       };
       class moneyDrop : Life_RscButtonMenu
       {
           idc = 2001;
           text = "$STR_Global_Give";
           onbuttonclick = "[] call life_fnc_giveMoney";
           sizeex = 0.025;
           x = 0.396145833333334 * safezoneW + safezoneX;
           y = 0.575949367088607 * safezoneH + safezoneY;
           w = 0.13 * safezoneW;
           h = 0.0277507302823759 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
   };
};

