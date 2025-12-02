#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

long long sum = 0;

bool checkInvalid(long long id) {
    if (to_string(id).length() % 2 != 0) return false;

    string s = to_string(id);
    string s1 = s.substr(0, s.length() / 2);
    string s2 = s.substr(s.length() / 2, s.length() / 2);

    if (s1 == s2) return true;
    return false;
}

vector<long long> generateIds(long long start, long long end) {
    vector<long long> ids;
    for (long long i = start; i <= end; i++) {
        ids.push_back(i);
        if (checkInvalid(i)) {
            sum += i;
            // cout << "Invalid ID found: " << i << endl;
            // cout << "Current sum: " << sum << endl;
        }
    }
    return ids;
}

int main() {
    // ifstream file("day2example.txt");
    ifstream file("day2input.txt");
    if (!file.is_open()) {
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string range;

        while (getline(ss, range, ',')) {
            size_t dashPos = range.find('-');
            if (dashPos == string::npos) continue;

            long long start = stoll(range.substr(0, dashPos));
            long long end = stoll(range.substr(dashPos + 1));

            generateIds(start, end);
        }
    }

    file.close();

    cout << "Sum of invalid IDs: " << sum << endl;

    return 0;
}