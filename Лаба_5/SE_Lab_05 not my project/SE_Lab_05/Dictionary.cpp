#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <locale>
#include <windows.h>
#include "Dictionary.h"

using namespace std;
using namespace Dictionary;

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1
#error "Можно установить только один макрос из списка"
#endif

bool Dict = false, s_Prep = false, s_Stud = false, fCreate = false, fAdd = false, fDel = false, fUpd = false, fGet = false, fDelE = false;

namespace Dictionary
{
    Instance* Create(const char name[DICTNAMEMAXSIZE], int size)
    {
        Instance* inst = new Instance;
        inst->dictionary = new Entry[size];
        if (size > DICTMAXSIZE)
        {
            cout << THROW02 << endl;
#ifdef TEST_CREATE_02
            throw TEST_CREATE_02;
#endif


        }


        inst->max_size = size;
        if (strlen(name) > DICTNAMEMAXSIZE)
        {
            cout << THROW01 << endl;
#ifdef TEST_CREATE_01
            throw TEST_CREATE_01;
#endif
        }
        strncpy(inst->name, name, DICTNAMEMAXSIZE);
        inst->size = 0;

        return inst;
    }

    void AddEntry(Instance& inst, Entry ed)
    {
        if (inst.size >= inst.max_size)
        {
            cout << THROW03 << endl;
#ifdef TEST_ADDENTRY_03
            throw TEST_ADDENTRY_03;
#endif
        }

        for (int i = 0; i < inst.size; i++)
        {
            if (inst.dictionary[i].id == ed.id)
            {
                cout << THROW04 << endl;
#ifdef TEST_ADDENTRY_04
                throw TEST_ADDENTRY_04;
#endif
            }
            fAdd = true;
        }

        inst.dictionary[inst.size] = ed;
        inst.size++;
        fCreate = true;
    }

    void DelEntry(Instance& inst, int id)
    {
        bool flag = false;
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id)
            {
                flag = true;
                for (int j = i; j < (inst.size - 1); j++)
                {
                    inst.dictionary[j] = inst.dictionary[j + 1];
                }
            }
        }
        if (!flag)
        {
            cout << THROW06 << endl;
#ifdef TEST_GETENTRY_06
            throw TEST_GETENTRY_06;
#endif
        }
        inst.size--;
        fDelE = true;
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed)
    {
        bool flag = false, find = false;
        int value = -1;
        for (int i = 0; i < inst.size; i++)
        {
            if (inst.dictionary[i].id == id) {
                find = true;
            }
        }
        if (!find)
        {
            cout << THROW07 << endl;
#ifdef TEST_UPDENTRY_07
            throw TEST_UPDENTRY_07;
#endif
        }
        for (int i = 0; i < inst.size; i++)
        {
            if (inst.dictionary[i].id == new_ed.id)
            {
                cout << THROW08 << endl;
#ifdef TEST_UPDENTRY_08
                throw TEST_UPDENTRY_08;
#endif
            }
            if (inst.dictionary[i].id == id)
            {
                flag = true;
                value = i;
            }
        }
        if (value != -1)
            inst.dictionary[value] = new_ed;
        else
        {
            cout << "Непредвиденная ошибка, введено недопустимое место в структуре" << endl;
            exit(-1);
        }
        fUpd = true;
    }

    Entry GetEntry(Instance inst, int id)
    {
        Entry word;
        bool flag = false;
        for (int i = 0; i < inst.size; i++)
        {
            if (inst.dictionary[i].id == id)
            {
                flag = true;
                word = inst.dictionary[i];
            }
        }
        if (!flag)
        {
            cout << THROW06 << endl;
#ifdef TEST_GETENTRY_06
            throw TEST_GETENTRY_06;
#endif
        }
        fGet = true;
        return word;
    }

    void Print(Instance d)
    {
        cout << "__________" << d.name << "__________" << endl;
        for (int i = 0; i < (d.size); i++)
        {
            cout << d.dictionary[i].id << " " << d.dictionary[i].name << endl;
        }
        cout << "__________________________________" << endl;
        if (d.size > 6)
            s_Prep = true;
        if (d.size > 6)
            s_Stud = true;


    }

    void Delete(Instance& d)
    {
        delete[] d.dictionary;
        delete[] & d;
        fDel = true;
    }
}

int main(int argc, _TCHAR* ARGV[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try
    {
        Instance* d1 = Create("Преподаватели", 7); //
        Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" }, e6 = { 6, "Якубенко" }, e7 = { 7, "Север" }; //
        AddEntry(*d1, e1); //
        AddEntry(*d1, e2); //
        AddEntry(*d1, e3); //
        AddEntry(*d1, e4);
        AddEntry(*d1, e5);
        AddEntry(*d1, e6);
        AddEntry(*d1, e7);//
        Entry ex2 = GetEntry(*d1, 4);
        DelEntry(*d1, 2);
        Entry newentry1 = { 8, "Гурин" }, e9 = { 9, "Архипенко" };
        AddEntry(*d1, e9);
        UpdEntry(*d1, 3, newentry1);
        Print(*d1);

        Instance* d2 = Create("Студенты", 7);
        Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" }, s4 = { 4, "Галкин" }, s5 = { 5, "Зайцев" }, s6 = { 6, "Смолин" }, s7 = { 7, "Кухаренко" };
        AddEntry(*d2, s1);
        AddEntry(*d2, s2);
        AddEntry(*d2, s3);
        AddEntry(*d2, s4);
        AddEntry(*d2, s5);
        AddEntry(*d2, s6);
        AddEntry(*d2, s7);
        Entry newentry3 = { 8, "Николаев" };
        UpdEntry(*d2, 3, newentry3);
        Print(*d2);
        Delete(*d1);
        Delete(*d2);
        if (s_Prep && s_Stud && fCreate && fAdd && fDel && fUpd && fGet && fDelE)
        {
#if defined TEST_DICTIONARY
            cout << "Во время работы программы вызваны словари Преподаватели и Студенты, имеющие как минимум по 7 элементов, были распечатаны" << endl;
#endif
        }
    }
    catch (const char* e)
    {
        cout << e << endl;
    };

    system("pause");
    return 0;
}

