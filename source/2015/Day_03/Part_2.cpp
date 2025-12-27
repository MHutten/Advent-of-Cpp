#include <iostream>
#include <fstream>

#include "../../../include/2015/Day_03/Perfectly_Spherical_Houses_in_a_Vacuum.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;

int main (int argc, char *argv[]) {

    cout << calculate_number_of_visited_houses_with_robo_santa(read(argv[1])) << endl;

    return 0;

}
