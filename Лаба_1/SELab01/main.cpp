#include "stdafx.h"

using namespace std;

int leapYear(int year);
int dayOfYear(int day, int month, int year);
int countOfDayUntilBirthday(int day, int month, int year, int iday, int imonth, int iyear);

int main() {
	setlocale(LC_ALL, "ru");

	unsigned int n, day, month, year, iday, imonth, iyear, choice;

	cout << "�������� ��������:" << endl;
	cout << "1. ����������, �������� �� �������� ��� ����������." << endl;
	cout << "2. ��������� ���������� ����� ��������� ��� � ����." << endl;
	cout << "3. ���������, ������� ���� �������� �� ���������� ������ ��� ��������." << endl;
	cout << "��� �����: "; cin >> n;

	if (n < 1 || n > 3) {
		cout << "������! ����� �������� ������� ��������." << endl;
		main();
	}

	cout << "�������! ������ ������� ���� � ������� �� �� ����: " << endl;
	cin >> day >> month >> year; cout << endl;
	if (day > 31 || day < 1 || month > 12 || month < 1 || year > 9999 || year < 1) {
		do {
			cout << "������! ������ ���� ��� ���." << endl << endl;
			cin >> day >> month >> year; cout << endl;
		} while (day > 31 || day < 1 || month > 12 || month < 1 || year > 9999 || year < 1);
	}

	switch (n) {
	case 1: {
		if (leapYear(year)) {
			cout << year << " ��� �������� ����������." << endl << endl;

			cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
			cout << "��� �����: "; cin >> choice; cout << endl;
			if (choice == 1) {
				main();
			}
			else if (choice == 0) {
				exit(0);
			}
			else {
				do {
					cout << "������� ���������� �����!" << endl << endl;
					cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
					cout << "��� �����: "; cin >> choice; cout << endl;
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
			cout << year << " ��� �� �������� ����������." << endl << endl;

			cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
			cout << "��� �����: "; cin >> choice; cout << endl;
			if (choice == 1) {
				main();
			}
			else if (choice == 0) {
				exit(0);
			}
			else {
				do {
					cout << "������� ���������� �����!" << endl << endl;
					cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
					cout << "��� �����: "; cin >> choice; cout << endl;
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
		cout << "���������� ����� ��� � ���� " << dayOfYear(day, month, year) << "." << endl << endl;

		cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
		cout << "��� �����: "; cin >> choice; cout << endl;
		if (choice == 1) {
			main();
		}
		else if (choice == 0) {
			exit(0);
		}
		else {
			do {
				cout << "������� ���������� �����!" << endl << endl;
				cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
				cout << "��� �����: "; cin >> choice; cout << endl;
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
		cout << "������� ���� ��� �������� � ������� �� �� ����: " << endl;
		cin >> iday >> imonth >> iyear; cout << endl;
		if (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year) {
			do {
				cout << "������! ������ ���� ��� ���." << endl << endl;
				cin >> iday >> imonth >> iyear; cout << endl;
			} while (iday > 31 || iday < 1 || imonth > 12 || imonth < 1 || iyear > year + 1 || iyear < year);
		}
		cout << "���������� ���� �� ������ ��� �������� " << countOfDayUntilBirthday(day, month, year, iday, imonth, iyear) << "." << endl << endl;

		cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
		cout << "��� �����: "; cin >> choice; cout << endl;
		if (choice == 1) {
			main();
		}
		else if (choice == 0) {
			exit(0);
		}
		else {
			do {
				cout << "������� ���������� �����!" << endl << endl;
				cout << "������ ����������? ���� �� - ������� 1, ���� ��� - 0" << endl;
				cout << "��� �����: "; cin >> choice; cout << endl;
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