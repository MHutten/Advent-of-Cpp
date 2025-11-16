#include <string>
#include <vector>

using std::string;
using std::vector;

struct TestOutput {

    const string function_name;
    const bool result;

};

typedef struct TestOutput (*TestFunction)();

class TestSuite {

    public:

        void run();

    protected:

        vector<TestFunction> test_functions;


};