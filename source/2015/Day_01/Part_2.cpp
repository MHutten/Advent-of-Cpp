#include <iostream>
#include <fstream>

#include "../../../include/2015/Day_01/Not_Quite_Lisp.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;

int main (int argc, char *argv[]) {

    cout << calculate_basement_entering_instruction_position(read(argv[1])) << endl;

    return 0;

}
