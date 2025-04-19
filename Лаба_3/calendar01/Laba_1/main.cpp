#include "stdafx.h"

int leapYear(int year);
int dayOfYear(int day, int month, int year);
int countOfDayUntilBirthday(int day, int month, int year, int iday, int imonth, int iyear);
string yearsMonth(int month);
void date(int days_number, int year);
void repeat();

unsigned int choice = 0;

int main() {
	setlocale(LC_ALL, "ru");

	unsigned int n, day, month, year, iday, imonth, iyear, days_number;

	cout << "Выберите действие:" << endl;
	cout << "1. Определить, является ли введённый год високосным." << endl;
	cout << "2. Вычислить порядковый номер введённого дня в году." << endl;
	cout << "3. Вычислить, сколько дней осталось до ближайшего вашего Дня рождения." << endl;
	cout << "4. Определить название месяца по его порядковому номеру." << endl;
	cout << "5. Определить дату по введённому порядковому номеру дня в году, вывести событие." << endl;
	cout << "Ваш выбор: "; cin >> n;

	if (n < 1 || n > 5) {
		do {
			cout << "Ошибка! Введите еще раз." << endl << endl;
			cin >> n; cout << endl;
		} while (n < 1 || n > 5);
	}

	if (n > 0 && n < 4) {
		cout << "Отлично! Теперь введите дату в формате ДД ММ ГГГГ: " << endl;
		cin >> day >> month >> year; cout << endl;
		if (day > 31 || day < 1 || month > 12 || month < 1 || year < 1) {
			do {
				cout << "Ошибка! Ведите дату еще раз." << endl << endl;
				cin >> day >> month >> year; cout << endl;
			} while (day > 31 || day < 1 || month > 12 || month < 1 || year < 1);
		}
	} 
	else if (n == 4) {
		cout << "Введите порядковый номер месяца: "; cin >> month; cout << endl;
		if (month < 1 || month > 12) {
			do {
				cout << "Ошибка! Введите еще раз." << endl << endl;
				cin >> month; cout << endl;
			} while (month < 1 || month > 12);
		}
	}
	else {
		cout << "Введите год: "; cin >> year; cout << endl;
		if (year < 1) {
			do {
				cout << "Ошибка! Введите еще раз." << endl << endl;
				cin >> year; cout << endl;
			} while (year < 1);
		}
		cout << "Введите порядковый номер дня в году: "; cin >> days_number; cout << endl;
		if (days_number < 1 || days_number > 366) {
			do {
				cout << "Ошибка! Ведите еще раз." << endl << endl;
				cin >> days_number; cout << endl;
			} while (days_number < 1 || days_number > 366);
		}
	}
	
	switch (n) {
	case 1: {
		if (leapYear(year)) {
			cout << year << " год является високосным." << endl << endl;

			repeat();
		}
		else {
			cout << year << " год не является високосным." << endl << endl;

			repeat();
		}
	} break;

	case 2: {
		cout << "Порядковый номер дня в году " << dayOfYear(day, month, year) << "." << endl << endl;

		repeat();
	} break;

	case 3: {
		cout << "Введите дату дня рождения в формате ДД ММ ГГГГ: " << endl;
		cin >> iday >> imonth >> iyear; cout << endl;
		if (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year) {
			do {
				cout << "Ошибка! Ведите дату еще раз." << endl << endl;
				cin >> iday >> imonth >> iyear; cout << endl;
			} while (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year);
		}
		cout << "Количество дней до вашего дня рождения " << countOfDayUntilBirthday(day, month, year, iday, imonth, iyear) << "." << endl << endl;

		repeat();
	} break;
	case 4: {
		cout << month << " месяц это " << yearsMonth(month) << "." << endl << endl;

		repeat();
	} break;
	case 5: {
		date(days_number, year);
		cout << endl;
		repeat();
	}
	}

	return 0;
}

void repeat() {
	cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
	cout << "Ваш выбор: "; cin >> choice; cout << endl;
	if (choice == 1) {
		main();
	}
	else {
		exit(0);
	}
}