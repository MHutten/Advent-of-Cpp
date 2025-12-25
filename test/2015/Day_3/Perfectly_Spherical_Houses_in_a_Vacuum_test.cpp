#include "../../../include/2015/Day_3/Perfectly_Spherical_Houses_in_a_Vacuum.hpp"
#include "../../../include/testing/asserts.hpp"
#include "../../../include/testing/suite.hpp"

struct TestOutput test__calculate_number_of_visited_houses__good_weather__east() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses(">"), 2)
    };
    return output;
}

struct TestOutput test__calculate_number_of_visited_houses__good_weather__north_east_south_west() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses("^>v<"), 4)
    };
    return output;
}

struct TestOutput test__calculate_number_of_visited_houses__good_weather__north_south_repeated_5_times() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses("^v^v^v^v^v"), 2)
    };
    return output;
}

struct TestOutput test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_south() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses_with_robo_santa("^v"), 3)
    };
    return output;
}

struct TestOutput test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_east_south_west() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses_with_robo_santa("^>v<"), 3)
    };
    return output;
}

struct TestOutput test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_south_repeated_5_times() {
    struct TestOutput output = {
        __func__,
        assert_equal(calculate_number_of_visited_houses_with_robo_santa("^v^v^v^v^v"), 11)
    };
    return output;
}

class PerfectlySphericalHousesinaVacuumTestSuite : public TestSuite {

    public:

        PerfectlySphericalHousesinaVacuumTestSuite() {

            vector<TestFunction> temp_vector = {
                &test__calculate_number_of_visited_houses__good_weather__east,
                &test__calculate_number_of_visited_houses__good_weather__north_east_south_west,
                &test__calculate_number_of_visited_houses__good_weather__north_south_repeated_5_times,
                &test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_south,
                &test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_east_south_west,
                &test__calculate_number_of_visited_houses_with_robo_santa__good_weather__north_south_repeated_5_times
            };

            for (size_t index = 0; index < temp_vector.size(); index++) {

                test_functions.push_back(temp_vector[index]);

            }

        }

};

int main() {
    
    PerfectlySphericalHousesinaVacuumTestSuite suite;
    suite.run();

}