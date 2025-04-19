#include "stdafx.h"
#include "Dictionary.h"

using namespace Dictionary;
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "ru");

	

	try {
		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
		Dictionary::Entry e1 = { 1, "Гладкий" },
			e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" },
			e4 = { 4, "Урбанович" },
			e5 = { 5, "Пацей" };
		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
		Dictionary::AddEntry(d1, e5);
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry new_entry_1 = { 6, "Гурин" };
		Dictionary::UpdEntry(d1, 3, new_entry_1);
		Dictionary::Print(d1);
		Dictionary::Delete(d1);

		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" },
			s2 = { 2, "Петров" },
			s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry new_entry_3 = { 3, "Николаев" };
		Dictionary::UpdEntry(d2, 3, new_entry_3);
		Dictionary::Print(d2);

		
		Dictionary::Delete(d2);
	}
	catch (char *e) {
		cout << e << endl;
	};
	system("pause");
	return 0;
}


Dictionary::Instance Dictionary::Create(const char name[DICTNAMEMAXSIZE], int size) {
	Dictionary::Instance inst;
	inst.size = size;
	memcpy(inst.name, name, sizeof(name));
	count_dict++;
	return inst;
}

void Dictionary::AddEntry(Dictionary::Instance& inst, Dictionary::Entry ed) {
	inst.size++;
	inst.dictionary[inst.size] = ed;
}

void Dictionary::DelEntry(Dictionary::Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.size - 1; j++) {
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.size--;
			break;
		}
	}
}

void Dictionary::UpdEntry(Dictionary::Instance& inst, int id, Entry new_ed) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			inst.dictionary[i] = new_ed;
		}
	}
}

Dictionary::Entry Dictionary::GetEntry(Dictionary::Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			return inst.dictionary[i];
		}
	}
}

void Dictionary::Print(Dictionary::Instance& inst) {
	cout << setfill('-') << setw(9) << inst.name << setfill('-') << setw(9) << endl;
	for (int j = 0; j < inst.size; j++) {
		cout << inst.dictionary->id << " " << inst.dictionary->name << endl;
	}
	cout << endl;
}

void Dictionary::Delete(Dictionary::Instance& inst) {
	delete[] inst.dictionary;
}