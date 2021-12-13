#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string filename = "input/03.txt";

    ifstream infile(filename);
    string line;
    vector<string> bits;
    while (infile >> line) {
        bits.push_back(line);
    }

    vector<int> total;
    for (int j = 0; j < bits[0].size(); j++) {
        total.push_back(0);
    }

    for (int i = 0; i < bits.size(); i++) {
        for (int j = 0; j < bits[i].size(); j++) {
            if (bits[i][j] == '1') {
                total[j] += 1;
            }
        }
    }

    int gamma = 0, epsilon = 0;
    for (int j = 0; j < bits[0].size(); j++) {
        if (total[j] > bits.size() / 2) {
            gamma += 1;
        }
        else {
            epsilon += 1;
        }
        gamma *= 2;
        epsilon *= 2;
    }
    gamma /= 2;
    epsilon /= 2;
    cout << "Part 1: " << gamma * epsilon << endl;

    cout << "Part 2: " << 0 << endl;
}
