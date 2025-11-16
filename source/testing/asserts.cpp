#include <string>

using std::string;

bool fail() {
    return false;
}

bool assert_equal(int first, int second) {

    if (first == second) {

        return true;

    } else {

        return false;

    }

}

bool assert_equal(string first, string second) {

    int index = 0;

    while (true) {
        
        if (first[index] != second[index]) {

            return false;

        }

        if (first[index] == '\0') {

            break;

        }

        index++;

    }

    return true;

}

bool assert_is_true(bool condition) {

    return condition;

}

bool assert_is_false(bool condition) {

    return !condition;

}