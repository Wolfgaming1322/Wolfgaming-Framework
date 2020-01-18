/* #Vohuti
$[
	1.063,
	["helpMenu",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1000,"Life_RscTitleBackground",[1,"TheLastGamer Hilfe",["0.298906 * safezoneW + safezoneX","0.27516 * safezoneH + safezoneY","0.170156 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"MainBackground",[1,"",["0.298906 * safezoneW + safezoneX","0.2976 * safezoneH + safezoneY","0.402187 * safezoneW","0.407 * safezoneH"],[-1,-1,-1,-1],["(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"mText",[1,"Womit kÃ¶nnen wir helfen?",["0.300969 * safezoneW + safezoneX","0.302 * safezoneH + safezoneY","0.195937 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],["(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"mText2",[1,"Infotext",["0.502062 * safezoneW + safezoneX","0.302 * safezoneH + safezoneY","0.195937 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],["(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5],[-1,-1,-1,-1],"","-1"],[]],
	[1500,"itemList",[1,"",["0.304062 * safezoneW + safezoneX","0.3328 * safezoneH + safezoneY","0.190781 * safezoneW","0.363 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"",[1,"TheLastGamer Hilfe",["0.298906 * safezoneW + safezoneX","0.2756 * safezoneH + safezoneY","0.170156 * safezoneW","0.022 * safezoneH"],[0.95,0.95,0.95,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[2400,"close",[1,"Schliessen",["0.636641 * safezoneW + safezoneX","0.7046 * safezoneH + safezoneY","0.0644531 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1005,"",[1,"Farmen",["0.497937 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.190781 * safezoneW","0.055 * safezoneH"],[0.95,0.95,0.95,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1100,"Description",[1,"Beschreibung",["0.497937 * safezoneW + safezoneX","0.379 * safezoneH + safezoneY","0.06159 * safezoneW","0.044 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1101,"DescriptionText",[1,"",["0.497937 * safezoneW + safezoneX","0.4164 * safezoneH + safezoneY","0.195937 * safezoneW","0.2772 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/
class helpDisplay {
    idd = 60700;
    name= "helpDisplay";
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
		class Life_RscTitleBackground: Life_RscText
		{
			idc = -1;
			text = "TheLastGamer Hilfe"; //--- ToDo: Localize;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.27516 * safezoneH + safezoneY;
			w = 0.170156 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
		};
		class MainBackground: Life_RscText
		{
			idc = -1;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.2976 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.407 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class mText: Life_RscText
		{
			idc = -1;
			text = "Womit können wir helfen?"; //--- ToDo: Localize;
			x = 0.300969 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
		};
		class mText2: Life_RscText
		{
			idc = -1;
			text = "Infotext"; //--- ToDo: Localize;
			x = 0.502062 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])",0.5};
		};
    };

    class controls {
        class itemList: Life_RscListBox
		{
			idc = 67001;
			onLBSelChanged = "_this call TLG_Client_fnc_menuLBChanged";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.3328 * safezoneH + safezoneY;
			w = 0.190781 * safezoneW;
			h = 0.363 * safezoneH;
			sizeEx = 2.5 * 0.02;
		};
		class Title: Life_RscTitle
		{
			idc = 67003;
			text = "TheLastGamer Hilfe"; //--- ToDo: Localize;
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.2756 * safezoneH + safezoneY;
			w = 0.170156 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.95,0.95,0.95,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * GUI_GRID_H;
		};
		class ButtonClose: Life_RscButtonMenu
		{
			onButtonClick = "closeDialog 0;";
			idc = 60702;
			text = "Schließen"; //--- ToDo: Localize;
			x = 0.636641 * safezoneW + safezoneX;
			y = 0.7046 * safezoneH + safezoneY;
			w = 0.0644531 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ItemName: Life_RscText
		{
			idc = 60704;
			text = "";
			x = 0.497937 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.190781 * safezoneW;
			h = 0.055 * safezoneH;
			sizeEx = 2.7 * 0.02;
		};
		class Description: Life_RscStructuredText
		{
			idc = 60708;
			text = "Beschreibung:"; //--- ToDo: Localize;
			x = 0.497937 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.06159 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class DescriptionText: Life_RscStructuredText
		{
			idc = 60709;
			text = "";
			x = 0.497937 * safezoneW + safezoneX;
			y = 0.4164 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.2772 * safezoneH;
		};
    };
};