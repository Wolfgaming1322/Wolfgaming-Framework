life_actions = [];
switch (playerSide) do {
    case civilian:{
            life_actions pushBack(player addAction[localize "STR_pAct_DropFishingNet", life_fnc_dropFishingNet, "", 0, false, false, "", '(surfaceisWater(getPos vehicle player))&&(vehicle player isKindOf "Ship")&& life_carryWeight<life_maxWeight && speed(vehicle player)<2 && speed(vehicle player)>-1 && !life_net_dropped ']);
            life_actions pushBack(player addAction[localize "STR_pAct_RobPerson", life_fnc_robAction, "", 0, false, false, "", '!isNull cursorObject && player distance cursorObject<3.5 && isPlayer cursorObject && animationState cursorObject=="Incapacitated" && !(cursorObject getVariable["robbed",false])']);
        };
    case west:{
            life_actions = life_actions + [player addAction["Sachen entfernen", life_fnc_seizeWeapon, cursorTarget, 0, false, false, "", 'count(nearestObjects[player,["weaponholder"],3])>0']];
        };
    case independent:{};
};
