class life_progress {
    name = "life_progress";
    idd = 38200;
    fadein=0;
    duration = 99999999999;
    fadeout=0;
    movingEnable = 0;
    onLoad="uiNamespace setVariable ['life_progress',_this select 0]";
    objects[]={};

    class controlsBackground {
		class RscProgressBackground : Life_RscText {
			idc = -1;
			colorBackground[] = { 0.2, 0.2, 0.2, 0.72 };

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.1942 * safezoneH + safezoneY;
			w = 0.289776 * safezoneW;
			h = 0.0242 * safezoneH;
		};
		class RscProgressBar : Life_RscProgress {
			idc = 38201;

			x = 0.355625 * safezoneW + safezoneX;
			y = 0.1942 * safezoneH + safezoneY;
			w = 0.289776 * safezoneW;
			h = 0.0242 * safezoneH;

			//colorBackground[] = { 0.1, 0.1, 0.1, 0.5 };
			colorBar[] = {1,0.647,0,1};
			colorFrame[] = {0,0,0,0};
		};

		class RscProgressText : Life_RscText {
			idc = 38202;
			text = "Servicing Chopper (50%)...";

			x = 0.353563 * safezoneW + safezoneX;
			y = 0.1524 * safezoneH + safezoneY;
			w = 0.290766 * safezoneW;
			h = 0.055 * safezoneH;
		};
    };
};

class life_timer {
    name = "life_timer";
    idd = 38300;
    fadeIn = 1;
    duration = 99999999999;
    fadeout = 1;
    movingEnable = 0;
    onLoad = "uiNamespace setVariable ['life_timer',_this select 0]";
    objects[] = {};

    class controlsBackground {
        class TimerIcon: life_RscPicture {
            idc = -1;
            text = "\a3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa";
            x = 0.00499997 * safezoneW + safezoneX;
            y = 0.291 * safezoneH + safezoneY;
            w = 0.04;
            h = 0.045;
        };

        class TimerText: Life_RscText {
            colorBackground[] = {0,0,0,0};
            idc = 38301;
            text = "";
            x = 0.0204688 * safezoneW + safezoneX;
            y = 0.2778 * safezoneH + safezoneY;
            w = 0.09125 * safezoneW;
            h = 0.055 * safezoneH;
        };
    };
};
