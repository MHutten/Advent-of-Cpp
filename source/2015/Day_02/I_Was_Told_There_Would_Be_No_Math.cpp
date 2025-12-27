#include <algorithm>

using std::max;
using std::min;

int calculate_area_of_wrapping_paper(int length, int width, int height) {
    int  length_x_width = length * width;
    int  width_x_height = width * height;
    int  height_x_length = height * length;

    return 2 * (length_x_width + width_x_height + height_x_length) + min(min(length_x_width, width_x_height), height_x_length);
}

int calculate_ribbon_length(int length, int width, int height) {
    return (length + width + height - max(max(length, width), height)) * 2 + length * width * height;
}