#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Range {
    long long start;
    long long end;
};

bool compareRanges(const Range &a, const Range &b) {
    return a.start < b.start;
}

int main() {
    // ifstream file("day5example.txt");
    ifstream file("day5input.txt");

    if (!file.is_open()) {
        return 1;
    }
    
    string line;
    vector<Range> idRanges;

    idRanges.clear();

    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        size_t dashPos = line.find('-');
            if (dashPos == string::npos) continue;

            long long start = stoll(line.substr(0, dashPos));
            long long end = stoll(line.substr(dashPos + 1));

            idRanges.push_back({start, end});
    }

    file.close();

    sort(idRanges.begin(), idRanges.end(), compareRanges);

    vector<Range> mergedRanges;
    mergedRanges.push_back(idRanges[0]);

    for (size_t i = 1; i < idRanges.size(); ++i) {
        if (idRanges[i].start <= mergedRanges.back().end + 1) {
            mergedRanges.back().end = max(mergedRanges.back().end, idRanges[i].end);
        } else {
            mergedRanges.push_back(idRanges[i]);
        }
    }

    long long count = 0;
    for (Range range : mergedRanges) {
        count += (range.end - range.start + 1);
    }
    
    cout << "Total fresh IDs: " << count << endl;
    return 0;
}