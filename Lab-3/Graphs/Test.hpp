#pragma once

#include "DirectedGraph.hpp"

template<typename T>
void MakeEdge(int edge_number, Sequence<Edge<int>>* edges) { // Create edges
    for (int i = 0; i < edge_number; i++) {
        Edge<T> m;
        int start, finish, distance;

        cout << "Enter information about edge " << i << endl;
        cout << "Enter start vertex" << endl;
        cin >> start;

        cout << "Enter finish vertex" << endl;
        cin >> finish;

        cout << "Enter length of edge" << endl;
        cin >> distance;

        m.start = start;
        m.finish = finish;
        m.distance = distance;

        edges->Append(m);
    }
}