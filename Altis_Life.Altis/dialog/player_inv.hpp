
class playerSettings {
   idd = 2001;
   name = "playerSettings";
   movingenable = 1;
   enablesimulation = 1;
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonex.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class ButtonOnlinebanking : Life_RscPictureButton
       {
           text = "menus\zv4\OnlineBanking.paa";
           tooltip = "Online Banking";
           onbuttonclick = "createDialog ""Life_Onlinebaning_management"";";
           x = 0.3828125 * safezoneW + safezoneX;
           y = 0.205452775073028 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1000;
       };
       class ButtonInv : Life_RscPictureButton
       {
           text = "menus\zv4\Buttoneninv.paa";
           tooltip = "Inventar";
           onbuttonclick = "createDialog ""Life_Inventar_management"";";
           x = 0.416666666666667 * safezoneW + safezoneX;
           y = 0.205452775073028 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1000;
       };
       class ButtonLicences : Life_RscPictureButton
       {
           text = "menus\zv4\ButtonenLicences.paa";
           tooltip = "Lizenzen";
           onbuttonclick = "createDialog ""License_Menu"";";
           x = 0.449479166666667 * safezoneW + safezoneX;
           y = 0.205452775073028 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1000;
       };
       class ButtonKeys : Life_RscPictureButton
       {
           idc = 2013;
           text = "menus\zv4\ButtonenSchluessel.paa";
           tooltip = "Schlüssel";
           onbuttonclick = "createDialog ""Life_key_management"";";
           x = 0.4828125 * safezoneW + safezoneX;
           y = 0.205452775073028 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonTelefon : Life_RscPictureButton
       {
           idc = 2014;
           text = "menus\zv4\ButtonenTelefon.paa";
           tooltip = "Telefon";
           onbuttonclick = "createDialog ""Life_cell_phone"";";
           x = 0.515625 * safezoneW + safezoneX;
           y = 0.205452775073028 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonEinstellungen : Life_RscPictureButton
       {
           text = "menus\zv4\ButtonenEinstellungen.paa";
           tooltip = "Einstellungen";
           onbuttonclick = "[] call life_fnc_settingsMenu;";
           x = 0.3828125 * safezoneW + safezoneX;
           y = 0.255111976630964 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1000;
       };
       class ButtonGangs : Life_RscPictureButton
       {
           idc = 2011;
           text = "menus\zv4\ButtonenGang.paa";
           tooltip = "Gang";
           onbuttonclick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
           x = 0.416666666666667 * safezoneW + safezoneX;
           y = 0.255111976630964 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonWantedList : Life_RscPictureButton
       {
           idc = 2012;
           text = "menus\zv4\ButtonenWantedlist.paa";
           tooltip = "Wanted Liste";
           onbuttonclick = "[] call life_fnc_wantedMenu";
           x = 0.515625 * safezoneW + safezoneX;
           y = 0.255111976630964 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonAdminMenu : Life_RscPictureButton
       {
           idc = 2021;
           text = "menus\zv4\ButtonenAdmin.paa";
           tooltip = "Admin Menu";
           onbuttonclick = "closeDialog 0; createDialog ""life_admin_menu"";";
           x = 0.3828125 * safezoneW + safezoneX;
           y = 0.305744888023369 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonSyncData : Life_RscPictureButton
       {
           text = "menus\zv4\ButtonenSyncSave.paa";
           tooltip = "Daten Abspeichern";
           onbuttonclick = "[] call SOCK_fnc_syncData;";
           x = 0.449479166666667 * safezoneW + safezoneX;
           y = 0.255111976630964 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1010;
       };
       class ButtonTelefonDown : Life_RscPictureButton
       {
           idc = 1001;
           text = "menus\zv4\ButtonenTelefon.paa";
           tooltip = "Telefon";
           onbuttonclick = "createDialog ""Life_cell_phone"";";
           x = 0.3828125 * safezoneW + safezoneX;
           y = 0.71080817916261 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonOnlinebankingDown : Life_RscPictureButton
       {
           text = "menus\zv4\OnlineBanking.paa";
           tooltip = "Online Banking";
           onbuttonclick = "createDialog ""Life_Onlinebaning_management"";";
           x = 0.416666666666667 * safezoneW + safezoneX;
           y = 0.71080817916261 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1002;
       };

       class ButtonMarkt : Life_RscPictureButton
       {
           text = "menus\zv2\ButtonenMarkt.paa";
		   onButtonClick = "call TLG_Client_fnc_helpMenu";
           tooltip = "Hilfe";
           x = 0.4828125 * safezoneW + safezoneX;
           y = 0.255111976630964 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1045;
       };
	   

       class ButtonInvDown : Life_RscPictureButton
       {
           text = "menus\zv4\Buttoneninv.paa";
           tooltip = "Inventar";
           onbuttonclick = "createDialog ""Life_Inventar_management"";";
           x = 0.449479166666667 * safezoneW + safezoneX;
           y = 0.71080817916261 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1003;
       };
       class ButtonKeysDown : Life_RscPictureButton
       {
           idc = 1005;
           text = "menus\zv4\ButtonenSchluessel.paa";
           tooltip = "Schlüssel";
           onbuttonclick = "createDialog ""Life_key_management"";";
           x = 0.4828125 * safezoneW + safezoneX;
           y = 0.71080817916261 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
       };
       class ButtonSyncDataDown : Life_RscPictureButton
       {
           text = "menus\zv4\ButtonenSyncSave.paa";
           tooltip = "Daten Abspeichern";
           onbuttonclick = "[] call SOCK_fnc_syncData;";
           x = 0.515625 * safezoneW + safezoneX;
           y = 0.71080817916261 * safezoneH + safezoneY;
           w = 0.0239583333333333 * safezoneW;
           h = 0.0418695228821811 * safezoneH;
           idc = 1006;
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
   };
};

