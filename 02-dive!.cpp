#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename = "input/02.txt";

    ifstream infile(filename);
    int depth = 0, horizontal = 0, value;
    string key;
    while (infile >> key >> value) {
        if (key.compare("forward") == 0) {
            horizontal += value;
        }
        else if (key.compare("up") == 0) {
            depth -= value;
        }
        else if (key.compare("down") == 0) {
            depth += value;
        }
    }
    cout << "Part 1: " << horizontal * depth << endl;

    infile.clear();
    infile.seekg(0, infile.beg);
    int aim = 0;
    depth = 0;
    horizontal = 0;
    while (infile >> key >> value) {
        if (key.compare("forward") == 0) {
            horizontal += value;
            depth += aim * value;
        }
        else if (key.compare("up") == 0) {
            aim -= value;
        }
        else if (key.compare("down") == 0) {
            aim += value;
        }
    }
    cout << "Part 2: " << horizontal * depth << endl;
}
