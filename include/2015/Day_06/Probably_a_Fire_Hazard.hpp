#include <string>

using std::string;

struct OperationData {
    const string operation;
    const int start[2];
    const int end[2];
};

struct OperationData parse_operation_string(string operation_string);

class Lights {

    protected:

        bool lights[1000][1000];

    public:

        Lights(bool initial_state);
        void turn_on(const int start[2], const int end[2]);
        void toggle(const int start[2], const int end[2]);
        void turn_off(const int start[2], const int end[2]);
        int get_number_of_lit_lights();

};

class LightsWithBrightnessControls {

    protected:

        int ** lights;

    public:

        LightsWithBrightnessControls(int initial_state);
        void turn_on_ancient_nordic_elvish(const int start[2], const int end[2]);
        void toggle_ancient_nordic_elvish(const int start[2], const int end[2]);
        void turn_off_ancient_nordic_elvish(const int start[2], const int end[2]);
        int calculate_total_brightness();

};
