#include "stdafx.h"

void date(int days_number, int year) {
    string month[] = { "������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "�������", "������", "�������" };
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = 0;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] += 1;
    }
    if (days_number > days_in_month[0]) {
        int i = 0;
        for (i; i < size(days_in_month); i++) {
            days_number -= days_in_month[i];
            if (days_number <= days_in_month[i + 1]) {
                break;
            }
        }
        cout << "����: " << days_number << " " << month[i + 1] << " " << year << "." << endl;
        if (days_in_month[i == 1] && days_number == 14) {
            cout << "������� ���� ������� ���������!" << endl;
        }
        else if (i + 1 == 1 && days_number == 23) {
            cout << "������� ���� ���������� ���������!" << endl;
        }
        else if (i + 1 == 2 && days_number == 1) {
            cout << "������� ������ ���� �����!" << endl;
        }
        else if (i + 1 == 2 && days_number == 8) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 3 && days_number == 2) {
            cout << "������� ���� �������� ������� �������� � ������!" << endl;
        }
        else if (i + 1 == 4 && days_number == 1) {
            cout << "������� ���� �����!" << endl;
        }
        else if (i + 1 == 4 && days_number == 9) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 5 && days_number == 1) {
            cout << "������� ������ ���� ����!" << endl;
        }
        else if (i + 1 == 6 && days_number == 3) {
            cout << "������� ���� ������������� ���������� ��������!" << endl;
        }
        else if (i + 1 == 6 && days_number == 11) {
            cout << "������� ��������� ���� ��������!" << endl;
        }
        else if (i + 1 == 7 && days_number == 3) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 7 && days_number == 31) {
            cout << "������� ��������� ���� ����!" << endl;
        }
        else if (i + 1 == 8 && days_number == 1) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 8 && days_number == 17) {
            cout << "������� ���� ��������� ��������!" << endl;
        }
        else if (i + 1 == 9 && days_number == 14) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 9 && days_number == 21) {
            cout << "������� ���� ����!" << endl;
        }
        else if (i + 1 == 10 && days_number == 2) {
            cout << "������� ���� ������!" << endl;
        }
        else if (i + 1 == 11 && days_number == 25) {
            cout << "������� ��������� ��������!" << endl;
        }
        else if (i + 1 == 11 && days_number == 31) {
            cout << "������� ��������� ���� ����!" << endl;
        }
        else {
            cout << "������� ��� ���������.";
        }
    } 
    else {
        cout << "����: " << days_number << " " << month[0] << " " << year << "." << endl;
        if (days_number == 1) {
            cout << "������� ����� ���!";
        }
        else if (days_number == 7) {
            cout << "������� ��������� ������ ������!";
        }
        else if (days_number == 5) {
            cout << "������� ���� ���������� ���������� ������!";
        }
        else if (days_number == 19) {
            cout << "������� ���� ���������!";
        }
        else {
            cout << "������� ��� ���������." << endl;
        }
    }
}