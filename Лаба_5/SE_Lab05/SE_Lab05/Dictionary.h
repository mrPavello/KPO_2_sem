#pragma once
#include "stdafx.h"

#define DICTNAMEMAXSIZE 20 //макс размер имени словаря
#define DICTMAXSIZE 100 //макс ёмкость словаря
#define ENTRYNAMEMAXSIZE 30 //макс длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря"	
#define THROW02 "Create: превышен размер максимальной ёмеости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary {
	struct Entry {
		int id;
		char name[ENTRYNAMEMAXSIZE];
	};
	struct Instance {
		char name[DICTNAMEMAXSIZE];
		int max_size = DICTMAXSIZE;
		int size = 0;
		Entry* dictionary = new Entry[size];
	};
	int count_dict = 0;
	Instance* array_dict = new Instance[count_dict];

	Instance Create(const char name[DICTNAMEMAXSIZE], int size);
	void AddEntry(Instance& inst, Entry ed);
	void DelEntry(Instance& inst, int id);
	void UpdEntry(Instance& inst, int id, Entry new_ed);
	Entry GetEntry(Instance& inst, int id);
	void Print(Instance& inst);
	void Delete(Instance& inst);
}