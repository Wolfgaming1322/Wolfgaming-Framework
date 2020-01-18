/*
    File: config.cpp
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: Master config for locker system. 
*/
#include "dialog\locker.hpp"
class Cation_Locker {

    locker_size_price[] = { //upgrade price and size stages
        {"100","10000"}, //{"size","price"}
        {"150","15000"},
		{"200","15000"},
		{"250","15000"},
		{"300","15000"},
        {"350","15000"}
    };

    DebugMode = 1; //Debugmodus (1 = Logeinträge erstellen | 0 = keine Logeinträge erstellen)

    HeadlessSupport = 0; //Enable/Disable Headless client support. Default: 1 (1 = Enabled / 0 = Disabled)

    version = 5; // version 3.x -> 3 | 4.0 - 4.3 -> 4 | version 4.4+ -> 5
    
    weightMultiplier = 0.25; //Weight Multiplier for ArmA Items

    Locker = "Schließfach"; //Locker
    LockerInventory = "Schließfachstauraum"; //Locker Inventory
    PlayerInventory = "Spielerinventar"; //Player Inventory
    Take = "Nehmen";
    Store = "Lagern";
    Close = "Schließen";
    No = "Nein";
    Yes = "Ja";
    Upgrade = "Upgraden";
    Weight = "Gewicht:";
    Warning = "Entferne deine Aufsätze und Magazine von den Waffen bevor du die Waffe in das Schließfach legst! Entferne außerdem sämtliche Items aus den Klamotten bevor du diese in das Schließfach legst!";
    WarningWeapon = "Ein oder mehrere Waffen wurden nicht hinzugefügt, da sich daran noch Aufsätze und Magazine befinden!";
    WarningClothing = "Ein oder mehrere Klamotten werden nicht angezeigt, da sich darin noch Items befinden!";
    Amount = "Anzahl";
    AmmoCount = "Patronen";
    NoItems = "Keine Items verfügbar";
    VItems = "virtuelle Items";
    Weapons = "Waffen";
    Magazines = "Magazine";
    Items = "Items";
    Equipment = "Equipment";
    WrongNumFormat = "Ungültiges Zahlenformat!";
    Under1 = "Du kannst nichts unter 1 eingeben!";
    VehicleFullOrInsufCap = "Das Fahrzeug ist entweder voll oder kann nicht so viel halten.";
    CouldNotRemoveItemsToPutInVeh = "Das Fahrzeug ist entweder voll oder hat nicht so viel Platz.";
    NoRoom = "Du hast nicht genug Platz für den Gegenstand.";
    NoSelection = "Du hast nichts ausgewählt.";
    NotEnough = "Das Fahrzeug hat nicht so viele dieser Gegenstände.";
    InvFull = "Dein Inventar ist voll.";
    UpgradeLocker = "Schließfach upgraden ...";
    UpgradeLockerMSG = "Soll ihr Schließfach für %1$ von %3 auf %2 Steckplätze erweitert werden?";
    UpgradeSuccess = "Schließfach erfolgreich für %1$ auf %2 Steckplätze erweitert.";
    NotEnoughCash = "Du hast nicht genügend Bargeld dabei!";
};
