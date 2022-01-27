#pragma once

#include "../Matrix/Matrix.hpp"

using namespace std;

// Ориентированный граф
template<typename T> // T - type of distance
class DirectedGraph {
private:
    template<typename TDistance>
    class Edge {
    public:
        int start;
        int finish;
        TDistance distance;

        // Constructor
        Edge(int start_vertex, int finish_vertex, TDistance distance1) {
            start = start_vertex;
            finish = finish_vertex;
            distance = distance1;
        }

        // Operators
        friend ostream& operator<< (ostream &out, const Edge<T> &edge) {
            out << "[ " << edge.start << " -> " << edge.finish << " : " << edge.distance << " ]";
        }
    };

    DischargedMatrix<int, T> m_adjacency; // Матрица смежности
    DischargedMatrix<int, T> m_distances; // Матрица расстояний
    int m_number; // number of vertices

    // vertices: int
    // distances: T type (int or double)

public:
    // Constructors
    DirectedGraph() {
        m_adjacency = DischargedMatrix<int, T>();
        m_number = 0;
    }

    // Operations

    // Печать словаря
    void PrintDict() {
        m_adjacency.PrintDict();
    }

    // Печать всех рёбер
    void PrintEdges() {
        ArraySequence<Pair<int, int>> keys = ArraySequence<Pair<int, int>>();
        m_adjacency.KEYS(&keys);
        ArraySequence<T> values = ArraySequence<T>();
        m_adjacency.VALUES(&values);
        for (int i = 0; i < keys.GetSize(); i++) {
            Edge<T> edge = Edge<T>(keys[i].GetFirst(), keys[i].GetSecond(), values[i]);
            cout << edge << endl;
        }
    }

    // Количество вершин
    int GetNumber() {
        return m_number;
    }

    // Добавление ребра
    void AddEdge(int first, int second, T distance) {
        Pair<int, int> p = Pair<int, int>(first, second);
        m_adjacency.Add(p, distance);

    }

    // Получения списка смежных вершин
    void GetAdjacency(int index, Sequence<int>* result_sequence) {
        m_adjacency.ContainsFirst(index, result_sequence);
    }

    // Алгоритм Флойда-Уоршелла - заполнение матрицы расстояний
    void FloydWarshall(int number_vertex) {
        m_number = number_vertex;

        ArraySequence<Pair<int, int>> keys = ArraySequence<Pair<int, int>>();
        m_adjacency.KEYS(&keys);
        ArraySequence<T> values = ArraySequence<T>();
        m_adjacency.VALUES(&values);
        for (int i = 0; i < keys.GetSize(); i++) {
            Pair<int, int> p = Pair<int, int>(keys[i].GetFirst(), keys[i].GetSecond());
            m_distances.Add(p, values[i]);
        }
        // Скопировали матрицу смежности в distances
        m_distances.PrintDict();

        for (int y = 0; y < m_number; y++) {
            Pair<int, int> p = Pair<int, int>(y, y);
            m_distances.AddOrSet(p, m_adjacency.Get(p));
        }

        for (int k = 0; k < m_number; k++) {
            for (int i = 0; i < m_number; i++) {
                for (int j = 0; j < m_number; j++) {
                    Pair<int, int> ik = Pair<int, int>(i, k);
                    Pair<int, int> kj = Pair<int, int>(k, j);
                    Pair<int, int> ij = Pair<int, int>(i, j);
                    T distance_ik = m_distances.Get(ik);
                    T distance_kj = m_distances.Get(kj);
                    T distance_ij = m_distances.Get(ij);
                    if (distance_ik && distance_kj && i != j) {
                        if (distance_ik + distance_kj < distance_ij || distance_ij == T()) {
                            m_distances.AddOrSet(ij, distance_ik + distance_kj);
                        }
                    }

                }
            }
        }

        m_distances.PrintDict();
    }


    void PrintMatrixDistances(int number_vertex) {
        for (int i = 0; i < number_vertex; i++) {
            for (int j = 0; j < number_vertex; j++) {
                Pair<int, int> p = Pair<int, int>(i, j);
                if (m_distances.ContainsIndexes(p)) {
                    cout << m_distances.Get(p) << " ";
                } else {
                    cout << "inf ";
                }
            }
            cout << endl;
        }
    }


};

