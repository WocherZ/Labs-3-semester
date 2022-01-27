#pragma once

#include "Graph.hpp"


Graph<int>* CreateGraph() {
    auto *graph = new Graph<int>();
    int edges_number;
    cout << "Input edges number for create graph" << endl;
    cin >> edges_number;

    for (int i = 1; i <= edges_number; i++) {
        int start, finish, distance;
        cout << "Enter information about edge " << i << endl;
        cout << "Enter start vertex" << endl;
        cin >> start;

        cout << "Enter finish vertex" << endl;
        cin >> finish;

        cout << "Enter length of edge" << endl;
        cin >> distance;

        graph->AddEdge(start, finish, distance);
    }
    cout << "Graph was created" << endl;
    return graph;
}

