#include <bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 10;

// Primary hash function
int h(int k) {
    return k % TABLE_SIZE;
}

// Secondary hash function for double hashing
int h2(int k) {
    return 7 - (k % 7);
}

// Linear probing insert
void insertLinear(vector<int> &table, int key) {
    int idx = h(key);
    int start = idx;
    while (table[idx] != -1) {
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) {
            cout << "Table full, cannot insert " << key << endl;
            return;
        }
    }
    table[idx] = key;
}

// Quadratic probing insert
void insertQuadratic(vector<int> &table, int key) {
    int idx = h(key);
    int i = 0;
    while (table[(idx + i * i) % TABLE_SIZE] != -1) {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Table full, cannot insert " << key << endl;
            return;
        }
    }
    table[(idx + i * i) % TABLE_SIZE] = key;
}

// Double hashing insert
void insertDoubleHash(vector<int> &table, int key) {
    int idx = h(key);
    int step = h2(key);
    int i = 0;
    while (table[(idx + i * step) % TABLE_SIZE] != -1) {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Table full, cannot insert " << key << endl;
            return;
        }
    }
    table[(idx + i * step) % TABLE_SIZE] = key;
}

// Display the table
void printTable(const vector<int> &table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1) cout << i << " : " << "EMPTY" << endl;
        else cout << i << " : " << table[i] << endl;
    }
    cout << "-----------------------------\n";
}

int main() {
    vector<int> keys = {2451, 8253, 6173, 7389, 4344, 9699, 1889};

    cout << "Linear Probing:\n";
    vector<int> linear(TABLE_SIZE, -1);
    for (int k : keys) insertLinear(linear, k);
    printTable(linear);

    cout << "Quadratic Probing:\n";
    vector<int> quadratic(TABLE_SIZE, -1);
    for (int k : keys) insertQuadratic(quadratic, k);
    printTable(quadratic);

    cout << "Double Hashing:\n";
    vector<int> dbl(TABLE_SIZE, -1);
    for (int k : keys) insertDoubleHash(dbl, k);
    printTable(dbl);

    return 0;
}
