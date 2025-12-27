#include "../../../include/2015/Day_05/Doesnt_He_Have_Intern-Elves_For_This.hpp"
#include "../../../include/testing/asserts.hpp"
#include "../../../include/testing/suite.hpp"

struct TestOutput test__is_nice__good_weather__ugknbfddgicrmopn() {
    struct TestOutput output = {
        __func__,
        assert_is_true(is_nice("ugknbfddgicrmopn"))
    };
    return output;
}

struct TestOutput test__is_nice__good_weather__aaa() {
    struct TestOutput output = {
        __func__,
        assert_is_true(is_nice("aaa"))
    };
    return output;
}

struct TestOutput test__is_nice__good_weather__jchzalrnumimnmhp() {
    struct TestOutput output = {
        __func__,
        assert_is_false(is_nice("jchzalrnumimnmhp"))
    };
    return output;
}

struct TestOutput test__is_nice__good_weather__haegwjzuvuyypxyu() {
    struct TestOutput output = {
        __func__,
        assert_is_false(is_nice("haegwjzuvuyypxyu"))
    };
    return output;
}

struct TestOutput test__is_nice__good_weather__dvszwmarrgswjxmb() {
    struct TestOutput output = {
        __func__,
        assert_is_false(is_nice("dvszwmarrgswjxmb"))
    };
    return output;
}

struct TestOutput test__is_nice_now__good_weather__qjhvhtzxzqqjkmpb() {
    struct TestOutput output = {
        __func__,
        assert_is_true(is_nice_now("qjhvhtzxzqqjkmpb"))
    };
    return output;
}

struct TestOutput test__is_nice_now__good_weather__xxyxx() {
    struct TestOutput output = {
        __func__,
        assert_is_true(is_nice_now("xxyxx"))
    };
    return output;
}

struct TestOutput test__is_nice_now__good_weather__uurcxstgmygtbstg() {
    struct TestOutput output = {
        __func__,
        assert_is_false(is_nice_now("uurcxstgmygtbstg"))
    };
    return output;
}

struct TestOutput test__is_nice_now__good_weather__ieodomkazucvgmuy() {
    struct TestOutput output = {
        __func__,
        assert_is_false(is_nice_now("ieodomkazucvgmuy"))
    };
    return output;
}

class DoesntHeHaveInternElvesForThisTestSuite : public TestSuite {

    public:

        DoesntHeHaveInternElvesForThisTestSuite() {

            vector<TestFunction> temp_vector = {
                &test__is_nice__good_weather__ugknbfddgicrmopn,
                &test__is_nice__good_weather__aaa,
                &test__is_nice__good_weather__jchzalrnumimnmhp,
                &test__is_nice__good_weather__haegwjzuvuyypxyu,
                &test__is_nice__good_weather__dvszwmarrgswjxmb,
                &test__is_nice_now__good_weather__qjhvhtzxzqqjkmpb,
                &test__is_nice_now__good_weather__xxyxx,
                &test__is_nice_now__good_weather__uurcxstgmygtbstg,
                &test__is_nice_now__good_weather__ieodomkazucvgmuy
            };

            for (size_t index = 0; index < temp_vector.size(); index++) {

                test_functions.push_back(temp_vector[index]);

            }

        }

};

int main() {
    
    DoesntHeHaveInternElvesForThisTestSuite suite;
    suite.run();

}