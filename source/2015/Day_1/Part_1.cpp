#include <iostream>
#include <fstream>

#include "../../../include/2015/Day_1/Not_Quite_Lisp.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;

int main (int argc, char *argv[]) {

    cout << calculate_santas_final_destination(read(argv[1])) << endl;

    return 0;

}
