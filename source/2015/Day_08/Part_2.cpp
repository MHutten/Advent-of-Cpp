#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../../include/2015/Day_08/Matchsticks.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main (int argc, char *argv[]) {

    vector<string> lines = read_lines(argv[1]);
    size_t difference = 0;

    for (size_t index = 0; index < lines.size(); index++) {
        difference += calculate_encoded_length(lines[index]) - lines[index].length();
    }

    cout << difference << endl;

    return 0;

}
