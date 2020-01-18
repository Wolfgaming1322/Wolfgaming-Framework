
class Life_cell_phone {
   idd = 3000;
   name = "Life_cell_phone";
   movingenable = 0;
   enablesimulation = 1;
   onload = "[] spawn life_fnc_cellphone";
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenutelefon.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
   };
   class controls
   {
       class textEdit : Life_RscEdit
       {
           idc = 3003;
           text = "";
           sizeex = 0.030;
           x = 0.382291666666667 * safezoneW + safezoneX;
           y = 0.375949367088608 * safezoneH + safezoneY;
           w = 0.159895833333333 * safezoneW;
           h = 0.107010710808179 * safezoneH;
       };
       class TextMsgButton : Life_RscButtonMenu
       {
           idc = 3015;
           text = "Nachricht";
           colorbackground[] = {1,0.647058823529412,0,1};
           onbuttonclick = "[] call TON_fnc_cell_textmsg";
           x = 0.382291666666667 * safezoneW + safezoneX;
           y = 0.487293086660176 * safezoneH + safezoneY;
           w = 0.159895833333333 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class PlayerList : Life_RscCombo
       {
           idc = 3004;
           x = 0.382291666666667 * safezoneW + safezoneX;
           y = 0.349026290165531 * safezoneH + safezoneY;
           w = 0.126041666666666 * safezoneW;
           h = 0.0141674780915285 * safezoneH;
       };
       class TextCopButton : Life_RscButtonMenu
       {
           idc = 3016;
           text = "Polizei";
           colorbackground[] = {0,0,1,1};
           onbuttonclick = "[] call TON_fnc_cell_textcop";
           x = 0.465625 * safezoneW + safezoneX;
           y = 0.542794547224927 * safezoneH + safezoneY;
           w = 0.0760416666666663 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class TextAdminButton : Life_RscButtonMenu
       {
           idc = 3017;
           text = "Admins";
           colorbackground[] = {1,0,0,1};
           onbuttonclick = "[] call TON_fnc_cell_textadmin";
           x = 0.382291666666667 * safezoneW + safezoneX;
           y = 0.568646543330087 * safezoneH + safezoneY;
           w = 0.0755208333333333 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class AdminMsgButton : Life_RscButtonMenu
       {
           idc = 3020;
           text = "$STR_CELL_AdminMsg";
           colorbackground[] = {1,0,0,1};
           onbuttonclick = "[] call TON_fnc_cell_adminmsg";
           x = 0.3953125 * safezoneW + safezoneX;
           y = 0.611927945472248 * safezoneH + safezoneY;
           w = 0.126041666666666 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class AdminMsgAllButton : Life_RscButtonMenu
       {
           idc = 3021;
           text = "$STR_CELL_AdminMSGAll";
           colorbackground[] = {1,0,0,1};
           onbuttonclick = "[] call TON_fnc_cell_adminmsgall";
           x = 0.3953125 * safezoneW + safezoneX;
           y = 0.63919182083739 * safezoneH + safezoneY;
           w = 0.126041666666666 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
       };
       class EMSRequest : Life_RscButtonMenu
       {
           idc = 3022;
           text = "Sanitäter";
           colorbackground[] = {0,0.501960784313725,0,1};
           onbuttonclick = "[] call TON_fnc_cell_emsrequest";
           x = 0.382291666666667 * safezoneW + safezoneX;
           y = 0.542794547224927 * safezoneH + safezoneY;
           w = 0.0760416666666667 * safezoneW;
           h = 0.0219571567672833 * safezoneH;
           sizeex = 0.045;
		   class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
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

