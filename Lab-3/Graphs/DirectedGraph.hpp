#pragma once
#include <list>
#include <vector>
#include <queue>

#include "../Matrix/Matrix.hpp"


using namespace std;


// Инкапсулировать класс дуги в граф
template<typename T>
class Edge {
public:
    int start;
    int finish;
    T distance;

    // Operators
    friend ostream& operator<< (ostream &out, const Edge<T> &edge) {
        out << "[ " << edge.start << " -> " << edge.finish << " : " << edge.distance << " ]";
    }

};

// Ориентированный граф
template<typename T> // T - type of distance
class DirectedGraph {
private:
    DischargedMatrix<int, T> m_adjacency; // vertex - int type; T - distances
    // list<int>* m_adjacency;
    // T** m_distances;
    int m_number; // number of vertices

    // vertices: int
    // distances: T type (int or double)

public:
    // Constructors
    DirectedGraph(int number_vertices, T** data) {
        m_number = number_vertices;
        m_adjacency = DischargedMatrix<int, T>(); // Init empty matrix

        for (int i = 0; i < number_vertices; i++) {
            for (int j = 0; j < number_vertices; j++) {
                Pair<int, int> p = Pair<int, int>(i, j);
                m_adjacency.Add(p, data[i][j]);
            }
        }
    }

    DirectedGraph(int number_vertices, ArraySequence<Edge<T>> edges) {
        m_number = number_vertices;
        m_adjacency = DischargedMatrix<int, T>(); // Init empty matrix

        for (int i = 0; i < edges.GetSize(); i++) {
            Pair<int, int> p = Pair<int, int>(edges[i].start, edges[i].finish);
            m_adjacency.Add(p, edges[i].distance);
        }
    }

    // Operations

    // Печать словаря
    void PrintDict() {
        m_adjacency.PrintDict();
    }

    // Количество вершин
    int GetNumber() {
        return m_number;
    }

    // Добавление ребра
    void AddEdge(int first, int second, T distance) {
        Pair<int, int> p = Pair<int, int>(first, second);
        m_adjacency.Add(p, distance);

        //m_adjacency[first].push_back(second);
    }

    // Получения списка смежных вершин
    void GetAdjacency(int index, Sequence<int>* result_sequence) {
        m_adjacency.ContainsFirst(index, result_sequence);
    }

//    void BFS(int s) {
//        bool *visited = new bool[m_number];
//        for (int i = 0; i < m_number; i++) visited[i] = false;
//        visited[s] = true;
//
//        queue<int> queue;
//        queue.push(s);
//
//        list<int>::iterator i;
//
//        while (!queue.empty()) {
//            s = queue.front();
//            cout << s << " ";
//            queue.pop();
//
//            for (i = m_adjacency[s].begin(); i != m_adjacency[s].end(); ++i) {
//                if (!visited[*i]) {
//                    visited[*i] = true;
//                    queue.push(*i);
//                }
//            }
//        }
//    }
//
//    void DFS_rec(int v, bool visited[]) {
//        visited[v] = true;
//        cout << v << " ";
//
//        list<int>::iterator i;
//        for (i = m_adjacency[v].begin(); i != m_adjacency[v].end(); ++i) {
//            if (!visited[*i]) DFS_rec(*i, visited);
//        }
//    }
//
//    void DFS(int v) {
//        bool *visited = new bool[m_number];
//        for (int i = 0; i < m_number; i++) visited[i] = false;
//        DFS_rec(v, visited);
//    }

    void FloydWarshall() {  // time - O(n^3); memory - O(n^2)
//        int** dist = new int*[m_number];
//        for (int i = 0; i < m_number; i++) {
//            dist[i] = new int[m_number];
//        }
//        for (int i = 0; i < m_number; i++) {
//            for (int j = 0; j < m_number; j++) {
//                dist[i][j] = m_distances[i][j];
//                parent[i][j] = i;
//            }
//        }
//
//        for (int k = 0; k < m_number; k++) {
//            for (int i = 0; i < m_number; i++) {
//                for (int j = 0; j < m_number; j++) {
//                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
//                        dist[i][j] = dist[i][k] + dist[k][j];
//                        parent[i][j] = parent[k][j];
//                    }
//                }
//            }
//        }
//        return dist;

        for (int k = 0; k < m_number; k++) {
            for (int i = 0; i < m_number; i++) {
                for (int j = 0; j < m_number; j++) {
                    Pair<int, int> ik = Pair<int, int>(i, k);
                    Pair<int, int> kj = Pair<int, int>(k, j);
                    Pair<int, int> ij = Pair<int, int>(i, j);
                    T distance_ik = m_adjacency.Get(ik);
                    T distance_kj = m_adjacency.Get(kj);
                    T distance_ij = m_adjacency.Get(ij);
                    if (distance_ik + distance_kj < distance_ij) {
                        m_adjacency.AddOrSet(ij, distance_ik + distance_kj);
                    }

                }
            }
        }
    }

};

