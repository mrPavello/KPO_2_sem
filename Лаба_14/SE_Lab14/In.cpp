#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <fstream>

namespace In {
    IN getin(wchar_t infile[]) {
        IN input;
        input.text = new unsigned char[IN_MAX_LEN_TEXT];
        wifstream file(infile);

        if (!file.is_open()) {
            throw ERROR_THROW(110);
        }

        wchar_t current_char;
        int position = 0;
        int acceptable_count = 0;

        while (file.get(current_char)) {
            position++;
            input.size++;

            if (current_char >= 0 && current_char < 256) {
                switch (input.code[current_char]) {
                case IN::T:
                    input.text[acceptable_count++] = static_cast<unsigned char>(current_char);
                    break;
                case IN::I:
                    input.ignor++;
                    input.size--;
                    break;
                case IN::F:
                    throw ERROR_THROW_IN(111, input.lines, position);
                default:
                    input.text[acceptable_count++] = static_cast<unsigned char>(input.code[current_char]);
                    break;
                }
            }
            else {
                throw ERROR_THROW_IN(111, input.lines, position);
            }

            if (current_char == IN_CODE_ENDL) {
                position = 0;
                input.lines++;
            }
        }

        file.close();
        return input;
    }
}
