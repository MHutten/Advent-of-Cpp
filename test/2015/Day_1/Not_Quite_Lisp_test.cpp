#include "../../../include/2015/Day_1/Not_Quite_Lisp.hpp"
#include "../../../include/testing/asserts.hpp"
#include "../../../include/testing/suite.hpp"

struct TestOutput test__calculate_santas_final_destination__good_weather__up_up_down_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("(())"), 0)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__up_down_up_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("()()"), 0)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__up_up_up() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("((("), 3)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__up_up_down_up_up_down_up() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("(()(()("), 3)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__down_down_up_up_up_up_up() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("))((((("), 3)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__up_down_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("())"), -1)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__down_down_up() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination("))("), -1)
    };
    return output;
}

struct TestOutput test__calculate_santas_final_destination__good_weather__down_down_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination(")))"), -3)
    };
    return output;        
}

struct TestOutput test__calculate_santas_final_destination__good_weather__down_up_down_down_up_down_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_santas_final_destination(")())())"),-3)
    };
    return output;
}

struct TestOutput test__calculate_basement_entering_instruction_position__good_weather__down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_basement_entering_instruction_position(")"), 1)
    };
    return output;
}

struct TestOutput test__calculate_basement_entering_instruction_position__good_weather__up_down_up_down_down() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_basement_entering_instruction_position("()())"), 5)
    };
    return output;
}

class NotQuiteLispTestSuite : public TestSuite {

    public:

        NotQuiteLispTestSuite() {

            vector<TestFunction> temp_vector = {
                &test__calculate_santas_final_destination__good_weather__up_up_down_down,
                &test__calculate_santas_final_destination__good_weather__up_down_up_down,
                &test__calculate_santas_final_destination__good_weather__up_up_up,
                &test__calculate_santas_final_destination__good_weather__up_up_down_up_up_down_up,
                &test__calculate_santas_final_destination__good_weather__down_down_up_up_up_up_up,
                &test__calculate_santas_final_destination__good_weather__up_down_down,
                &test__calculate_santas_final_destination__good_weather__down_down_up,
                &test__calculate_santas_final_destination__good_weather__down_down_down,
                &test__calculate_santas_final_destination__good_weather__down_up_down_down_up_down_down,
                &test__calculate_basement_entering_instruction_position__good_weather__down,
                &test__calculate_basement_entering_instruction_position__good_weather__up_down_up_down_down
            };

            for (size_t index = 0; index < temp_vector.size(); index++) {

                test_functions.push_back(temp_vector[index]);

            }

        }

};

int main() {
    
    NotQuiteLispTestSuite suite;
    suite.run();

}