#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../../../include/2015/Day_6/Probably_a_Fire_Hazard.hpp"

using std::stoi;
using std::string;
using std::stringstream;

struct OperationData parse_operation_string(string operation_string) {

    string operation;
    stringstream operation_string_stream(operation_string);

    getline(operation_string_stream, operation, ' ');

    if (operation.compare("turn") == 0) {
        getline(operation_string_stream, operation, ' ');
    }

    string start;
    string end;

    getline(operation_string_stream, start, ' ');
    getline(operation_string_stream, end, ' ');
    getline(operation_string_stream, end, ' ');

    string start_int;
    stringstream start_string_stream(start);

    getline(start_string_stream, start_int, ',');
    int start_0 = stoi(start_int);
    getline(start_string_stream, start_int, ',');
    int start_1 = stoi(start_int);

    string end_int;
    stringstream end_string_stream(end);

    getline(end_string_stream, end_int, ',');
    int end_0 = stoi(end_int);
    getline(end_string_stream, end_int, ',');
    int end_1 = stoi(end_int);

    struct OperationData operation_data = {
        operation,
        {start_0, start_1},
        {end_0, end_1}
    };

    return operation_data;

}

Lights::Lights(bool initial_state) {

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            lights[i][j] = initial_state;

        }

    }

}

void Lights::turn_on(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            lights[i][j] = true;

        }

    }

}

void Lights::toggle(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            lights[i][j] = !lights[i][j];

        }

    }

}

void Lights::turn_off(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            lights[i][j] = false;

        }

    }

}

int Lights::get_number_of_lit_lights() {

    int number_of_lit_lights = 0;

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            if (lights[i][j] == true) {
                number_of_lit_lights++;
            }

        }

    }

    return number_of_lit_lights;

}

LightsWithBrightnessControls::LightsWithBrightnessControls(int initial_state) {

    lights = new int*[1000];

    for (int i = 0; i < 1000; i++) {

        lights[i] = new int[1000];

        for (int j = 0; j < 1000; j++) {

            lights[i][j] = initial_state;

        }

    }

}

void LightsWithBrightnessControls::turn_on_ancient_nordic_elvish(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            lights[i][j]++;

        }

    }

}

void LightsWithBrightnessControls::toggle_ancient_nordic_elvish(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            lights[i][j] += 2;

        }

    }

}

void LightsWithBrightnessControls::turn_off_ancient_nordic_elvish(const int start[2], const int end[2]) {

    for (int i = start[0]; i <= end[0]; i++) {

        for (int j = start[1]; j <= end[1]; j++) {

            if (lights[i][j] > 0) {
                lights[i][j]--;
            }

        }

    }

}

int LightsWithBrightnessControls::calculate_total_brightness() {

    int brightness = 0;

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            brightness += lights[i][j];

        }

    }

    return brightness;

}