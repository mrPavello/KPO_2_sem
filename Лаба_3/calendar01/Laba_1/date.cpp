#include "stdafx.h"

void date(int days_number, int year) {
    string month[] = { "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" };
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
        cout << "Дата: " << days_number << " " << month[i + 1] << " " << year << "." << endl;
        if (days_in_month[i == 1] && days_number == 14) {
            cout << "Сегодня День святого Валентина!" << endl;
        }
        else if (i + 1 == 1 && days_number == 23) {
            cout << "Сегодня День защитников Отечества!" << endl;
        }
        else if (i + 1 == 2 && days_number == 1) {
            cout << "Сегодня первый день весны!" << endl;
        }
        else if (i + 1 == 2 && days_number == 8) {
            cout << "Сегодня День женщин!" << endl;
        }
        else if (i + 1 == 3 && days_number == 2) {
            cout << "Сегодня День единения народов Беларуси и России!" << endl;
        }
        else if (i + 1 == 4 && days_number == 1) {
            cout << "Сегодня День труда!" << endl;
        }
        else if (i + 1 == 4 && days_number == 9) {
            cout << "Сегодня День победы!" << endl;
        }
        else if (i + 1 == 5 && days_number == 1) {
            cout << "Сегодня первый день лета!" << endl;
        }
        else if (i + 1 == 6 && days_number == 3) {
            cout << "Сегодня День Независимости Республики Беларусь!" << endl;
        }
        else if (i + 1 == 6 && days_number == 11) {
            cout << "Сегодня Всемирный день шоколада!" << endl;
        }
        else if (i + 1 == 7 && days_number == 3) {
            cout << "Сегодня День арбуза!" << endl;
        }
        else if (i + 1 == 7 && days_number == 31) {
            cout << "Сегодня последний день лета!" << endl;
        }
        else if (i + 1 == 8 && days_number == 1) {
            cout << "Сегодня День знаний!" << endl;
        }
        else if (i + 1 == 8 && days_number == 17) {
            cout << "Сегодня День народного единства!" << endl;
        }
        else if (i + 1 == 9 && days_number == 14) {
            cout << "Сегодня День матери!" << endl;
        }
        else if (i + 1 == 9 && days_number == 21) {
            cout << "Сегодня День отца!" << endl;
        }
        else if (i + 1 == 10 && days_number == 2) {
            cout << "Сегодня День памяти!" << endl;
        }
        else if (i + 1 == 11 && days_number == 25) {
            cout << "Сегодня Рождество Христово!" << endl;
        }
        else if (i + 1 == 11 && days_number == 31) {
            cout << "Сегодня последний день года!" << endl;
        }
        else {
            cout << "Сегодня нет праздника.";
        }
    } 
    else {
        cout << "Дата: " << days_number << " " << month[0] << " " << year << "." << endl;
        if (days_number == 1) {
            cout << "Сегодня Новый Год!";
        }
        else if (days_number == 7) {
            cout << "Сегодня Рождество Иисуса Христа!";
        }
        else if (days_number == 5) {
            cout << "Сегодня День работников социальной защиты!";
        }
        else if (days_number == 19) {
            cout << "Сегодня День спасателя!";
        }
        else {
            cout << "Сегодня нет праздника." << endl;
        }
    }
}