#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int total;
int col;
int count;
vector<char> v;

bool checkCount(int count, int i) {
    if (count < 4) {
        total++;
        cout << "Position " << i << " with char: '" << v[i] << "' is counted." << endl;
        return true;
    } else return false;
}

bool isCorner(int i) {
    if (i == 0 || i == col - 1 || i == (col - 1) * col || i == (col * col) - 1) {
        return true;
    } else {
        return false;
    }
}

bool topRow(int i) {
    if (i < col) {
        return true;
    } else {
        return false;
    }
}

bool bottomRow(int i) {
    if (i >= v.size() - col) {
        return true;
    } else {
        return false;
    }
}

bool leftColumn(int i) {
    if (i % col == 0) {
        return true;
    } else {
        return false;
    }
}

bool rightColumn(int i) {
    if ((i + 1) % col == 0) {
        return true;
    } else {
        return false;
    }
}

int countTopRow(int i) {
    int count = 0;
    if (v[i + 1] == '@') count++;
    if (v[i - 1] == '@') count++;
    if (v[i + col] == '@') count++;
    if (v[i + col + 1] == '@') count++;
    if (v[i + col - 1] == '@') count++;
    return count;
}

int countBottomRow(int i) {
    int count = 0;
    if (v[i + 1] == '@') count++;
    if (v[i - 1] == '@') count++;
    if (v[i - col] == '@') count++;
    if (v[i - col + 1] == '@') count++;
    if (v[i - col - 1] == '@') count++;
    return count;
}

int countLeftColumn(int i) {
    int count = 0;
    if (v[i + 1] == '@') count++;
    if (v[i + col] == '@') count++;
    if (v[i + col + 1] == '@') count++;
    if (v[i - col] == '@') count++;
    if (v[i - col + 1] == '@') count++;
    return count;
}

int countRightColumn(int i) {
    int count = 0;
    if (v[i - 1] == '@') count++;
    if (v[i + col] == '@') count++;
    if (v[i + col - 1] == '@') count++;
    if (v[i - col] == '@') count++;
    if (v[i - col - 1] == '@') count++;
    return count;
}

void countPaper() {
    total = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != '@') {
            continue;
        } else if (isCorner(i)) {
            total++;
            cout << "Corner at position " << i << " with char: '" << v[i] << "' is counted." << endl;
        } else if (topRow(i)) {
            count = countTopRow(i);
            checkCount(count, i);
        } else if (bottomRow(i)) {
            count = countBottomRow(i);
            checkCount(count, i);
        } else if (leftColumn(i)) {
            count = countLeftColumn(i);
            checkCount(count, i);
        } else if (rightColumn(i)) {
            count = countRightColumn(i);
            checkCount(count, i);
        } else {
            count = 0;
            if (v[i + 1] == '@') count++;
            if (v[i - 1] == '@') count++;
            if (v[i + col] == '@') count++;
            if (v[i - col] == '@') count++;
            if (v[i + col + 1] == '@') count++;
            if (v[i + col - 1] == '@') count++;
            if (v[i - col + 1] == '@') count++;
            if (v[i - col - 1] == '@') count++;
            checkCount(count, i);
        }
    }
}


int main() {
    total = 0;
    // ifstream file("day4example.txt");
    ifstream file("day4input.txt");
    if (!file.is_open()) {
        cerr << "Error: Cannot open file." << endl;
        return 1;
    }

    string s;

    v.clear();
    while (getline(file, s)) {
        if (s == "") continue;
        col = s.length();
        for (char c : s) {
            v.push_back(c);
        }
    }

    countPaper();
    file.close();
    cout << "Total: " << total << endl;
    return total;
}