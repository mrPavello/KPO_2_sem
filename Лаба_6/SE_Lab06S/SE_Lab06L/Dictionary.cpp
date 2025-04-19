#include <iostream>
#include <iomanip>
#include <windows.h>
#include <array>

#include "Dictionary.h"
using namespace Dictionary;
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1
#error "Можно установить только один макрос из списка"
#endif

bool chek_create = false, chek_add = false, chek_get = false, chek_del = false, chek_upd = false, chek_print = false, chek_delete = false;
int num_dict = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	try {
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

		if (chek_create && chek_add && chek_get && chek_del && chek_upd && chek_print && chek_delete) {
#if defined TEST_DICTIONARY
			cout << "Было создано 2 словаря, каждый словарь содержит не менее 7 элементов, словари распечатаны с помощью функции print. Все функции успешно выполняются." << endl;
#endif
		}
		cout << endl;
	}
	catch (const char* e) {
		cout << e << endl;

	}

	return 0;
}

Instance* Dictionary::Create(const char name[DICTNAMEMAXSIZE], int size) {
	if (strlen(name) > DICTNAMEMAXSIZE) {
#ifdef TEST_CREATE_01
		cout << TEST_CREATE_01 << endl;
#endif
		throw THROW01;
	}

	if (size > DICTMAXSIZE) {
#ifdef TEST_CREATE_02
		cout << TEST_CREATE_02 << endl;
#endif
		throw THROW02;
	}

	Instance* inst = new Instance;
	inst->dictionary = new Entry[size];
	inst->max_size = size;
	strncpy_s(inst->name, name, DICTNAMEMAXSIZE);
	inst->size = 0;

	num_dict++;
	if (num_dict == 2) {
		chek_create = true;
	}
	return inst;
}

void Dictionary::AddEntry(Instance& inst, Entry ed) {
	if (inst.size > inst.max_size) {
#ifdef TEST_CREATE_03
		cout << TEST_CREATE_03 << endl;
#endif
		throw THROW03;
	}

	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == ed.id) {
#ifdef TEST_CREATE_04
			cout << TEST_CREATE_04 << endl;
#endif
			throw THROW04;
		}
	}

	inst.dictionary[inst.size] = ed;
	inst.size++;
	if (inst.size >= 7) {
		chek_add = true;
	}
}

void Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.size - 1; j++) {
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			chek_del = true;
			inst.size--;
			break;
		}
	}

	if (!chek_del) {
#ifdef TEST_CREATE_06
		cout << TEST_CREATE_06 << endl;
#endif
		throw THROW06;
	}
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == new_ed.id) {
#ifdef TEST_CREATE_08
			cout << TEST_CREATE_08 << endl;
#endif
			throw THROW08;
		}
	}

	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			inst.dictionary[i] = new_ed;
			chek_upd = true;
			break;
		}
	}

	if (!chek_upd) {
#ifdef TEST_CREATE_07
		cout << TEST_CREATE_07 << endl;
#endif
		throw THROW07;
	}
}

Entry Dictionary::GetEntry(Instance inst, int id) {
	Entry found_entry;
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			found_entry = inst.dictionary[i];
			chek_get = true;
			break;
		}
	}

	if (!chek_get) {
#ifdef TEST_CREATE_05
		cout << TEST_CREATE_05 << endl;
#endif
		throw THROW05;
	}
	return found_entry;
}

void Dictionary::Print(Instance inst) {
	cout << '\n' << setfill('-') << setw(9) << " " << inst.name << " " << setfill('-') << setw(9) << '\n';
	for (int j = 0; j < inst.size; j++) {
		cout << inst.dictionary[j].id << " " << inst.dictionary[j].name << endl;
	}
	cout << endl;
	chek_print = true;
}

void Dictionary::Delete(Instance& inst) {
	delete[] inst.dictionary;
	delete[] & inst;
	chek_delete = true;
}