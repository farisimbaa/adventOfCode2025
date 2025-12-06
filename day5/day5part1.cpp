#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Range {
    long long start;
    long long end;
};

vector<Range> idRanges;

bool isFresh(long long targetId) {
    // cout << "Checking ID: " << targetId << endl;
    for (Range range : idRanges) {
        if (targetId >= range.start && targetId <= range.end) {
            // cout << "ID found: " << id << endl;
            return true;
        }
    }
    return false;
}

int main() {
    // ifstream file("day5example.txt");
    ifstream file("day5input.txt");

    if (!file.is_open()) {
        return 1;
    }
    
    int count = 0;
    bool isRange = true;
    string line;
    idRanges.clear();

    while (getline(file, line)) {
        if (line.empty()) {
            isRange = false;
            continue;
        }

        if (isRange) {
            size_t dashPos = line.find('-');
            if (dashPos == string::npos) continue;

            long long start = stoll(line.substr(0, dashPos));
            long long end = stoll(line.substr(dashPos + 1));

            idRanges.push_back({start, end});

        } else {
            long long id = stoll(line);
            
            if (isFresh(id)) {
                count++;
                cout << "Fresh ID: " << id << endl;
            } else {
                cout << "Spoiled ID: " << id << endl;
            }
        }
    }

    file.close();
    
    // for (int i : ids) {
    //     cout << i << " ";
    // }
    
    cout << "Total fresh IDs: " << count << endl;
    return 0;
}