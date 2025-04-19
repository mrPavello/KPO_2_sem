#include "stdafx.h"
#include "E:\2 семестр\КПО\Лаба_6\SE_Lab06_S\SE_Lab06L\Dictionary.h"
#pragma comment(lib, "E:\\2 семестр\\КПО\\Лаба_6\\SE_Lab06_S\\x64\\Debug\\SE_Lab06L.lib")

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1
#error "Можно установить только один макрос из списка"
#endif


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
#if defined TEST_DICTIONARY
		Dictionary::Instance* d1 = Dictionary::Create("Преподаватели", 8);
		Dictionary::Entry
			e1 = { 1, "Гладкий" },
			e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" },
			e4 = { 4, "Урбанович" },
			e5 = { 5, "Пацей" },
			e6 = { 6, "Белодед" },
			e7 = { 7, "Наркевич" },
			e8 = { 8, "Мащук" };

		Dictionary::AddEntry(*d1, e1);
		Dictionary::AddEntry(*d1, e2);
		Dictionary::AddEntry(*d1, e3);
		Dictionary::AddEntry(*d1, e4);
		Dictionary::AddEntry(*d1, e5);
		Dictionary::AddEntry(*d1, e6);
		Dictionary::AddEntry(*d1, e7);
		Dictionary::AddEntry(*d1, e8);

		Dictionary::Entry ex2 = Dictionary::GetEntry(*d1, 4);

		Dictionary::DelEntry(*d1, 2);
		Dictionary::Entry new_entry_1 = { 9, "Гурин" };
		Dictionary::UpdEntry(*d1, 3, new_entry_1);
		Dictionary::Print(*d1);


		Dictionary::Instance* d2 = Dictionary::Create("Студенты", 7);
		Dictionary::Entry
			s1 = { 1, "Иванов" },
			s2 = { 2, "Петров" },
			s3 = { 3, "Сидоров" },
			s4 = { 4, "Кисляк" },
			s5 = { 5, "Бовкунович" },
			s6 = { 6, "Ляшко" },
			s7 = { 7, "Печурин" };
		Dictionary::AddEntry(*d2, s1);
		Dictionary::AddEntry(*d2, s2);
		Dictionary::AddEntry(*d2, s3);
		Dictionary::AddEntry(*d2, s4);
		Dictionary::AddEntry(*d2, s5);
		Dictionary::AddEntry(*d2, s6);
		Dictionary::AddEntry(*d2, s7);
		Dictionary::Entry new_entry_3 = { 8, "Николаев" };
		Dictionary::UpdEntry(*d2, 3, new_entry_3);
		Dictionary::Print(*d2);

		Dictionary::Delete(*d1);
		Dictionary::Delete(*d2);

		
		cout << TEST_DICTIONARY << endl;
#endif
	}
	catch (const char* e) {
		cout << e << endl;

	}

	return 0;
}