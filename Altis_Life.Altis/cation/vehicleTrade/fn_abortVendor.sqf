/*
    File: fn_abortVendor.sqf
    Author: B4v4r!4n_Str!k3r (julianbauer@cationstudio.com)
    Licence: THIS FILE AND EXTRACTS OF IT IS THE MINDSET OF CATIONSTUDIO
             AND ONLY AUTHORIZED PEOPLE/SERVERS ARE ALLOWED TO USE IT.
    Description: abort info for vendor
*/
params[
    ["_buyer","",[""]]
];
hint format[getText(missionConfigFile >> "Cation_VehicleTrade" >> "abortedVendor"),_buyer];