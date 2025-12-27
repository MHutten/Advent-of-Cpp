#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../../include/2015/Day_05/Doesnt_He_Have_Intern-Elves_For_This.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main (int argc, char *argv[]) {

    vector<string> lines = read_lines(argv[1]);
    int number_of_nice_strings = 0;

    for (size_t index = 0; index < lines.size(); index++) {

        number_of_nice_strings += is_nice_now(lines[index]);
        
    }

    cout << number_of_nice_strings << endl;

    return 0;
}
