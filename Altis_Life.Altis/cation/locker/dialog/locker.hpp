/*
    File: locker.hpp
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: dialog for locker 
*/
class LockerMenu {
    idd = 5000;
    name = "LockerMenu";
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.7;
            h = (1 / 25);
        };

        class RscBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.7;
            h = 0.7 - (22 / 250);
        };

        class RscTitleText: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 5001;
            text = "";
            x = 0.1;
            y = 0.2;
            w = 0.7;
            h = (1 / 25);
        };

        class LockerWeight : RscTitleText {
            idc = 5004;
            style = 1;
            text = "";
        };

        class RscLockerText: Life_RscText {
            idc = 5009;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "";
            sizeEx = 0.04;
            x = 0.11;
            y = 0.25;
            w = 0.3;
            h = 0.04;
        };

        class RscPlayerText: Life_RscText {
            idc = 5010;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "";
            sizeEx = 0.04;
            x = 0.49;
            y = 0.25;
            w = 0.3;
            h = 0.04;
        };
    };

    class Controls {
        class LockerGear: Life_RscListBox {
            idc = 5002;
            text = "";
            sizeEx = 0.030;
            x = 0.11;
            y = 0.29;
            w = 0.3;
            h = 0.42;
        };

        class PlayerGear: Life_RscListBox {
            idc = 5003;
            text = "";
            sizeEx = 0.030;
            x = 0.49;
            y = 0.29;
            w = 0.3;
            h = 0.42;
        };

        class LockerEdit: Life_RscEdit {
            idc = 5005;
            text = "1";
            sizeEx = 0.030;
            x = 0.11;
            y = 0.72;
            w = 0.3;
            h = 0.03;
        };

        class PlayerEdit: Life_RscEdit {
            idc = 5006;
            text = "1";
            sizeEx = 0.030;
            x = 0.49;
            y = 0.72;
            w = 0.3;
            h = 0.03;
        };

        class TakeItem: Life_RscButtonMenu {
            idc = 5011;
            text = "";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call cat_locker_fnc_lockerTakeItem;";
            x = 0.11;
            y = 0.78;
            w = 0.20;
            h = (1 / 25);
        };

        class StoreItem: Life_RscButtonMenu {
            idc = 5012;
            text = "";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call cat_locker_fnc_lockerStoreItem;";
            x = 0.59;
            y = 0.78;
            w = 0.20;
            h = (1 / 25);
        };

        class FilterList: Life_RscCombo {
            idc = 5007;
            colorBackground[] = {0,0,0,0.7};
            onLBSelChanged  = "_this call cat_locker_fnc_lockerFilter;";
            x = 0.35;
            y = 0.78;
            w = 0.20;
            h = (1 / 25);
        };

        class ButtonClose: Life_RscButtonMenu {
            idc = 5013;
            text = "";
            onButtonClick = "closeDialog 0;";
            x = 0.1;
            y = 0.9 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonUpgrade: Life_RscButtonMenu {
            idc = 5008;
            text = "";
            onButtonClick = "[] spawn cat_locker_fnc_upgradeLocker;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.9 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };
    };
};