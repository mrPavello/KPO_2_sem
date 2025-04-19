#include "stdafx.h"

int countOfDayUntilBirthday(int day, int month, int year, int iday, int imonth, int iyear) {
	int dayNumber = day;
	int daysOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < month - 1; i++) {
		dayNumber += daysOfMonth[i];
	}
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month > 2) {
		dayNumber++;
	}

	int idayNumber = iday;
	for (int i = 0; i < imonth - 1; i++) {
		idayNumber += daysOfMonth[i];
	}
	if (((iyear % 4 == 0 && iyear % 100 != 0) || (iyear % 400 == 0)) && imonth > 2) {
		idayNumber++;
	}

	if (imonth < month) {
		int countOfDays;
		if ((iyear % 4 == 0 && iyear % 100 != 0) || (iyear % 400 == 0)) {
			countOfDays = 366 - dayNumber;
		}
		else {
			countOfDays = 365 - dayNumber;
		}
		return (countOfDays + idayNumber);
	}
	else {
		return (idayNumber - dayNumber);
	}
}