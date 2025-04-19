#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
	day dd;
	month mm;
	year yyyy;
};

bool operator<(const Date &date1, const Date &date2) {
	if (date1.yyyy != date2.yyyy) {
		return (date1.yyyy < date2.yyyy);
	}
	else if (date1.mm != date2.mm) {
		return (date1.mm < date2.mm);
	}
	else (date1.dd < date2.dd);
}
bool operator>(const Date& date1, const Date& date2) {
	if (date1.yyyy != date2.yyyy) {
		return (date1.yyyy > date2.yyyy);
	}
	else if (date1.mm != date2.mm) {
		return (date1.mm > date2.mm);
	}
	else (date1.dd > date2.dd);
}
bool operator==(const Date& date1, const Date& date2) {
	return (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd);
}

typedef int second;
typedef int minutes;
typedef int hours;

struct My_time {
	hours hh;
	minutes mm;
	second ss;	
};

My_time operator+(My_time& time1, My_time& time2) {
	My_time result = {};
	result.hh = time1.hh + time2.hh;
	result.mm = time1.mm + time2.mm;
	result.ss = time1.ss + time2.ss;

	if (result.ss >= 60) {
		result.ss -= 60;
		result.mm++;
	}
	if (result.mm >= 60) {
		result.mm -= 60;
		result.hh++;
	}
	
	return result;
}
My_time operator-(My_time& time1, My_time& time2) {
	My_time result = {};
	result.hh = time1.hh - time2.hh;
	result.mm = time1.mm - time2.mm;
	result.ss = time1.ss - time2.ss;

	if (result.ss < 0) {
		result.ss += 60;
		result.mm--;
	}
	if (result.mm < 0) {
		result.mm += 60;
		result.hh--;
	}

	return result;
}

int main() {
	setlocale(LC_ALL, "ru");

	Date date1 = { 7, 1, 1980 };
	Date date2 = { 7, 2, 1993 };
	Date date3 = { 7, 1, 1980 };

	if (date1 < date2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}

	if (date1 > date2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}

	if (date1 == date2) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}

	if (date1 == date3) {
		cout << "истина" << endl;
	}
	else {
		cout << "ложь" << endl;
	}


	My_time time1 = { 5, 25, 36 };
	My_time time2 = { 6, 17, 59 };
	My_time sum = time1 + time2;
	My_time diff = time1 - time2;
	cout << endl << "Операции с временем:" << endl;
	cout << "Сумма: " << sum.hh << "ч. " << sum.mm << "мин. " << sum.ss << "с." << endl;
	cout << "Разность: " << abs(diff.hh) << "ч. " << diff.mm << "мин. " << diff.ss << "с." << endl;
}