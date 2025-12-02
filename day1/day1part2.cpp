#include <iostream>
#include <fstream>
using namespace std;

int zeroCount = 0;

int rotateLeft (int point, int value) {
    if (point - value < 0) {
        zeroCount = zeroCount + ((point + value) / 100);
        return (point - value % 100 + 100) % 100;
    } else return point - value;
}

int rotateRight (int point, int value) {
    if (point + value >= 100) {
        zeroCount = zeroCount + ((point + value) / 100);
        return (point + value % 100) % 100;
    } else return point + value;
}

int rotate(int point, string rotation) {
    if (rotation.front() == 'L') {
        return rotateLeft(point, stoi(rotation.substr(1)));
    } else {
        return rotateRight(point, stoi(rotation.substr(1)));
    }
}

int main() {
    ifstream file("day1example.txt");
    if (!file.is_open()) {
        cerr << "Error: Cannot open file." << endl;
        return 1;
    }

    string rotation;
    int point = 50;

    while (getline(file, rotation)) {
        if (rotation == "") continue;
        cout << "The dial is rotated " << rotation.front() << rotation.substr(1) << " to point at ";
        point = rotate(point, rotation);
        cout << point << endl;
        if (point == 0) zeroCount++;
    }

    file.close();
    cout << "The dial points at 0 a total of " << zeroCount << " times." << endl;
    return zeroCount;
}