#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int calculate_memory_length(string source) {

    int length = 0;
    size_t index = 1;

    while (source[index + 1] != '\0') {

        if (source[index] != '\\') {
            index++; 
        } else if (source[index + 1] == '\\' || source[index + 1] == '\"') {
            index += 2;
        } else if (source[index + 1] == 'x' && isxdigit(source[index + 2]) && isxdigit(source[index + 3])) {
            index += 4;
        } else {
            cout << "Unexpected next character '" << source[index + 1] << "', '" << source[index + 2] << "' and '" << source[index + 3] << "' in source \"" << source << "\"" << endl;
            exit(-1);
        }

        length++;

    }

    return length;

}

int calculate_encoded_length(string source) {

    int length = 6;
    size_t index = 1;

    for (size_t index = 1; index < source.length() - 1; index++) {

        if (source[index] == '\"' || source[index] == '\\') {
            length += 2;
        } else {
            length++;
        }

    }

    return length;

}