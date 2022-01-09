#pragma once

#include <vector>

#define inf 3200

using namespace std;

template<typename T>
void PrintVector(vector<T> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void PrintSolution(int** dist, int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == 3200) {
                cout << "#" << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

template<typename T>
void PrintPath(int i, int j, T p) {
    if (i != j) PrintPath(i, p[i][j], p);
    cout << j << " ";
}