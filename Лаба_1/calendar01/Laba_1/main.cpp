#include "stdafx.h"

using namespace std;

int leapYear(int year);
int dayOfYear(int day, int month, int year);
int countOfDayUntilBirthday(int day, int month, int year, int iday, int imonth, int iyear);

int main() {
	setlocale(LC_ALL, "ru");

	unsigned int n, day, month, year, iday, imonth, iyear, choice;

	cout << "Выберите действие:" << endl;
	cout << "1. Определить, является ли введённый год високосным." << endl;
	cout << "2. Вычислить порядковый номер введённого дня в году." << endl;
	cout << "3. Вычислить, сколько дней осталось до ближайшего вашего Дня рождения." << endl;
	cout << "Ваш выбор: "; cin >> n;

	if (n < 1 || n > 3) {
		cout << "Ошибка! Введён неверный вариант действия." << endl;
		main();
	}

	cout << "Отлично! Теперь введите дату в формате ДД ММ ГГГГ: " << endl;
	cin >> day >> month >> year; cout << endl;
	if (day > 31 || day < 1 || month > 12 || month < 1 || year > 9999 || year < 1) {
		do {
			cout << "Ошибка! Ведите дату еще раз." << endl << endl;
			cin >> day >> month >> year; cout << endl;
		} while (day > 31 || day < 1 || month > 12 || month < 1 || year > 9999 || year < 1);
	}

	switch (n) {
	case 1: {
		if (leapYear(year)) {
			cout << year << " год является високосным." << endl << endl;

			cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
			cout << "Ваш выбор: "; cin >> choice; cout << endl;
			if (choice == 1) {
				main();
			}
			else if (choice == 0) {
				exit(0);
			}
			else {
				do {
					cout << "Введите корректное число!" << endl << endl;
					cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
					cout << "Ваш выбор: "; cin >> choice; cout << endl;
					if (choice == 1) {
						main();
					}
					else {
						exit(0);
					}
				} while (choice != 0);
			}
		}
		else {
			cout << year << " год не является високосным." << endl << endl;

			cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
			cout << "Ваш выбор: "; cin >> choice; cout << endl;
			if (choice == 1) {
				main();
			}
			else if (choice == 0) {
				exit(0);
			}
			else {
				do {
					cout << "Введите корректное число!" << endl << endl;
					cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
					cout << "Ваш выбор: "; cin >> choice; cout << endl;
					if (choice == 1) {
						main();
					}
					else {
						exit(0);
					}
				} while (choice != 0);
			}
		}
	} break;

	case 2: {
		cout << "Порядковый номер дня в году " << dayOfYear(day, month, year) << "." << endl << endl;

		cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
		cout << "Ваш выбор: "; cin >> choice; cout << endl;
		if (choice == 1) {
			main();
		}
		else if (choice == 0) {
			exit(0);
		}
		else {
			do {
				cout << "Введите корректное число!" << endl << endl;
				cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
				cout << "Ваш выбор: "; cin >> choice; cout << endl;
				if (choice == 1) {
					main();
				}
				else {
					exit(0);
				}
			} while (choice != 0);
		}
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
		cout << "Количество дней до вашего Дня рождения " << countOfDayUntilBirthday(day, month, year, iday, imonth, iyear) << "." << endl << endl;

		cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
		cout << "Ваш выбор: "; cin >> choice; cout << endl;
		if (choice == 1) {
			main();
		}
		else if (choice == 0) {
			exit(0);
		}
		else {
			do {
				cout << "Введите корректное число!" << endl << endl;
				cout << "Хотите продолжить? Если да - введите 1, если нет - 0" << endl;
				cout << "Ваш выбор: "; cin >> choice; cout << endl;
				if (choice == 1) {
					main();
				}
				else {
					exit(0);
				}
			} while (choice != 0);
		}
	} break;
	}

	return 0;
}