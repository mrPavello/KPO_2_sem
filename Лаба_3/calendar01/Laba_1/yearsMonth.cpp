#include "stdafx.h"

string yearsMonth(int imonth) {
    string month[] = { "Январь", "Февраль", "Март", "Апрель",
                        "Май", "Июнь", "Июль", "Август",
                        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    if (imonth > 0 && imonth <= 12) {
        return (month[imonth - 1]);
    }
    else return 0;   
}   