#include "stdafx.h"
#include "Log.h"
#include <cstdarg>

namespace Log {
	LOG getlog(const wchar_t logfile[]) {
		LOG log;
		wcsncpy_s(log.logfile, PARM_MAX_SIZE, logfile, _TRUNCATE);

		log.stream = new ofstream(log.logfile);
		if (!log.stream->is_open()) {
			throw ERROR_THROW(112);
		}
		
		return log;
	}

	void WriteLine(LOG log, const char* c, ...) {
		va_list args;
		va_start(args, c);

		char buffer[1024];
		vsnprintf(buffer, sizeof(buffer), c, args);

		*log.stream << buffer << std::endl;

		va_end(args);
	}

	void WriteLine(LOG log, const wchar_t* c, ...) {
		va_list args;
		va_start(args, c);

		wchar_t buffer[1024];
		vswprintf_s(buffer, sizeof(buffer) / sizeof(wchar_t), c, args);

		char converted[1024];
		size_t converted_chars = 0;
		wcstombs_s(&converted_chars, converted, sizeof(converted), buffer, _TRUNCATE);

		if (log.stream) {
			*log.stream << converted << std::endl;
		}

		va_end(args);
	}

	void WriteLog(LOG log) {
		if (log.stream) {
			time_t now = time(nullptr);
			tm local_time;
			localtime_s(&local_time, &now);
			char timestamp[64];
			strftime(timestamp, sizeof(timestamp), "%d.%m.%y %H:%M:%S", &local_time);

			*log.stream << "Протокол: " << timestamp << std::endl;
		}
	}

	void WriteParm(LOG log, Parm::PARM parm) {
		if (log.stream) {
			*log.stream << "Параметры:" << endl;
			*log.stream << "-in:" << parm.in << endl;
			*log.stream << "-out:" << parm.out << endl;
			*log.stream << "-log:" << parm.log << endl;
		}
	}

	void WriteIn(LOG log, In::IN in) {
		if (log.stream) {
			*log.stream << "Исходные данные:" << endl;
			*log.stream << "Количество символов:	" << in.size << endl;
			*log.stream << "Проигнорировано:	" << in.ignor << endl;
			*log.stream << "Количество строк:	" << in.lines << endl;
		}
	}

	void WriteError(LOG log, Error::ERROR error) {
		if (log.stream) {
			if (error.inext.col > 0 && error.inext.line > 0) {
				*log.stream << "Ошибка " << error.id << ": " << error.message << ", строка " << error.inext.line << ", позиция " << error.inext.col << endl;
			}
			else {
				*log.stream << "Ошибка " << error.id << ": " << error.message << endl;
			}
		}
		else {
			if (error.inext.col > 0 && error.inext.line > 0) {
				cout << "Ошибка " << error.id << ": " << error.message << ", строка " << error.inext.line << ", позиция " << error.inext.col << endl;
			}
			else {
				cout << "Ошибка " << error.id << ": " << error.message << endl;
			}
		}
	}

	void Close(LOG& log) {
		if (log.stream) {
			log.stream->close();
			delete log.stream;
			log.stream = nullptr;
		}
	}
}

