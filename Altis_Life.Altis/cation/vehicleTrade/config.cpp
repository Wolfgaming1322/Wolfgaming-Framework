/*
    File: config.cpp
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Master config for vehicle trade system. 
*/
#include "buyer.hpp"
#include "vendor.hpp"
class Cation_VehicleTrade {

    DebugMode = 1; //Debug mode (0 = off | 1 = on)

    version = 5; // version 3.x -> 3 | version 4.0 - 4.3 -> 4 | version 4.4+ -> 5

    key = 36; //Key for opening the menu (https://community.bistudio.com/wiki/DIK_KeyCodes#German_keyboard)
    shift = 1; // 1 = true | 0 = false
    ctrl = 0; // 1 = true | 0 = false
    alt = 0; // 1 = true | 0 = false

    //Text
    aborted = "Du hast den Kaufvertrag nicht unterschrieben. Er ist somit nichtig und wird verworfen.";
    abortedVendor = "%1 hat den Kaufvertrag nicht akzeptiert. Er ist somit nichtig und wird verworfen.";
    noVehOwned = "Keine Fahrzeuge";
    distance = "Distanz";
    treaty = "Kaufvertrag";
    buyer = "Käufer";
    vendor = "Verkäufer";
    price = "Preis";
    vehicle = "Fahrzeug";
    accept = "Hiermit bestätige ich alle Angaben.";
    sign = "unterschreiben";
    abort = "ablehnen";
    didNotSelectVehicle = "Du hast kein Fahrzeug ausgewählt.";
    moneyTooLow = "Der Preis ist zu niedrig.";
    notNumberFormat = "Du hast keine echte Zahl eingegeben.";
    notAccepted = "Du musst deine Angaben noch auf ihre Korrektheit bestätigen.";
    noMoney = "Du hast nicht genügend Bargeld dabei.";
    soldVehicle = "Das Fahrzeug %1 wurde erfolgreich verkauft.";
    gotVehicle = "Das Fahrzeug %1 gehört nun ihnen.";
}