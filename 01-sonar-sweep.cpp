#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename = "input/01.txt";

    ifstream infile(filename);
    int old_depth = 9999, depth, count = 0;
    while (infile >> depth) {
        if (depth > old_depth) {
            count++;
        }
        old_depth = depth;
    }
    cout << "Part 1: " << count << endl;

    infile.clear();
    infile.seekg(0, infile.beg);
    int one, two, three, next;
    infile >> one >> two >> three;
    count = 0;
    while (infile >> next) {
        if (next > one) {
            count++;
        }
        one = two;
        two = three;
        three = next;
    }
    cout << "Part 2: " << count << endl;
}
