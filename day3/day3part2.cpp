#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long getProducedJoltage(string s) {
    string joltage;
    int pos = -1;
    string target = "9";

    pos = s.find(target);
    if (s.substr(pos).length() >= 12) {
        joltage += s[pos];
    }

    long long maxVal = stoll(joltage);
    cout << "Produced joltage for " << s << " is " << maxVal << "." << endl;
    return maxVal;
}

int main() {
    long long sum = 0;
    ifstream file("day3example.txt");
    // ifstream file("day3input.txt");
    if (!file.is_open()) {
        cerr << "Error: Cannot open file." << endl;
        return 1;
    }

    string s;

    while (getline(file, s)) {
        if (s == "") continue;
        sum += getProducedJoltage(s);
    }

    file.close();
    cout << "Total output joltage produced is " << sum << "." << endl;
    return sum;
}