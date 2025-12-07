#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

long long total = 0;

long long computeChecksum(const vector<vector<string>>& data) {
    int rows = data.size();
    int cols = data[0].size();
    for (int i = 0; i < cols; i++) {
        if (data.back()[i] == "+") {
            long long sum = 0;
            for (int j = 0; j < rows - 1; j++) {
                sum += stoll(data[j][i]);
            }
            total += sum;
        } else if (data.back()[i] == "*") {
            long long product = 1;
            for (int j = 0; j < rows - 1; j++) {
                product *= stoll(data[j][i]);
            }
            total += product;
        }
    }
    return total;
}

int main() {
    // ifstream inputFile("day6example.txt");
    ifstream inputFile("day6input.txt");
    if (!inputFile.is_open()) return 1;

    string line;
    vector<vector<string>> data;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<string> row;
        string item;
        while (ss >> item) {
            row.push_back(item);
        }
        if (!row.empty()) {
            data.push_back(row);
        }
    }

    inputFile.close();

    computeChecksum(data);
    cout << "Total checksum: " << total << endl;

    return 0;
}