#include "stdafx.h"

string yearsMonth(int imonth) {
    string month[] = { "������", "�������", "����", "������",
                        "���", "����", "����", "������",
                        "��������", "�������", "������", "�������" };
    if (imonth > 0 && imonth <= 12) {
        return (month[imonth - 1]);
    }
    else return 0;   
}   