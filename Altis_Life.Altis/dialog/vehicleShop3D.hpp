class Life_Vehicle_Shop_v2_3D {
  idd = 2300;
  name = "Life_Vehicle_Shop_v2_3D";
  movingenable = 0;
  enablesimulation = 1;
  onload = "call life_fnc_3dPreviewInit; ctrlShow [2330,false];";
  onunload = "call life_fnc_3dPreviewExit;";
  class controlsBackground
  {
    class MainBackground : Life_RscText
    {
      colorbackground[] = {0.1,0.1,0.1,0.5};
      idc = -1;
      x = 0.0204687 * safezoneW + safezoneX;
      y = 0.06 * safezoneH + safezoneY;
      w = 0.149531 * safezoneW;
      h = 0.656650438169425 * safezoneH;
    };
    class SecondBackground : Life_RscText
    {
      colorbackground[] = {0.1,0.1,0.1,0.5};
      idc = -1;
      x = 0.809375 * safezoneW + safezoneX;
      y = 0.06 * safezoneH + safezoneY;
      w = 0.190781 * safezoneW;
      h = 0.341 * safezoneH;
    };
    class Title : Life_RscTitle
    {
      idc = 2301;
      text = "";
      x = 0.0204687 * safezoneW + safezoneX;
      y = 0.027 * safezoneH + safezoneY;
      w = 0.144375 * safezoneW;
      h = 0.033 * safezoneH;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };
    class VehicleTitleBox : Life_RscText
    {
      idc = -1;
      text = "$STR_GUI_ShopStock";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      x = 0.0204687 * safezoneW + safezoneX;
      y = 0.06 * safezoneH + safezoneY;
      w = 0.149531 * safezoneW;
      h = 0.033 * safezoneH;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };
    class VehicleInfoHeader : Life_RscText
    {
      idc = 2330;
      text = "$STR_GUI_VehInfo";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      x = 0.809375 * safezoneW + safezoneX;
      y = 0.058 * safezoneH + safezoneY;
      w = 0.190781 * safezoneW;
      h = 0.022 * safezoneH;
    };
    class CloseBtn : Life_RscButtonMenu
    {
      text = "$STR_Global_Close";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      onbuttonclick = "closeDialog 0;";
      x = 0.023487 * safezoneW + safezoneX;
      y = 0.687887486854917 * safezoneH + safezoneY;
      w = 0.144375 * safezoneW;
      h = 0.0219957 * safezoneH;
      idc = -1;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };

    class RentCar : Life_RscButtonMenu
    {
      text = "$STR_Global_RentVeh";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      onbuttonclick = "[false] spawn life_fnc_vehicleShopBuy;";
      x = 0.0995286666666667 * safezoneW + safezoneX;
      y = 0.636393 * safezoneH + safezoneY;
      w = 0.0676588333333333 * safezoneW;
      h = 0.0219957 * safezoneH;
      idc = -1;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };

    class BuyCar : Life_RscButtonMenu
    {
      idc = 2309;
      text = "$STR_Global_Buy";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      onbuttonclick = "[true] spawn life_fnc_vehicleShopBuy;";
      x = 0.023487 * safezoneW + safezoneX;
      y = 0.636393 * safezoneH + safezoneY;
      w = 0.0676588333333333 * safezoneW;
      h = 0.0219957 * safezoneH;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };

    class BuyCarBank : Life_RscButtonMenu
    {
      idc = 2310;
      text = "$STR_Global_Buy_Bank";
      colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
      onbuttonclick = "[true] spawn life_fnc_vehicleShopBuyBank;";
      x = 0.023487 * safezoneW + safezoneX;
      y = 0.662683165530672 * safezoneH + safezoneY;
      w = 0.144375 * safezoneW;
      h = 0.0219957 * safezoneH;
      class Attributes {
			   font = "PuristaMedium";
			   align = "center";
		   };
    };

  };
  class controls
  {
    class VehicleList : Life_RscListBox
    {
      idc = 2302;
      text = "";
      sizeex = 0.04;
      colorbackground[] = {0.1,0.1,0.1,0.9};
      onlbselchanged = "_this call life_fnc_vehicleShopLBChange";
      x = 0.023487 * safezoneW + safezoneX;
      y = 0.095 * safezoneH + safezoneY;
      w = 0.144375 * safezoneW;
      h = 0.5 * safezoneH;
    };
    class ColorList : Life_RscCombo
    {
      idc = 2304;
      onlbselchanged = "call life_fnc_vehicleColor3DRefresh;";
      x = 0.0204687 * safezoneW + safezoneX;
      y = 0.6034 * safezoneH + safezoneY;
      w = 0.149531 * safezoneW;
      h = 0.0219957 * safezoneH;
    };
    class vehicleInfomationList : Life_RscStructuredText
    {
      idc = 2303;
      sizeex = 0.035;
      x = 0.819688 * safezoneW + safezoneX;
      y = 0.104 * safezoneH + safezoneY;
      w = 0.175313 * safezoneW;
      h = 0.275 * safezoneH;
    };
  };
};
