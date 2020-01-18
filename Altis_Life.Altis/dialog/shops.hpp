class life_weapon_shop {
   idd = 38400;
   name = "life_weapon_shop";
   movingenable = 0;
   enablesimulation = 1;
   class controlsBackground
   {
       class Life_RscTitleBackground : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.753645833333333 * safezoneW + safezoneX;
           y = 0.176241480038948 * safezoneH + safezoneY;
           w = 0.236458333333333 * safezoneW;
           h = 0.0238364167478092 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class Background : Life_RscText
       {
           colorbackground[] = {0,0,0,0.7};
           idc = 2200;
           x = 0.754166666666667 * safezoneW + safezoneX;
           y = 0.201557935735151 * safezoneH + safezoneY;
           w = 0.236458333333333 * safezoneW;
           h = 0.586173320350535 * safezoneH;
       };
       class Title : Life_RscStructuredText
       {
           idc = 1100;
           text = "Shop";
           x = 0.753645833333333 * safezoneW + safezoneX;
           y = 0.176662122687439 * safezoneH + safezoneY;
           w = 0.236458333333333 * safezoneW;
           h = 0.0248958130477118 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class Title2 : Life_RscStructuredText
       {
           idc = 1106;
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           text = "Infos zu diesem Item";
           x = 0.758072666666667 * safezoneW + safezoneX;
           y = 0.593842259006816 * safezoneH + safezoneY;
           w = 0.2289065 * safezoneW;
           h = 0.0234897760467381 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
   };
   class controls
   {
       class ButtonMags : Life_RscButtonMenu
       {
           onbuttonclick = "_this call life_fnc_weaponShopMags; _this call life_fnc_weaponShopFilter";
           idc = 38406;
           text = "Magazine";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.836979166666667 * safezoneW + safezoneX;
           y = 0.757231742940604 * safezoneH + safezoneY;
           w = 0.0781765333333334 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class itemList : Life_RscListbox
       {
           onlbselchanged = "_this call life_fnc_weaponShopSelection";
           idc = 38403;
           x = 0.758072666666667 * safezoneW + safezoneX;
           y = 0.208977604673807 * safezoneH + safezoneY;
           w = 0.2289065 * safezoneW;
           h = 0.379143135345667 * safezoneH;
           sizeex = 0.05;
       };
       class CloseButtonKey : Life_RscButtonMenu
       {
           onbuttonclick = "closeDialog 0; [] call life_fnc_playerSkins;";
           idc = 2400;
           text = "SCHLIESSEN";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.752604166666666 * safezoneW + safezoneX;
           y = 0.789894839337878 * safezoneH + safezoneY;
           w = 0.0670312 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ButtonBuySell : Life_RscButtonMenu
       {
           onbuttonclick = "[] spawn life_fnc_weaponShopBuySell; true";
           idc = 38405;
           text = "Kaufen";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.919270833333333 * safezoneW + safezoneX;
           y = 0.757231742940604 * safezoneH + safezoneY;
           w = 0.0670312 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ButtonBuySellBank : Life_RscButtonMenu
       {
           onbuttonclick = "[] spawn life_fnc_weaponShopBuySellBank; true";
           idc = 384077;
           text = "Kreditkarte";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.919270833333333 * safezoneW + safezoneX;
           y = 0.72757740993184 * safezoneH + safezoneY;
           w = 0.0670312 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class itemInfo : Life_RscStructuredText
       {
           idc = 38404;
           x = 0.758072666666667 * safezoneW + safezoneX;
           y = 0.621226874391431 * safezoneH + safezoneY;
           w = 0.2289065 * safezoneW;
           h = 0.100219084712756 * safezoneH;
       };
       class FilterList : Life_RscCombo
       {
           onlbselchanged = "_this call life_fnc_weaponShopFilter";
           idc = 38402;
           x = 0.758072666666667 * safezoneW + safezoneX;
           y = 0.72757740993184 * safezoneH + safezoneY;
           w = 0.1570315 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
       };
       class ButtonAccs : Life_RscButtonMenu
       {
           onbuttonclick = "_this call life_fnc_weaponShopAccs; _this call life_fnc_weaponShopFilter";
           idc = 38407;
           text = "Zubehör";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.758072666666667 * safezoneW + safezoneX;
           y = 0.757231742940604 * safezoneH + safezoneY;
           w = 0.0781765333333334 * safezoneW;
           h = 0.0220000000000001 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
   };
};
