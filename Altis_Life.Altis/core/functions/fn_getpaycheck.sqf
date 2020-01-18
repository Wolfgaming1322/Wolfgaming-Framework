if (life_paycheckamount <= 0 || !life_paycheckready) exitWith {
    hint "Du hast derzeit keinen offenen Paycheck!";
};
hint format["Du hast deinen Paycheck abgeholt. Heutiger Paycheck:%1", life_paycheckamount];
life_cash = life_cash + life_paycheckamount;
life_paycheckamount = 0;
life_paycheckready = false;
