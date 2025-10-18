#include <string>

using std::string;

int calculate_santas_final_destination(const string directions) {

    int floor = 0;
    int index = 0;

    while (true) {

        if (directions[index] == '(') {
            floor++;
        } else if (directions[index] == ')') {
            floor--;
        } else if (directions[index] == '\0') {
            return floor;
        }

        index++;

    }

}

int calculate_basement_entering_instruction_position(const string directions) {

    int floor = 0;
    int index = 0;

    while (true) {

        if (directions[index] == '(') {
            floor++;
        } else if (directions[index] == ')') {
            floor--;
        } else if (directions[index] == '\0') {
            return -1;
        }

        index++;

        if (floor < 0) {
            return index;
        }

    }

}