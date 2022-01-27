#pragma once

#include "DirectedGraph.hpp"

DirectedGraph<int>* CreateDirectedGraph() {
    auto* graph = new DirectedGraph<int>();
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
    cout << "Directed graph was created" << endl;
    return graph;
}