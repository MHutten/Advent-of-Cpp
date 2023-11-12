#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::stringstream;
using std::vector;
using std::stoi;
using std::min;

int get_required_square_feet_of_wrapping_paper(string list_of_dimensions);

vector<int> parse_dimensions_string(string box_dimensions);

int calculate_square_feet_of_wrapping_paper_for_present(vector<int> box_dimensions);

int get_required_feet_of_ribbon(string list_of_dimensions);

int calculate_feet_of_ribbon_for_present(vector<int> box_dimensions);

int main() {
    string list_of_dimensions;
    ifstream file ("input.txt");

    for (string line; getline(file, line); ) {
        list_of_dimensions += line + '\n';
    }

    cout << "Part 1 answer: " << get_required_square_feet_of_wrapping_paper(list_of_dimensions) << '\n';
    cout << "Part 2 answer: " << get_required_feet_of_ribbon(list_of_dimensions) << '\n';

}

int get_required_square_feet_of_wrapping_paper(string list_of_dimensions) {
    int square_feet_wrapping_paper = 0;
    istringstream stream (list_of_dimensions);

    for (string line; getline(stream, line); ) {
        square_feet_wrapping_paper += calculate_square_feet_of_wrapping_paper_for_present(parse_dimensions_string(line));
    }

    return square_feet_wrapping_paper;
}

vector<int> parse_dimensions_string(string box_dimensions) {
    istringstream stream(box_dimensions);
    vector<int> output;

    for (string dimension; getline(stream, dimension, 'x'); ) {
        output.push_back(stoi(dimension));
    }

    return output;
}

int calculate_square_feet_of_wrapping_paper_for_present(vector<int> box_dimensions) {
    int l = box_dimensions[0];
    int w = box_dimensions[1];
    int h = box_dimensions[2];

    return 2*l*w + 2*w*h + 2*h*l + min({l*w, w*h, h*l});
}

int get_required_feet_of_ribbon(string list_of_dimensions) {
    int feet_of_ribbon = 0;
    istringstream stream (list_of_dimensions);

    for (string line; getline(stream, line); ) {
        feet_of_ribbon += calculate_feet_of_ribbon_for_present(parse_dimensions_string(line));
    }

    return feet_of_ribbon;
}

int calculate_feet_of_ribbon_for_present(vector<int> box_dimensions) {
    int l = box_dimensions[0];
    int w = box_dimensions[1];
    int h = box_dimensions[2];

    return l*w*h + min({2*l+2*w, 2*w+2*h, 2*h+2*l});
}