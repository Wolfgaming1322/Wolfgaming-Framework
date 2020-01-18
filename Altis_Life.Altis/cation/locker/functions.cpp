class Cation_Locker {
    tag = "cat_locker";
    class functions {
        file = "cation\locker";        
        // Client        
        class index {};
        class initLocker {};
        class isNumber {};
        class lockerFilter {};
        class lockerInventory {};
        class lockerStoreItem {};
        class lockerTakeItem {};
        class openLocker {};
        class queryLocker { postInit = 1; };
        class StrToArray {};
        class upgradeLocker {};
        // Server
        class addLocker {};
        class fetchLockerTrunk {};
        class updateLockerTrunk {};
        // HC
        class addLockerHC {};
        class fetchLockerTrunkHC {};
        class updateLockerTrunkHC {};
    };
};