#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../include/testing/suite.hpp"

using std::size_t;
using std::string;
using std::vector;

using std::cout;
using std::endl;

void TestSuite::run() {

    for (size_t index = 0; index < test_functions.size(); index++) {

        struct TestOutput output = test_functions[index]();

        if (output.result == true) {

            cout << output.function_name << ": PASS" << endl;

        } else {

            cout << output.function_name << ": FAIL" << endl;
            
        }

    }

}