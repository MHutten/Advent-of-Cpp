#include <string>

using std::string;

bool is_vowel(char character) {
    string vowels = "aeiou";

    for (size_t index = 0; index < vowels.size(); index++) {

        if (character == vowels[index]) {
            return true;
        }

    }

    return false;
}

bool is_naughty_substring(string substring) {
    string naughty_substrings[] = {"ab", "cd", "pq", "xy"};

    for (size_t index = 0; index < 4; index++) {

        if (substring.compare(naughty_substrings[index]) == 0) {
            return true;
        }

    }

    return false;
}

bool occurs_at_least_twice(string sub, string sup, int start) {

    int sup_index = start;

    for (size_t sup_index = start; sup_index < sup.size(); sup_index++) {

        bool is_match = true;

        for (size_t sub_index = 0; sub_index < sub.size(); sub_index++) {

            if (sub[sub_index] != sup[sup_index + sub_index]) {
                is_match = false;
            }

        }

        if (is_match) {
            return true;
        }

    }

    return false;

}

bool is_nice(string input_string) {
    
    bool contains_consecutives = false;
    int vowel_count = 0;

    if (is_vowel(input_string[0])) {
        vowel_count++;
    }
    
    for (size_t index = 1; index < input_string.size(); index++) {

        if (is_naughty_substring(input_string.substr(index-1, 2))) {
            return false;
        }

        if (is_vowel(input_string[index])) {
            vowel_count++;
        }

        if (input_string[index-1] == input_string[index]) {
            contains_consecutives = true;
        }

    }

    return contains_consecutives && (vowel_count > 2);

}

bool is_nice_now(string input_string) {

    bool contains_multiple_non_overlapping_duplicate_pairs = false;
    bool contains_repeating_character_seperated_by_one_character = false;

    if (occurs_at_least_twice(input_string.substr(0, 2), input_string, 2)) {
        contains_multiple_non_overlapping_duplicate_pairs = true;
    }

    for (size_t index = 2; index < input_string.size(); index++) {

        if (occurs_at_least_twice(input_string.substr(index-1, 2), input_string, index+1)) {
            contains_multiple_non_overlapping_duplicate_pairs = true;
        }

        if (input_string[index - 2] == input_string[index]) {
            contains_repeating_character_seperated_by_one_character = true;
        }

        if (contains_multiple_non_overlapping_duplicate_pairs && contains_repeating_character_seperated_by_one_character) {
            return true;
        }

    }

    return false;

}