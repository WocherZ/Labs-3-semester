#include <iostream>

#include "Graphs/Graph.hpp"
#include "Graphs/Test.hpp"
#include "Graphs/HelperGraph.hpp"

#include "Matrix/Matrix.hpp"

int main() {
    int choose = 0;
    do {
        cout << "Test:" << endl;
        cout << "1. Hamilton path" << endl << "2. BFS and DFS" << endl << "3. Floyd Warshall" << endl << "4. Exit" << endl;
        cin >> choose;

        switch (choose) {
            case 1: {
                int vertex, edges;
                cout << "Input vertexes number" << endl;
                cin >> vertex;
                cout << "Input edges number" << endl;
                cin >> edges;
                ArraySequence<Edge<int>> test_edges = ArraySequence<Edge<int>>();

                MakeEdge<int>(edges, &test_edges);
                Graph<int> graph(test_edges);
                cout << "graph created" << endl;

                ArraySequence<int> path = ArraySequence<int>();
                int start_vertex = 0; // Начальная вершина
                path.Append(start_vertex);

                ArraySequence<bool> visited = ArraySequence<bool>();
                bool def = false;
                for (int i = 0; i < vertex; i++) {
                    visited.Append(def);
                }
                visited[start_vertex] = true;

                cout << "arrays are ready" << endl;


                cout << "Hamiltonian paths:" << endl;
                HamiltonianPaths(graph, start_vertex, visited, &path, vertex);
                if (path.GetSize() == 1) cout << "Graph has not hamiltonian paths" << endl;
                break;
            }
            case 2: {
                int vertex, edges, bfsing;
                cout << "Input vertexes number" << endl;
                cin >> vertex;
                cout << "Input edges number" << endl;
                cin >> edges;
//
//                vector<Edge<int>> test_edges = MakeEdge<int>(edges);
//                DirectedGraph<int> graph(vertex, test_edges);
//                cout << "Input vertex for dfs and bfs" << endl;
//                cin >> bfsing;
//
//                cout << "Depth first search starting from vertex " << bfsing << endl;
//                graph.DFS(bfsing);
//                cout << endl;
//
//                cout << "Breadth first search starting from vertex " << bfsing << endl;
//                graph.BFS(bfsing);
//                cout << endl;

                break;
            }

            case 3: {
                int vertex, edges;
                cout << "Input vertexes number" << endl;
                cin >> vertex;
                cout << "Input edges number" << endl;
                cin >> edges;

                ArraySequence<Edge<int>> test_edges = ArraySequence<Edge<int>>();

                MakeEdge<int>(edges, &test_edges);
                DirectedGraph<int> graph = DirectedGraph<int>(vertex, test_edges);

                graph.PrintDict();
                cout << endl;
                graph.FloydWarshall();

                graph.PrintDict();

//                int** help = new int*[vertex];
//                for (int i = 0; i < vertex; i++) {
//                    help[i] = new int[vertex];
//                }
//                int fw_start, fw_finish;
//
//                cout << "Floyd Warshall" << endl;
//                cout << "Input start vertex" << endl;
//                cin >> fw_start;
//                cout << "Input finish vertex" << endl;
//                cin >> fw_finish;
//
//                // PrintSolution(graph.FloydWarshall(help), graph.GetNumber());
//
//                // cout << "Print path from " << fw_start << " to " << fw_finish << " with length " << graph.FloydWarshall(help)[fw_start][fw_finish] << ": " << endl;
//                PrintPath(fw_start, fw_finish, help);
            }

            case 4: {
                cout << "Exit" << endl;
                break;
            }

            default:
                cout << "Enter a number from the list" << endl;
        }
    } while (choose != 4);
    return 0;
}
