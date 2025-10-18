#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void assert_file_found(ifstream * input_file_stream) {

    if (!input_file_stream->is_open()) {

        cerr << "file not found" << endl;
        exit(1);

    }

}

string read(string file_path) {

    ifstream input_file_stream(file_path);

    assert_file_found(&input_file_stream);

    string file_content;
    string line;

    while (getline(input_file_stream, line)) {

        file_content.append(line);

    }

    input_file_stream.close();

    return file_content;

}

vector<string> read_lines(string file_path) {

    ifstream input_file_stream(file_path);

    assert_file_found(&input_file_stream);

    vector<string> file_content;
    string line;

    while (getline(input_file_stream, line)) {

        file_content.push_back(line);

    }

    input_file_stream.close();

    return file_content;

}