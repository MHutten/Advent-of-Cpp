#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::vector;
using std::stoi;
using std::min;

int main() {

    ifstream dimensions_list ("input.txt");
    int square_feet_wrapping_paper = 0;
    string dimension;
    vector<int> box_dimensions_vector;
    int l;
    int w;
    int h;

    for (string box_dimensions; getline(dimensions_list, box_dimensions); ) {
        stringstream box_dimensions_stream(box_dimensions);

        while (getline(box_dimensions_stream, dimension, 'x')) {
            box_dimensions_vector.push_back(stoi(dimension));
        }

        l = box_dimensions_vector[0];
        w = box_dimensions_vector[1];
        h = box_dimensions_vector[2];
        box_dimensions_vector.clear();

        std::initializer_list<int> face_areas {l * w, w * h, h * l};

        square_feet_wrapping_paper += 2 * l * w + 2 * w * h + 2 * h * l + min(face_areas);
    }

    cout << square_feet_wrapping_paper;

}