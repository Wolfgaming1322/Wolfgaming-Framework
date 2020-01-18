class Life_Clothing {
   idd = 3100;
   name = "Life_Clothing";
   movingenable = 1;
   enablesimulation = 1;
   class controlsBackground
   {
       class Life_RscTitleBackground : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.0260416666666667 * safezoneW + safezoneX;
           y = 0.11489776046738 * safezoneH + safezoneY;
           w = 0.169791666666667 * safezoneW;
           h = 0.0238364167478092 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class MainBackground : Life_RscText
       {
           colorbackground[] = {0.1,0.1,0.1,0.5};
           idc = -1;
           x = 0.025625 * safezoneW + safezoneX;
           y = 0.1414 * safezoneH + safezoneY;
           w = 0.170156 * safezoneW;
           h = 0.462 * safezoneH;
       };
       class RedHighlightLeftSelection : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.025625 * safezoneW + safezoneX;
           y = 0.1414 * safezoneH + safezoneY;
           w = 0.004125 * safezoneW;
           h = 0.462 * safezoneH;
       };
       class MainBackground2 : Life_RscText
       {
           colorbackground[] = {0,0,0,0.698039215686274};
           idc = -1;
           x = 0.025625 * safezoneW + safezoneX;
           y = 0.6122 * safezoneH + safezoneY;
           w = 0.170156 * safezoneW;
           h = 0.033 * safezoneH;
       };
       class RedHighlightLeftSelection2 : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.025625 * safezoneW + safezoneX;
           y = 0.6122 * safezoneH + safezoneY;
           w = 0.004125 * safezoneW;
           h = 0.033 * safezoneH;
       };
       class MainBackground3 : Life_RscText
       {
           colorbackground[] = {0,0,0,0.698039215686274};
           idc = -1;
           x = 0.025629 * safezoneW + safezoneX;
           y = 0.654 * safezoneH + safezoneY;
           w = 0.169270833333333 * safezoneW;
           h = 0.087966893865628 * safezoneH;
       };
       class RedHighlightLeftSelection3 : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.025625 * safezoneW + safezoneX;
           y = 0.654 * safezoneH + safezoneY;
           w = 0.004125 * safezoneW;
           h = 0.087966893865628 * safezoneH;
       };
   };
   class controls
   {
       class Title : Life_RscTitle
       {
           colorbackground[] = {0, 0, 0, 0};
           idc = 3103;
           text = "";
           x = 0.0265625 * safezoneW + safezoneX;
           y = 0.11587147030185 * safezoneH + safezoneY;
           w = 0.169270833333333 * safezoneW;
           h = 0.0223182083739046 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ClothingList : Life_RscListBox
       {
           idc = 3101;
           text = "";
           sizeex = 0.035;
           onlbselchanged = "[_this] call life_fnc_changeClothes;";
           x = 0.0318586 * safezoneW + safezoneX;
           y = 0.1458 * safezoneH + safezoneY;
           w = 0.161891 * safezoneW;
           h = 0.4532 * safezoneH;
       };
       class PriceTag : Life_RscStructuredText
       {
           idc = 3102;
           sizeex = 0.035;
           x = 0.0318586 * safezoneW + safezoneX;
           y = 0.714263875365141 * safezoneH + safezoneY;
           w = 0.0794062 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
       };
       class TotalPrice : Life_RscStructuredText
       {
           idc = 3106;
           sizeex = 0.035;
           x = 0.11453 * safezoneW + safezoneX;
           y = 0.714263875365141 * safezoneH + safezoneY;
           w = 0.0794062 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
       };
       class FilterList : Life_RscCombo
       {
           idc = 3105;
           colorbackground[] = {0,0,0,0.7};
           onlbselchanged = "_this call life_fnc_clothingFilter";
           x = 0.0307291666666667 * safezoneW + safezoneX;
           y = 0.617332035053554 * safezoneH + safezoneY;
           w = 0.162411833333333 * safezoneW;
           h = 0.0223953261927945 * safezoneH;
       };
       class CloseButtonKey : Life_RscButtonMenu
       {
           text = "$STR_Global_Close";
           onbuttonclick = "closeDialog 0; [] call life_fnc_playerSkins;";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.0318586 * safezoneW + safezoneX;
           y = 0.68663758519961 * safezoneH + safezoneY;
           w = 0.1587664 * safezoneW;
           h = 0.0242 * safezoneH;
           idc = -1;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class BuyButtonColthing : Life_RscButtonMenu
       {
           text = "$STR_Global_Buy";
           onbuttonclick = "[] call life_fnc_buyClothes;";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.0318123 * safezoneW + safezoneX;
           y = 0.6584 * safezoneH + safezoneY;
           w = 0.0794062 * safezoneW;
           h = 0.0242 * safezoneH;
           idc = -1;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class BuyButtonColthingBank : Life_RscButtonMenu
       {
           text = "$STR_Global_Buy_Bank";
           onbuttonclick = "[] call life_fnc_buyClothesBank;";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.11453 * safezoneW + safezoneX;
           y = 0.6584 * safezoneH + safezoneY;
           w = 0.0766158333333333 * safezoneW;
           h = 0.0242 * safezoneH;
           idc = -1;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class viewAngle : life_RscXSliderH
       {
           color[] = {1, 1, 1, 0.45};
           coloractive[] = {1, 1, 1, 0.65};
           idc = 3107;
           text = "";
           onsliderposchanged = "[4,_this select 1] call life_fnc_s_onSliderChange;";
           tooltip = "";
           x = 0.25 * safezoneW + safezoneX;
           y = 0.93 * safezoneH + safezoneY;
           w = 0.5 * safezoneW;
           h = 0.02 * safezoneH;
       };
   };
};
