
class SettingsMenu {
   idd = 2900;
   name = "SettingsMenu";
   movingenable = 1;
   enablesimulation = 1;
   class controlsBackground
   {
       class Life_RscTitleBackground : life_RscPicture
       {
           text = "menus\zv4\phonexmenusettings.paa";
           idc = -1;
           x = 0.329687499999999 * safezoneW + safezoneX;
           y = 0.162609542356378 * safezoneH + safezoneY;
           w = 0.263541666666667 * safezoneW;
           h = 0.659201557935735 * safezoneH;
       };
       class SideChatHeader : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_SC";
           y = 0.572161635832522 * safezoneH + safezoneY;
           x = 0.391354166666666 * safezoneW + safezoneX;
           w = 0.070104166666667 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class RevealNearestHeader : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_RNObj";
           y = 0.599425511197663 * safezoneH + safezoneY;
           x = 0.391354166666666 * safezoneW + safezoneX;
           w = 0.070104166666667 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class BroacastHeader : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_BCSW";
           y = 0.625764362220058 * safezoneH + safezoneY;
           x = 0.391354166666666 * safezoneW + safezoneX;
           w = 0.070104166666667 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class Title : Life_RscTitle
       {
           idc = -1;
           colorbackground[] = {0,0,0,0};
           text = "$STR_SM_PlayerTags";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.54587147030185 * safezoneH + safezoneY;
           w = 0.070104166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
           colortext[] = {1,1,1,1};
       };
   };
   class controls
   {
       class VDonFoot : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_onFoot";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.425530671859786 * safezoneH + safezoneY;
           w = 0.070104166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class VDinCar : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_inCar";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.476163583252191 * safezoneH + safezoneY;
           w = 0.070104166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class VDinAir : Life_RscText
       {
           idc = -1;
           text = "$STR_SM_inAir";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.37587147030185 * safezoneH + safezoneY;
           w = 0.070104166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
           colortext[] = {1,1,1,1};
       };
       class VD_onfoot_slider : life_RscXSliderH
       {
           idc = 2901;
           text = "";
           onsliderposchanged = "[0,_this select 1] call life_fnc_s_onSliderChange;";
           tooltip = "$STR_SM_ToolTip1";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.451820837390458 * safezoneH + safezoneY;
           w = 0.133125 * safezoneW;
           h = 0.0216942551119761 * safezoneH;
       };
       class VD_onfoot_value : Life_RscEdit
       {
           idc = 2902;
           text = "";
           onchar = "[_this select 0, _this select 1,'ground',false] call life_fnc_s_onChar;";
           onkeyup = "[_this select 0, _this select 1,'ground',true] call life_fnc_s_onChar;";
           x = 0.46375 * safezoneW + safezoneX;
           y = 0.425530671859786 * safezoneH + safezoneY;
           w = 0.060729166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
       };
       class VD_car_slider : life_RscXSliderH
       {
           idc = 2911;
           text = "";
           onsliderposchanged = "[1,_this select 1] call life_fnc_s_onSliderChange;";
           tooltip = "$STR_SM_ToolTip2";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.502161635832523 * safezoneH + safezoneY;
           w = 0.133645833333334 * safezoneW;
           h = 0.0216942551119761 * safezoneH;
       };
       class VD_car_value : Life_RscEdit
       {
           idc = 2912;
           text = "";
           onchar = "[_this select 0, _this select 1,'vehicle',false] call life_fnc_s_onChar;";
           onkeyup = "[_this select 0, _this select 1,'vehicle',true] call life_fnc_s_onChar;";
           x = 0.46375 * safezoneW + safezoneX;
           y = 0.476163583252191 * safezoneH + safezoneY;
           w = 0.060729166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
       };
       class VD_air_slider : life_RscXSliderH
       {
           idc = 2921;
           text = "";
           onsliderposchanged = "[2,_this select 1] call life_fnc_s_onSliderChange;";
           tooltip = "$STR_SM_ToolTip3";
           x = 0.391354166666666 * safezoneW + safezoneX;
           y = 0.401869522882182 * safezoneH + safezoneY;
           w = 0.133125 * safezoneW;
           h = 0.0216942551119761 * safezoneH;
       };
       class VD_air_value : Life_RscEdit
       {
           idc = 2922;
           text = "";
           onchar = "[_this select 0, _this select 1,'air',false] call life_fnc_s_onChar;";
           onkeyup = "[_this select 0, _this select 1,'air',true] call life_fnc_s_onChar;";
           x = 0.46375 * safezoneW + safezoneX;
           y = 0.37587147030185 * safezoneH + safezoneY;
           w = 0.060729166666667 * safezoneW;
           h = 0.0243232716650438 * safezoneH;
       };
       class PlayerTagsONOFF : Life_Checkbox
       {
           tooltip = "$STR_GUI_PlayTags";
           idc = 2970;
           sizeex = 0.04;
           oncheckedchanged = "['tags',_this select 1] call life_fnc_s_onCheckedChange;";
           x = 0.46375 * safezoneW + safezoneX;
           y = 0.54587147030185 * safezoneH + safezoneY;
           w = 0.015625 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
       };
       class SideChatONOFF : PlayerTagsONOFF
       {
           idc = 2971;
           tooltip = "$STR_GUI_SideSwitch";
           oncheckedchanged = "['sidechat',_this select 1] call life_fnc_s_onCheckedChange;";
           y = 0.573135345666991 * safezoneH + safezoneY;
           x = 0.46375 * safezoneW + safezoneX;
           w = 0.015416666666667 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
       };
       class RevealONOFF : PlayerTagsONOFF
       {
           idc = 2972;
           tooltip = "$STR_GUI_PlayerReveal";
           oncheckedchanged = "['objects',_this select 1] call life_fnc_s_onCheckedChange;";
           y = 0.599474196689387 * safezoneH + safezoneY;
           x = 0.46375 * safezoneW + safezoneX;
           w = 0.015416666666667 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
       };
       class BroadcastONOFF : PlayerTagsONOFF
       {
           idc = 2973;
           tooltip = "$STR_GUI_BroadcastSwitch";
           oncheckedchanged = "['broadcast',_this select 1] call life_fnc_s_onCheckedChange;";
           y = 0.625764362220058 * safezoneH + safezoneY;
           x = 0.46375 * safezoneW + safezoneX;
           w = 0.0159375000000003 * safezoneW;
           h = 0.0247224926971765 * safezoneH;
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

