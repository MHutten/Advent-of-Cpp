#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;

int get_santas_destination(string directions);

int santa_enters_basement_at(string directions);

int follow_direction(char direction);

int main() {
    string directions;
    ifstream file ("input.txt");

    if (file.is_open()) {
        file >> directions;
    }

    cout << "Part 1 answer: " << get_santas_destination(directions) << '\n';
    cout << "Part 2 answer: " << santa_enters_basement_at(directions) << '\n';

}

int get_santas_destination(string directions) {
    int floor = 0;

    for (char direction : directions) {
        floor += follow_direction(direction);
    }

    return floor;
}

int follow_direction(char direction) {
    switch (direction) {
        case '(':
            return 1;
        case ')':
            return -1;
        default:
            return 0;
    }
}

int santa_enters_basement_at(string directions) {
    int floor = 0;
    int instruction_count = 0;

    for (char direction : directions) {
        floor += follow_direction(direction);

        instruction_count++;

        if (floor == -1) {
            break;
        }
    }

    return instruction_count;
}

