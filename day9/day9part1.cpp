#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
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
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    inputFile.close();

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                // cout << "Found point at (" << i << ", " << j << ")\n";
                points.push_back(make_pair(i, j));
            }
        }
    }

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