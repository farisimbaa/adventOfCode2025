#include <iostream>
#include <fstream>
using namespace std;

int zeroCount = 0;

int rotateLeft (int point, int value) {
    int steps = value % 100;
    int loops = value / 100;

    zeroCount += loops;
    
    if (point != 0 && point - steps <= 0) zeroCount++;

    return (point - steps + 100) % 100;
}

int rotateRight (int point, int value) {
    int steps = value % 100;
    int loops = value / 100;

    zeroCount += loops;

    if (point != 0 && point + steps >= 100) zeroCount++;
    return (point + steps) % 100;
}

int rotate(int point, string rotation) {
    if (rotation.front() == 'L') {
        return rotateLeft(point, stoi(rotation.substr(1)));
    } else {
        return rotateRight(point, stoi(rotation.substr(1)));
    }
}

int main() {
    ifstream file("day1input.txt");
    // ifstream file("day1example.txt");
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
        cout << "Current zero count: " << zeroCount << endl;
    }

    file.close();
    cout << "The dial points at 0 a total of " << zeroCount << " times." << endl;
    return zeroCount;
}