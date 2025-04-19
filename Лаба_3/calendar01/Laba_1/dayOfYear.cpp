#include "stdafx.h"

int dayOfYear(int day, int month, int year) {
	int dayNumber = day;
	int daysOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < month - 1; i++) {
		dayNumber += daysOfMonth[i];
	}
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month > 2) {
		dayNumber++;
	}
	return dayNumber;
}
