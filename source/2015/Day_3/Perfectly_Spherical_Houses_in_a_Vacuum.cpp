#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

void update_location(int location[2], char instruction) {

    if (instruction == '^') {

        location[1]++;

    } else if (instruction == 'v') {

        location[1]--;

    } else if (instruction == '>') {

        location[0]++;

    } else {

        location[0]--;

    }

}

void set_node(vector<array<int, 2>> * visited_houses, int position[2]) {

    for (size_t index = 0; index < visited_houses->size(); index++) {

        if (visited_houses->at(index)[0] == position[0] && visited_houses->at(index)[1] == position[1]) {

            return;

        }

    }

    visited_houses->push_back({position[0], position[1]});

}

int calculate_number_of_visited_houses(const string instructions) {

    vector<array<int, 2>> visited_houses = {{0, 0}};
    int current_location[] = {0, 0};

    for (size_t index = 0; index < instructions.size(); index++) {

        update_location(current_location, instructions[index]);
        set_node(&visited_houses, current_location);

    }

    return visited_houses.size();

}

int calculate_number_of_visited_houses_with_robo_santa(const string instructions) {

    vector<array<int, 2>> visited_houses = {{0, 0}};
    int santas_current_location[] = {0, 0};
    int robo_current_location[] =  {0, 0};
    bool it_is_santas_turn = true;

    for (size_t index = 0; index < instructions.size(); index++) {

        if(it_is_santas_turn) {

            update_location(santas_current_location, instructions[index]);
            set_node(&visited_houses, santas_current_location);

        } else {

            update_location(robo_current_location, instructions[index]);
            set_node(&visited_houses, robo_current_location);

        }

        it_is_santas_turn = !it_is_santas_turn;

    }

    return visited_houses.size();

}