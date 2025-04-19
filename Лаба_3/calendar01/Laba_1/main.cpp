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

	cout << "�������� ��������:" << endl;
	cout << "1. ����������, �������� �� �������� ��� ����������." << endl;
	cout << "2. ��������� ���������� ����� ��������� ��� � ����." << endl;
	cout << "3. ���������, ������� ���� �������� �� ���������� ������ ��� ��������." << endl;
	cout << "4. ���������� �������� ������ �� ��� ����������� ������." << endl;
	cout << "5. ���������� ���� �� ��������� ����������� ������ ��� � ����, ������� �������." << endl;
	cout << "��� �����: "; cin >> n;

	if (n < 1 || n > 5) {
		do {
			cout << "������! ������� ��� ���." << endl << endl;
			cin >> n; cout << endl;
		} while (n < 1 || n > 5);
	}

	if (n > 0 && n < 4) {
		cout << "�������! ������ ������� ���� � ������� �� �� ����: " << endl;
		cin >> day >> month >> year; cout << endl;
		if (day > 31 || day < 1 || month > 12 || month < 1 || year < 1) {
			do {
				cout << "������! ������ ���� ��� ���." << endl << endl;
				cin >> day >> month >> year; cout << endl;
			} while (day > 31 || day < 1 || month > 12 || month < 1 || year < 1);
		}
	} 
	else if (n == 4) {
		cout << "������� ���������� ����� ������: "; cin >> month; cout << endl;
		if (month < 1 || month > 12) {
			do {
				cout << "������! ������� ��� ���." << endl << endl;
				cin >> month; cout << endl;
			} while (month < 1 || month > 12);
		}
	}
	else {
		cout << "������� ���: "; cin >> year; cout << endl;
		if (year < 1) {
			do {
				cout << "������! ������� ��� ���." << endl << endl;
				cin >> year; cout << endl;
			} while (year < 1);
		}
		cout << "������� ���������� ����� ��� � ����: "; cin >> days_number; cout << endl;
		if (days_number < 1 || days_number > 366) {
			do {
				cout << "������! ������ ��� ���." << endl << endl;
				cin >> days_number; cout << endl;
			} while (days_number < 1 || days_number > 366);
		}
	}
	
	switch (n) {
	case 1: {
		if (leapYear(year)) {
			cout << year << " ��� �������� ����������." << endl << endl;

			repeat();
		}
		else {
			cout << year << " ��� �� �������� ����������." << endl << endl;

			repeat();
		}
	} break;

	case 2: {
		cout << "���������� ����� ��� � ���� " << dayOfYear(day, month, year) << "." << endl << endl;

		repeat();
	} break;

	case 3: {
		cout << "������� ���� ��� �������� � ������� �� �� ����: " << endl;
		cin >> iday >> imonth >> iyear; cout << endl;
		if (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year) {
			do {
				cout << "������! ������ ���� ��� ���." << endl << endl;
				cin >> iday >> imonth >> iyear; cout << endl;
			} while (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year);
		}
		cout << "���������� ���� �� ������ ��� �������� " << countOfDayUntilBirthday(day, month, year, iday, imonth, iyear) << "." << endl << endl;

		repeat();
	} break;
	case 4: {
		cout << month << " ����� ��� " << yearsMonth(month) << "." << endl << endl;

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
	cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
	cout << "��� �����: "; cin >> choice; cout << endl;
	if (choice == 1) {
		main();
	}
	else {
		exit(0);
	}
}