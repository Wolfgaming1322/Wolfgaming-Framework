class Cat_vehicleTrade_vendor {
   idd = 9600;
   name = "Cat_vehicleTrade_vendor";
   movingenable = 0;
   enablesimulation = 1;
   class controlsBackground
   {
       class background : Life_RscPicture
       {
           shadow = 0;
           type = 0;
           style = 48;
           sizeex = 0.023;
           font = "robotocondensed";
           text = "cation\vehicleTrade\treaty.paa";
           colorbackground[] = {};
           colortext[] = {};
           x = 0.296802325581395 * safezoneW + safezoneX;
           y = 0.0363108206245461 * safezoneH + safezoneY;
           w = 0.400872093023256 * safezoneW;
           h = 0.866376180101671 * safezoneH;
           tooltipcolortext[] = {1,1,1,1};
           tooltipcolorbox[] = {1,1,1,1};
           tooltipcolorshade[] = {0,0,0,0.65};
           idc = -1;
       };
   };
   class controls
   {
       class priceEdit : Life_RscEdit
       {
           idc = 9607;
           x = 0.489321763799384 * safezoneW + safezoneX;
           y = 0.415003631082063 * safezoneH + safezoneY;
           w = 0.0929456780610811 * safezoneW;
           h = 0.04 * safezoneH;
           text = "0";
           colortext[] = {0,0,0,1};
           colorbackground[] = {1,1,1,0};
       };
       class vendor : Life_RscText
       {
           x = 0.383139534883721 * safezoneW + safezoneX;
           y = 0.349027615334634 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.108430232558139 * safezoneW;
           idc = 9604;
           colortext[] = {0,0,0,1};
       };
       class vehicle : Life_RscText
       {
           x = 0.386337209302326 * safezoneW + safezoneX;
           y = 0.506989240530521 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.122364983188568 * safezoneW;
           idc = 9608;
           colortext[] = {0,0,0,1};
       };
       class buyer : Life_RscText
       {
           x = 0.384011627906977 * safezoneW + safezoneX;
           y = 0.286219451133281 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.103488372093023 * safezoneW;
           idc = 9602;
           colortext[] = {0,0,0,1};
       };
       class price : Life_RscText
       {
           x = 0.377906976744186 * safezoneW + safezoneX;
           y = 0.422992011619463 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.108430232558139 * safezoneW;
           idc = 9606;
           colortext[] = {0,0,0,1};
       };
       class sign : Life_RscButtonMenu
       {
           text = "";
           onbuttonclick = "[] call cat_vehicleTrade_fnc_signVendor";
           x = 0.538372093023255 * safezoneW + safezoneX;
           y = 0.759230210602759 * safezoneH + safezoneY;
           w = 0.0671511627906985 * safezoneW;
           h = 0.0399999999999999 * safezoneH;
           idc = 9612;
           colordisabled[] = {0,0,0,1};
           color[] = {0,0,0,1};
           colortext[] = {0,0,0,1};
           font = "LucidaConsoleB";
           style = 12;
           colorbackground[] = {1,1,1,0.1};
       };
       class treaty : Life_RscTitle
       {
           idc = 9601;
           x = 0.393023255813953 * safezoneW + safezoneX;
           y = 0.152868554829339 * safezoneH + safezoneY;
           w = 0.200872093023256 * safezoneW;
           h = 0.10639070442992 * safezoneH;
           colortext[] = {0,0,0,1};
           sizeex = 0.1;
           style = 34;
       };
       class buyerText : Life_RscText
       {
           x = 0.489321763799384 * safezoneW + safezoneX;
           y = 0.279927378358751 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.0964340501541044 * safezoneW;
           idc = 9603;
           colortext[] = {0,0,0,1};
       };
       class vendorText : Life_RscText
       {
           x = 0.493391531241244 * safezoneW + safezoneX;
           y = 0.341655773420479 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.0932363757355002 * safezoneW;
           idc = 9605;
           colortext[] = {0,0,0,1};
       };
       class checkbox : Life_Checkbox
       {
           idc = 9610;
           x = 0.389825581395348 * safezoneW + safezoneX;
           y = 0.684458968772694 * safezoneH + safezoneY;
           w = 0.00988372093023256 * safezoneW;
           h = 0.0228758169934641 * safezoneH;
           color[] = { 0,0,0,0.7 };
           colorfocused[] = { 0,0,0,1 };
           colorhover[] = { 0,0,0,1 };
           colorpressed[] = { 0,0,0,1 };
           colordisabled[] = { 0,0,0,1 };
       };
       class accept : Life_RscText
       {
           x = 0.40406976744186 * safezoneW + safezoneX;
           y = 0.673536673928831 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.201744186046512 * safezoneW;
           idc = 9611;
           colortext[] = {0,0,0,1};
       };
       class vehicleList : Life_RscCombo
       {
           x = 0.386627906976744 * safezoneW + safezoneX;
           y = 0.598010167029775 * safezoneH + safezoneY;
           w = 0.201162790697674 * safezoneW;
           h = 0.04 * safezoneH;
           idc = 9609;
           colortext[] = {0,0,0,1};
           colorbackground[] = {1,1,1,0.1};
       };
   };
};