
class Life_My_Gang_Diag {
   idd = 2620;
   name = "Life_My_Gang_Diag";
   movingenable = 0;
   enablesimulation = 1;
   onload = "";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenugang.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class Title : Life_RscTitle
       {
           colorbackground[] = {0, 0, 0, 0};
           idc = 2629;
           text = "";
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.320350535540409 * safezoneH + safezoneY;
           w = 0.0531249999999996 * safezoneW;
           h = 0.0155793573515093 * safezoneH;
       };
       class GangMemberList : Life_RscListBox
       {
           idc = 2621;
           text = "";
           sizeex = 0.035;
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.342745861733203 * safezoneH + safezoneY;
           w = 0.164583333333333 * safezoneW;
           h = 0.121713729308666 * safezoneH;
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
       class GangLeave : Life_RscButtonMenu
       {
           text = "$STR_Gang_Leave";
           onbuttonclick = "[] call life_fnc_gangLeave";
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.514479065238559 * safezoneH + safezoneY;
           w = 0.1640625 * safezoneW;
           h = 0.0230087633885102 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class GangLock : Life_RscButtonMenu
       {
           idc = 2622;
           text = "$STR_Gang_UpgradeSlots";
           onbuttonclick = "[] spawn life_fnc_gangUpgrade";
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.54076923076923 * safezoneH + safezoneY;
           w = 0.163541666666666 * safezoneW;
           h = 0.0249561830574489 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class GangKick : Life_RscButtonMenu
       {
           idc = 2624;
           text = "$STR_Gang_Kick";
           onbuttonclick = "[] call life_fnc_gangKick";
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.569006815968842 * safezoneH + safezoneY;
           w = 0.163541666666666 * safezoneW;
           h = 0.0249561830574489 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class GangLeader : Life_RscButtonMenu
       {
           idc = 2625;
           text = "$STR_Gang_SetLeader";
           onbuttonclick = "[] spawn life_fnc_gangNewLeader";
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.597244401168452 * safezoneH + safezoneY;
           w = 0.163541666666666 * safezoneW;
           h = 0.0249561830574489 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class InviteMember : Life_RscButtonMenu
       {
           idc = 2630;
           text = "$STR_Gang_Invite_Player";
           onbuttonclick = "[] spawn life_fnc_gangInvitePlayer";
           y = 0.486387536514119 * safezoneH + safezoneY;
           x = 0.380208333333334 * safezoneW + safezoneX;
           w = 0.164583333333333 * safezoneW;
           h = 0.0249561830574489 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class DisbandGang : Life_RscButtonMenu
       {
           idc = 2631;
           text = "$STR_Gang_Disband_Gang";
           onbuttonclick = "[] spawn life_fnc_gangDisband";
           y = 0.625481986368062 * safezoneH + safezoneY;
           x = 0.380208333333334 * safezoneW + safezoneX;
           w = 0.163541666666666 * safezoneW;
           h = 0.0249561830574489 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class ColorList : Life_RscCombo
       {
           idc = 2632;
           x = 0.380208333333334 * safezoneW + safezoneX;
           y = 0.467380720545278 * safezoneH + safezoneY;
           w = 0.164583333333333 * safezoneW;
           h = 0.0166991236611488 * safezoneH;
       };
       class GangBank : Title
       {
           idc = 601;
           style = 1;
           text = "";
           x = 0.492395833333334 * safezoneW + safezoneX;
           y = 0.320350535540409 * safezoneH + safezoneY;
           w = 0.052395833333333 * safezoneW;
           h = 0.0155793573515093 * safezoneH;
           colorbackground[] = {0,0,0,0.643137254901961};
       };
   };
};

class Life_Create_Gang_Diag {
   idd = 2520;
   name = "Life_Create_Gang_Diag";
   movingenable = 0;
   enablesimulation = 1;
   onload = "[] spawn {waitUntil {!isNull (findDisplay 2520)}; ((findDisplay 2520) displayCtrl 2523) ctrlSetText format [localize ""STR_Gang_PriceTxt"",[(getNumber(missionConfigFile >> 'Life_Settings' >> 'gang_price'))] call life_fnc_numberText]};";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenugangcreate.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class InfoMsg : Life_RscStructuredText
       {
           idc = 2523;
           sizeex = 0.020;
           x = 0.3825 * safezoneW + safezoneX;
           y = 0.3356864654333 * safezoneH + safezoneY;
           w = 0.160729166666667 * safezoneW;
           h = 0.0976144109055506 * safezoneH;
           colortext[] = {0,0,0,1};
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
       class GangCreateField : Life_RscButtonMenu
       {
           text = "$STR_Gang_Create";
           onbuttonclick = "[] call life_fnc_createGang";
           x = 0.397604166666666 * safezoneW + safezoneX;
           y = 0.507809152872443 * safezoneH + safezoneY;
           w = 0.132083333333334 * safezoneW;
           h = 0.025783836416748 * safezoneH;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class CreateGangText : Life_RscEdit
       {
           idc = 2522;
           text = "$STR_Gang_YGN";
           x = 0.3825 * safezoneW + safezoneX;
           y = 0.471713729308666 * safezoneH + safezoneY;
           w = 0.160729166666667 * safezoneW;
           h = 0.0248782862706915 * safezoneH;
       };
   };
};

