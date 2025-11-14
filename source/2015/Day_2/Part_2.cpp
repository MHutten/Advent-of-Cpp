#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../../../include/2015/Day_2/I_Was_Told_There_Would_Be_No_Math.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::stringstream;
using std::vector;

int main (int argc, char *argv[]) {

    vector<string> lines = read_lines(argv[1]);
    int ribbon_length = 0;
    string length;
    string width;
    string height;

    for (size_t index = 0; index < lines.size(); index++) {
        
        stringstream string_stream(lines.at(index));

        getline(string_stream, length, 'x');
        getline(string_stream, width, 'x');
        getline(string_stream, height);

        ribbon_length += calculate_ribbon_length(stoi(length), stoi(width), stoi(height));

    }

    cout << ribbon_length << endl;

    return 0;

}
