/////////////////////////////////////////////////////////////////
/////////// This File was Edited by GUI D3V by Shinji ///////////
/////////////////////////////////////////////////////////////////
class shops_menu {
   idd = 2400;
   name = "shops_menu";
   movingenable = 0;
   enablesimulation = 1;
   class controlsBackground
   {
       class Life_RscTitleBackground : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.303645833333333 * safezoneW + safezoneX;
           y = 0.232716650438169 * safezoneH + safezoneY;
           w = 0.330729166666667 * safezoneW;
           h = 0.0238364167478092 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class MainBackground : Life_RscText
       {
           colorbackground[] = {0, 0, 0, 0.7};
           idc = -1;
           x = 0.304166666666667 * safezoneW + safezoneX;
           y = 0.26 * safezoneH + safezoneY;
           w = 0.33125 * safezoneW;
           h = 0.382648490749757 * safezoneH;
       };
       class Life_vasTextBackground : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.309375 * safezoneW + safezoneX;
           y = 0.266105160662123 * safezoneH + safezoneY;
           w = 0.153333333333333 * safezoneW;
           h = 0.0279552093476144 * safezoneH;
       };
       class vasText : Life_RscText
       {
           idc = -1;
           text = "$STR_VS_SI";
           sizeex = 0.04;
           x = 0.309375 * safezoneW + safezoneX;
           y = 0.266105160662123 * safezoneH + safezoneY;
           w = 0.153333333333333 * safezoneW;
           h = 0.0279552093476144 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class Life_vasgTextBackground : Life_RscText
       {
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           idc = -1;
           x = 0.4734375 * safezoneW + safezoneX;
           y = 0.266105160662123 * safezoneH + safezoneY;
           w = 0.153854166666667 * safezoneW;
           h = 0.0269814995131451 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class vasgText : Life_RscText
       {
           idc = -1;
           text = "$STR_VS_PI";
           sizeex = 0.04;
           x = 0.4734375 * safezoneW + safezoneX;
           y = 0.266105160662123 * safezoneH + safezoneY;
           w = 0.153854166666667 * safezoneW;
           h = 0.0269814995131451 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
   };
   class controls
   {
       class itemList : Life_RscListBox
       {
           idc = 2401;
           text = "";
           sizeex = 0.030;
           x = 0.308854166666666 * safezoneW + safezoneX;
           y = 0.296368062317429 * safezoneH + safezoneY;
           w = 0.153854166666667 * safezoneW;
           h = 0.291752677702045 * safezoneH;
       };
       class pItemlist : Life_RscListBox
       {
           idc = 2402;
           text = "";
           sizeex = 0.030;
           x = 0.4734375 * safezoneW + safezoneX;
           y = 0.296368062317429 * safezoneH + safezoneY;
           w = 0.153854166666667 * safezoneW;
           h = 0.291752677702045 * safezoneH;
       };
       class Title : Life_RscText
       {
           colorbackground[] = {0, 0, 0, 0};
           idc = 2403;
           x = 0.303645833333333 * safezoneW + safezoneX;
           y = 0.2317429406037 * safezoneH + safezoneY;
           w = 0.33125 * safezoneW;
           h = 0.0238364167478092 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class PlayersName : Title
       {
           idc = 601;
           style = 1;
           text = "";
           x = 0.303645833333333 * safezoneW + safezoneX;
           y = 0.232716650438169 * safezoneH + safezoneY;
           w = 0.33125 * safezoneW;
           h = 0.0238364167478092 * safezoneH;
       };
       class buyEdit : Life_RscEdit
       {
           idc = 2404;
           text = "1";
           sizeex = 0.030;
           x = 0.409375 * safezoneW + safezoneX;
           y = 0.590866601752678 * safezoneH + safezoneY;
           w = 0.0535416666666666 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
       };
       class sellEdit : Life_RscEdit
       {
           idc = 2405;
           text = "1";
           sizeex = 0.030;
           x = 0.573958333333333 * safezoneW + safezoneX;
           y = 0.590866601752678 * safezoneH + safezoneY;
           w = 0.0535416666666666 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
       };
       class ButtonAddG : Life_RscButtonMenu
       {
           text = "Kaufen";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           onbuttonclick = "[] call life_fnc_virt_buy;";
           x = 0.308854166666667 * safezoneW + safezoneX;
           y = 0.590866601752678 * safezoneH + safezoneY;
           w = 0.0979166666666663 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ButtonAddGBank : Life_RscButtonMenu
       {
           text = "Kreditkarte";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           onbuttonclick = "[] call life_fnc_virt_buybank;";
           x = 0.308854166666666 * safezoneW + safezoneX;
           y = 0.615209347614411 * safezoneH + safezoneY;
           w = 0.0979166666666663 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ButtonRemoveG : Life_RscButtonMenu
       {
           text = "Verkaufen";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           onbuttonclick = "[] call life_fnc_virt_sell";
           x = 0.4734375 * safezoneW + safezoneX;
           y = 0.590866601752678 * safezoneH + safezoneY;
           w = 0.0989583333333337 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
       class ButtonClose : Life_RscButtonMenu
       {
           text = "Schliessen";
           onbuttonclick = "closeDialog 0;";
           colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
           x = 0.303645833333333 * safezoneW + safezoneX;
           y = 0.64539435248296 * safezoneH + safezoneY;
           w = 0.0989583333333337 * safezoneW;
           h = 0.0206231742940603 * safezoneH;
           class Attributes {
     			   font = "PuristaMedium";
     			   align = "center";
     		   };
       };
   };
};
