#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("day11example.txt");
    // ifstream inputFile("day11input.txt");

    if (!inputFile.is_open()) return 1;

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        long long x, y, z;
        char comma1, comma2;

        ss >> x >> comma1 >> y >> comma2 >> z;
    }

    inputFile.close();

    return 0;
}