#include <string>

using std::string;

bool fail();

bool assert_equal(int first, int second);

bool assert_equal(string first, string second);

bool assert_is_true(bool condition);

bool assert_is_false(bool condition);