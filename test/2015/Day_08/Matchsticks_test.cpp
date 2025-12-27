#include "../../../include/2015/Day_08/Matchsticks.hpp"
#include "../../../include/testing/asserts.hpp"
#include "../../../include/testing/suite.hpp"

struct TestOutput test__calculate_memory_length__good_weather__quote_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_memory_length("\"\""), 0)
    };
    return output;
}

struct TestOutput test__calculate_memory_length__good_weather__quote_abc_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_memory_length("\"abc\""), 3)
    };
    return output;
}

struct TestOutput test__calculate_memory_length__good_weather__quote_aaa_backslash_quote_aaa_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_memory_length("\"aaa\\\"aaa\""), 7)
    };
    return output;
}

struct TestOutput test__calculate_memory_length__good_weather__quote_backslash_x27_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_memory_length("\"\\x27\""), 1)
    };
    return output;
}

struct TestOutput test__calculate_encoded_length__good_weather__quote_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_encoded_length("\"\""), 6)
    };
    return output;
}

struct TestOutput test__calculate_encoded_length__good_weather__quote_abc_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_encoded_length("\"abc\""), 9)
    };
    return output;
}

struct TestOutput test__calculate_encoded_length__good_weather__quote_aaa_backslash_quote_aaa_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_encoded_length("\"aaa\\\"aaa\""), 16)
    };
    return output;
}

struct TestOutput test__calculate_encoded_length__good_weather__quote_backslash_x27_quote() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_encoded_length("\"\\x27\""), 11)
    };
    return output;
}

class MatchsticksTestSuite : public TestSuite {

    public:

        MatchsticksTestSuite() {

            vector<TestFunction> temp_vector = {
                &test__calculate_memory_length__good_weather__quote_quote,
                &test__calculate_memory_length__good_weather__quote_abc_quote,
                &test__calculate_memory_length__good_weather__quote_aaa_backslash_quote_aaa_quote,
                &test__calculate_memory_length__good_weather__quote_backslash_x27_quote,
                &test__calculate_encoded_length__good_weather__quote_quote,
                &test__calculate_encoded_length__good_weather__quote_abc_quote,
                &test__calculate_encoded_length__good_weather__quote_aaa_backslash_quote_aaa_quote,
                &test__calculate_encoded_length__good_weather__quote_backslash_x27_quote
            };

            for (size_t index = 0; index < temp_vector.size(); index++) {

                test_functions.push_back(temp_vector[index]);

            }

        }

};

int main() {
    
    MatchsticksTestSuite suite;
    suite.run();

}