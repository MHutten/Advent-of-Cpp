#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../../../include/2015/Day_6/Probably_a_Fire_Hazard.hpp"
#include "../../../include/file.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main (int argc, char *argv[]) {

    vector<string> lines = read_lines(argv[1]);
    Lights lights(false);

    for (size_t index = 0; index < lines.size(); index++) {

        struct OperationData operation_data = parse_operation_string(lines[index]);

        if (operation_data.operation.compare("on") == 0) {
            lights.turn_on(operation_data.start, operation_data.end);
        } else if (operation_data.operation.compare("toggle") == 0) {
            lights.toggle(operation_data.start, operation_data.end);
        } else {
            lights.turn_off(operation_data.start, operation_data.end);
        }

    }

    cout << lights.get_number_of_lit_lights() << endl;

    return 0;
}
