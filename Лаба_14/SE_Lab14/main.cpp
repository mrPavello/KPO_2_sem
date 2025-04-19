#include "stdafx.h"
#include "Error.h" 
#include "Parm.h"
#include "Log.h"
#include "In.h"



int _tmain(int argc, _TCHAR* argv[]) {
    setlocale(LC_ALL, "ru");

    cout << "TECT Parm::getparm" << endl << endl;
    
    try {
        Parm::PARM parm = Parm::getparm(argc, argv);
        wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
    }
    catch (Error::ERROR e) {
        cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
    };

    cout << endl << "TECT In::getin" << endl << endl;

    try {
        Parm::PARM parm = Parm::getparm(argc, argv);
        In::IN in = In::getin(parm.in);
        for (int i = 0; i < in.size; i++) {
            cout << in.text[i];
        }
        cout << endl;
        cout << "Всего символов: " << in.size << endl;
        cout << "Всего строк: " << in.lines << endl;
        cout << "Пропущено: " << in.ignor << endl;
    }
    catch (Error::ERROR e) {
        cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
    };

    cout << endl << "TECT Log" << endl << endl;

    Log::LOG log = Log::INITLOG;
    try {
        Parm::PARM parm = Parm::getparm(argc, argv);
        log = Log::getlog(parm.log);
        
        Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
        Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm.in);
        Log::WriteIn(log, in);
        Log::Close(log);
    }
    catch (Error::ERROR e) {
        Log::WriteError(log, e);
    };


    return 0;
}
