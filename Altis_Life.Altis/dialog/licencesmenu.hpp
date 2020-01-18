
class License_Menu {
   idd = 3110;
   name = "License_Menu";
   movingenable = false;
   enablesimulation = true;
   onload = "[] spawn life_fnc_license_update;";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenuLizenzen.paa";
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
       class Life_LicensBox : Life_RscListNBox
       {
           x = 0.38125 * safezoneW + safezoneX;
           y = 0.335929892891918 * safezoneH + safezoneY;
           w = 0.163020833333333 * safezoneW;
           h = 0.407984420642649 * safezoneH;
           colorbackground[] = {0,0,0,0.815686274509804};
           idc = 3111;
           font = "PuristaMedium";
           sizeex = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
           columns[] = {0,0.81};
       };
   };
};

