#include <iostream>
#include <fstream>

using namespace std;

int getProducedJoltage(string s) {
    int len = s.length();
    
}

int main() {
    int sum = 0;
    // ifstream file("day3example.txt");
    ifstream file("day3input.txt");
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