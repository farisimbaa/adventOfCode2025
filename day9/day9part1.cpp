#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<pair<long long, long long>> points;

long long calcArea(int x1, int y1, int x2, int y2) {
    return abs(static_cast<long long>(x2 - x1) + 1) * abs(static_cast<long long>(y2 - y1) + 1);
}

int main() {
    // ifstream inputFile("day9example.txt");
    ifstream inputFile("day9input.txt");

    if (!inputFile.is_open()) return 1;

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        long long x, y;
        char comma;

        ss >> x >> comma >> y;
        points.push_back(make_pair(x, y));
    }

    inputFile.close();

    long long maxSize = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            long long area = calcArea(points[i].first, points[i].second, points[j].first, points[j].second);
            // cout << "Area between points (" << points[i].first << ", " << points[i].second << ") and ("
            //      << points[j].first << ", " << points[j].second << ") is " << area << "\n";
            if (area > maxSize) {
                cout << "New max size found: " << area << " between points (" 
                     << points[i].first << ", " << points[i].second << ") and ("
                     << points[j].first << ", " << points[j].second << ")\n";
                maxSize = area;
            }
        }
    }

    cout << "Largest size: " << maxSize << endl;

    return 0;
}