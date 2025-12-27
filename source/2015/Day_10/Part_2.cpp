#include <iostream>
#include <fstream>
#include <string>

#include "../../../include/2015/Day_10/Elves_Look_Elves_Say.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {

    string digits = argv[1];

    for (int iteration = 0; iteration < 50; iteration++) {
        digits = look_and_say(digits);
    }

    cout << digits.length() << endl;

    return 0;

}