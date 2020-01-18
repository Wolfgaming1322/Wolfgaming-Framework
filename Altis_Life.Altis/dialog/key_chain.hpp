
class Life_key_management {
   idd = 2700;
   name = "Life_key_management";
   movingenable = 0;
   enablesimulation = 1;
   onload = "[] spawn life_fnc_keyMenu;";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenukey.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class KeyChainList : Life_RscListBox
       {
           idc = 2701;
           text = "";
           sizeex = 0.035;
           x = 0.380729166666667 * safezoneW + safezoneX;
           y = 0.334975657254138 * safezoneH + safezoneY;
           w = 0.163020833333333 * safezoneW;
           h = 0.170379746835444 * safezoneH;
       };
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
       class NearPlayers : Life_RscCombo
       {
           idc = 2702;
           x = 0.380729166666667 * safezoneW + safezoneX;
           y = 0.539839337877313 * safezoneH + safezoneY;
           w = 0.136458333333333 * safezoneW;
           h = 0.0151752677702044 * safezoneH;
       };
       class DropKey : Life_RscButtonMenu
       {
           text = "$STR_Keys_DropKey";
           onbuttonclick = "[] call life_fnc_keyDrop";
           x = 0.3921875 * safezoneW + safezoneX;
           y = 0.585603700097371 * safezoneH + safezoneY;
           w = 0.130729166666667 * safezoneW;
           h = 0.0229649464459591 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class GiveKey : Life_RscButtonMenu
       {
           idc = 2703;
           text = "$STR_Keys_GiveKey";
           onbuttonclick = "[] call life_fnc_keyGive";
           x = 0.3921875 * safezoneW + safezoneX;
           y = 0.561260954235638 * safezoneH + safezoneY;
           w = 0.130729166666667 * safezoneW;
           h = 0.0229649464459591 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
   };
};

