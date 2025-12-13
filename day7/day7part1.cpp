#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
int countSplit = 0;

void splitter(int i, int j) {
    countSplit++;
    grid[i][j+1] = '|';
    grid[i][j-1] = '|';
    if (i+1 < grid.size()) {
        grid[i+1][j+1] = '|';
        grid[i+1][j-1] = '|';
    }
}

void beamer(int i, int j) {
    grid[i+1][j] = '|';
}

int main() {
    // ifstream inputFile("day7example.txt");
    ifstream inputFile("day7input.txt");

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

    int rows = grid.size();
    int cols = grid[0].size();
    int boxCount = 0;

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (grid[i][j] == 'S') {
                cout << "Found source at (" << i << ", " << j << ")\n";
                grid[i+1][j] = '|';
            }
            if (grid[i][j] == '|' && grid[i+1][j] != '^') {
                // cout << "Found beam at (" << i << ", " << j << ")\n";
                beamer(i, j);
                }

            if (grid[i][j] == '^' && grid[i-1][j] == '|') {
                cout << "Found splitter at (" << i << ", " << j << ")\n";
                splitter(i, j);
            }
        }
    }

    cout << "Total splits: " << countSplit << endl;

    return 0;
}