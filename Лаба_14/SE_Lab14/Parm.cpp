#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm {
	PARM getparm(int argc, _TCHAR* argv[]) {
		PARM p;
		bool isInputProvided = false;
		for (int i = 1; i < argc; ++i) {
			if (wcsstr(argv[i], PARM_IN)) {
				wcscpy_s(p.in, argv[i] + wcslen(PARM_IN));
				isInputProvided = true;
				if (wcslen(p.in) > PARM_MAX_SIZE) {
					throw ERROR_THROW(104);
				}
			}
			else if (wcsstr(argv[i], PARM_OUT)) {
				wcscpy_s(p.out, argv[i] + wcslen(PARM_OUT));

				if (wcslen(p.out) > PARM_MAX_SIZE) {
					throw ERROR_THROW(104);
				}
			}
			else if (wcsstr(argv[i], PARM_LOG)) {
				wcscpy_s(p.log, argv[i] + wcslen(PARM_LOG));

				if (wcslen(p.log) > PARM_MAX_SIZE) {
					throw ERROR_THROW(104);
				}
			}
		}
		if (!isInputProvided) {
			throw ERROR_THROW(100);
		}

		if (p.out[0] == '\0') {
			wcscpy_s(p.out, PARM_MAX_SIZE, p.in);
			wcsncat_s(p.out, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT_DEFAULT_EXT));
		}
		if (p.log[0] == '\0') {
			wcscpy_s(p.log, PARM_MAX_SIZE, p.in);
			wcsncat_s(p.log, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT));
		}
		return p;
	}
}
