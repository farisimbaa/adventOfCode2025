#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

long long calcDistance(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    return llround(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)));
}

int main() {
    // ifstream inputFile("day8example.txt");
    ifstream inputFile("day8input.txt");

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