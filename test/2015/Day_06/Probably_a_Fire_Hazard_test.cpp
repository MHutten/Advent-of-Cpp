#include "../../../include/2015/Day_06/Probably_a_Fire_Hazard.hpp"
#include "../../../include/testing/asserts.hpp"
#include "../../../include/testing/suite.hpp"

class TestLights : public Lights {

    public:

        using Lights::Lights;

        bool get_light_state(size_t x, size_t y) {

            return lights[x][y];

        }

        void set_light(size_t x, size_t y, bool value) {

            lights[x][y] = value;

        }

};

class TestLightsWithBrightnessControls : public LightsWithBrightnessControls {

    public:

        using LightsWithBrightnessControls::LightsWithBrightnessControls;

        int get_light_brightness(size_t x, size_t y) {

            return lights[x][y];

        }

};

struct TestOutput test__turn_on__good_weather__0_0_trough_999_999() {

    TestLights lights(false);

    int start[] = {0, 0};
    int end[] = {999, 999};

    lights.turn_on(start, end);

    bool output_bool = assert_equal(lights.get_number_of_lit_lights(), 1000000);

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            output_bool = output_bool && assert_is_true(lights.get_light_state(i, j));

        }

    }

    struct TestOutput output = {
        __func__,
        output_bool
    };
    return output;
}

struct TestOutput test__toggle__good_weather__0_0_trough_999_0() {

    TestLights lights(false);

    for (int index = 0; index < 1000; index++) {

        if (index % 2 == 0) {
            lights.set_light(index, 0, true);
        }

    }

    int start[] = {0, 0};
    int end[] = {999, 0};

    lights.toggle(start, end);

    bool output_bool = assert_equal(lights.get_number_of_lit_lights(), 500);

    for (int index = 0; index < 1000; index++) {

        if (index % 2 == 0) {
            output_bool = output_bool && assert_is_false(lights.get_light_state(index, 0));
        } else {
            output_bool = output_bool && assert_is_true(lights.get_light_state(index, 0));
        }

        for (int j = 1; j < 1000; j++) {

            output_bool = output_bool && assert_is_false(lights.get_light_state(index, j));

        }

    }

    struct TestOutput output = {
        __func__,
        output_bool
    };
    return output;
}

struct TestOutput test__turn_off__good_weather__499_499_trough_500_500() {

    TestLights lights(true);

    int start[] = {499, 499};
    int end[] = {500, 500};

    lights.turn_off(start, end);

    bool output_bool = assert_equal(lights.get_number_of_lit_lights(), 999996);

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            if (i >= 499 && i <= 500 && j >= 499 && j <= 500) {

                output_bool = output_bool && assert_is_false(lights.get_light_state(i, j));

            } else {

                output_bool = output_bool && assert_is_true(lights.get_light_state(i, j));

            }

        }

    }

    struct TestOutput output = {
        __func__,
        output_bool
    };
    return output;
}

struct TestOutput test__turn_on_ancient_nordic_elvish__good_weather__0_0_trough_0_0() {

    TestLightsWithBrightnessControls lights(0);

    int start[] = {0, 0};
    int end[] = {0, 0};

    lights.turn_on_ancient_nordic_elvish(start, end);

    bool output_bool = assert_equal(lights.calculate_total_brightness(), 1);

    output_bool = output_bool && assert_equal(lights.get_light_brightness(0, 0), 1);

    for (int i = 1; i < 1000; i++) {

        for (int j = 1; j < 1000; j++) {

            output_bool = output_bool && assert_equal(lights.get_light_brightness(i, j), 0);

        }

    }

    struct TestOutput output = {
        __func__,
        output_bool
    };
    return output;
}

struct TestOutput test__toggle_ancient_nordic_elvish__good_weather__0_0_trough_999_999() {

    TestLightsWithBrightnessControls lights(0);

    int start[] = {0, 0};
    int end[] = {999, 999};

    lights.toggle_ancient_nordic_elvish(start, end);

    bool output_bool = assert_equal(lights.calculate_total_brightness(), 2000000);

    for (int i = 0; i < 1000; i++) {

        for (int j = 0; j < 1000; j++) {

            output_bool = output_bool && assert_equal(lights.get_light_brightness(i, j), 2);

        }

    }

    struct TestOutput output = {
        __func__,
        output_bool
    };
    return output;
}

class ProbablyaFireHazardTestSuite : public TestSuite {

    public:

        ProbablyaFireHazardTestSuite() {

            vector<TestFunction> temp_vector = {
                &test__turn_on__good_weather__0_0_trough_999_999,
                &test__toggle__good_weather__0_0_trough_999_0,
                &test__turn_off__good_weather__499_499_trough_500_500,
                &test__turn_on_ancient_nordic_elvish__good_weather__0_0_trough_0_0,
                &test__toggle_ancient_nordic_elvish__good_weather__0_0_trough_999_999
            };

            for (size_t index = 0; index < temp_vector.size(); index++) {

                test_functions.push_back(temp_vector[index]);

            }

        }

};

int main() {
    
    ProbablyaFireHazardTestSuite suite;
    suite.run();

}