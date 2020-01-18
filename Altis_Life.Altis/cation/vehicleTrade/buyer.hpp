class Cat_vehicleTrade_buyer {
   idd = 9600;
   name = "Cat_vehicleTrade_buyer";
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
           tooltipcolortext[] = {1.1.1.1};
           tooltipcolorbox[] = {1.1.1.1};
           tooltipcolorshade[] = {0.0.0.0.65};
           idc = -1;
       };
   };
   class controls
   {
       class vendor : Life_RscText
       {
           x = 0.382267441860465 * safezoneW + safezoneX;
           y = 0.349027615334634 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.109302325581395 * safezoneW;
           idc = 9604;
           colortext[] = {0,0,0,1};
       };
       class vehicleToBuy : Life_RscText
       {
           x = 0.386627906976744 * safezoneW + safezoneX;
           y = 0.598010167029775 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.20203488372093 * safezoneW;
           idc = 9609;
           colortext[] = {0,0,0,1};
       };
       class vehicle : Life_RscText
       {
           x = 0.386918604651163 * safezoneW + safezoneX;
           y = 0.506989240530521 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.121783587839731 * safezoneW;
           idc = 9608;
           colortext[] = {0,0,0,1};
       };
       class buyer : Life_RscText
       {
           x = 0.381395348837209 * safezoneW + safezoneX;
           y = 0.286219451133281 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.104941860465116 * safezoneW;
           idc = 9602;
           colortext[] = {0,0,0,1};
       };
       class price : Life_RscText
       {
           x = 0.378488372093023 * safezoneW + safezoneX;
           y = 0.422992011619463 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.107848837209302 * safezoneW;
           idc = 9606;
           colortext[] = {0,0,0,1};
       };
       class sign : Life_RscButtonMenu
       {
           text = "";
           onbuttonclick = "[] call cat_vehicleTrade_fnc_signBuyer;";
           x = 0.390116279069767 * safezoneW + safezoneX;
           y = 0.761614684860299 * safezoneH + safezoneY;
           w = 0.0683139534883721 * safezoneW;
           h = 0.0399999999999999 * safezoneH;
           idc = 9613;
           colordisabled[] = {0,0,0,1};
           colortext[] = {0,0,0,1};
           color[] = {0,0,0,1};
           font = "LucidaConsoleB";
           style = ST_VCENTER;
           colorbackground[] = {1,1,1,0.1};
       };
       class treaty : Life_RscTitle
       {
           idc = 9601;
           x = 0.392441860465116 * safezoneW + safezoneX;
           y = 0.152868554829339 * safezoneH + safezoneY;
           w = 0.203779069767442 * safezoneW;
           h = 0.10639070442992 * safezoneH;
           colortext[] = {0,0,0,1};
           sizeex = 0.1;
           style = ST_TITLE;
       };
       class buyerText : Life_RscText
       {
           x = 0.489321763799384 * safezoneW + safezoneX;
           y = 0.279927378358751 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.0978875385261974 * safezoneW;
           idc = 9603;
           colortext[] = {0,0,0,1};
       };
       class vendorText : Life_RscText
       {
           x = 0.493391531241244 * safezoneW + safezoneX;
           y = 0.341655773420479 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.0935270734099188 * safezoneW;
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
           x = 0.404941860465116 * safezoneW + safezoneX;
           y = 0.673536673928831 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.191279069767442 * safezoneW;
           idc = 9611;
           colortext[] = {0,0,0,1};
       };
       class priceFix : Life_RscText
       {
           x = 0.489321763799384 * safezoneW + safezoneX;
           y = 0.415003631082063 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.0941084687587555 * safezoneW;
           idc = 9607;
           colortext[] = {0,0,0,1};
       };
       class nameSigned : Life_RscText
       {
           x = 0.538372093023256 * safezoneW + safezoneX;
           y = 0.752694262890341 * safezoneH + safezoneY;
           h = 0.04 * safezoneH;
           w = 0.084593023255814 * safezoneW;
           idc = 9612;
           colortext[] = {0,0,0,1};
           font = "LucidaConsoleB";
       };
       class abort : Life_RscButtonMenu
       {
           text = "";
           onbuttonclick = "[] call cat_vehicleTrade_fnc_abortBuyer;";
           x = 0.344622093023256 * safezoneW + safezoneX;
           y = 0.887770515613653 * safezoneH + safezoneY;
           w = 0.0770348837209298 * safezoneW;
           h = 0.0399999999999999 * safezoneH;
           idc = 9614;
           colortext[] = {0,0,0,1};
           style = ST_VCENTER;
       };
   };
};