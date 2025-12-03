#include <iostream>
#include <fstream>

using namespace std;

int getMax(string s) {
    int max = -1;
    for (char c : s) {
        int digit = c - '0';
        if (digit > max) {
            max = digit;
        }
    }
    return max;
}

int getProducedJoltage(string s) {
    int firstMax = -1;
    int secondMax = -1;
    int maxIndex = -1;

    for (int i = 0; i < s.length(); i++) {
        int digit = s[i] - '0';
        if (digit > firstMax) {
            firstMax = digit;
            maxIndex = i;
        }
    }

    if (maxIndex == s.length() - 1) {
        secondMax = stoi(to_string(firstMax));
        firstMax = getMax(s.substr(0, s.length() - 1));
    } else {
        secondMax = getMax(s.substr(maxIndex + 1));
    }

    cout << "First max: " << firstMax << ", Second max: " << secondMax << endl;

    int result = stoi(to_string(firstMax) + to_string(secondMax));
    cout << "The largest joltage produced from " << s << " is " << result << "." << endl;
    return result;
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