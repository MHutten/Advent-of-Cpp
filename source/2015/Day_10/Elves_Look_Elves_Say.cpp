#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string integer_to_ascii(int integer) {

    int digit_count = 1;

    if (integer > 0) {
        digit_count = (int) log10(integer) + 1;
    }

    int remainder = integer;
    string ascii = "";

    for (int index = 0; index < digit_count; index++) {

        ascii += (char) (remainder / (int) pow(10, digit_count - 1 - index)) + 48;
        remainder %= (int) pow(10, digit_count - 1 - index);

    }

    return ascii;

}

string look_and_say(string input) {

    size_t length = 1;
    string output = "";
    size_t string_index = 0;

    while (input[string_index] != '\0') {

        if (!isdigit(input[string_index])) {
            cout << "'" << input[string_index] << "' is not a digit" << endl;
            exit(1);
        }

        char digit = input[string_index];
        int count = 1;

        while (input[string_index + count] == digit) {
            count++;
        }

        output += integer_to_ascii(count) + digit;
        string_index += count;

    }

    return output;

}