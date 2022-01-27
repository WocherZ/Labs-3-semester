#include <iostream>


#include "Graphs/TestGraph.hpp"
#include "Graphs/TestDirectedGraph.hpp"

int main() {
    int choose = 0;
    DirectedGraph<int>* directed_graph;
    Graph<int>* graph;
    int graph_vertex;
    int directed_graph_vertex;
    do {
        cout << "Operations" << endl;
        cout << "Graph:" << endl;
        cout << "1. Find Hamilton paths" << endl << "2. Print matrix adjacency" << endl;
        cout << "Directed graph:" << endl;
        cout << "3. Floyd Warshall" << endl << "4. Print matrix distances" << endl;
        cout << "5. Exit" << endl;
        cin >> choose;

        switch (choose) {
            case 1: {
                cout << "Input vertexes number" << endl;
                cin >> graph_vertex;

                graph = CreateGraph();
                graph->PrintEdges();
                int start_vertex;
                cout << "Input start vertex:" << endl;
                cin >> start_vertex;
                graph->FindHamiltonianPaths(start_vertex, graph_vertex);
                break;
            }

            case 2: {
                if (graph_vertex > 0) {
                    graph->PrintMatrixAdjacency(graph_vertex);
                } else {
                    cout << "Graph wasn't created" << endl;
                }
                break;
            }

            case 3: {
                cout << "Input vertexes number" << endl;
                cin >> directed_graph_vertex;
                directed_graph = CreateDirectedGraph();
                directed_graph->FloydWarshall(directed_graph_vertex);
                break;
            }

            case 4: {
                if (directed_graph_vertex > 0) {
                    directed_graph->PrintMatrixDistances(directed_graph_vertex);
                } else {
                    cout << "Directed graph wasn't created" << endl;
                }
                break;
            }

            case 5: {
                cout << "Exit" << endl;
                break;
            }

            default:
                cout << "Enter a number from the list" << endl;
        }
    } while (choose != 5);
    return 0;
}
