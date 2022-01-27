#pragma once

#include <ostream>

#include "../Matrix/Matrix.hpp"

// Неориентированный граф
template<typename T>
class Graph {
private:
    template<typename TDistance>
    class Edge {
    public:
        int start;
        int finish;
        TDistance distance;

        // Constructor
        Edge(int start_vertex, int finish_vertex) {
            start = start_vertex;
            finish = finish_vertex;
        }

        // Operators
        friend ostream& operator << (ostream &out, const Edge &edge) {
            out << "[ " << edge.start << " <-> " << edge.finish << " ]";
        }

    };

    DischargedMatrix<int, T> m_adjacency; // Матрица смежности

public:
    // Constructor
    Graph() {
        m_adjacency = DischargedMatrix<int, T>();
    }

    // Operations

    // Добавление ребра в граф
    void AddEdge(int start_vertex, int finish_vertex, T distance) {
        Pair<int, int> p1 = Pair<int, int>(start_vertex, finish_vertex);
        Pair<int, int> p2 = Pair<int, int>(finish_vertex, start_vertex);
        // Добавление симметричных элементов
        // (В дальнейшем нужно переделать чтобы использовать меньше памяти)
        m_adjacency.AddOrSet(p1, distance);
        m_adjacency.AddOrSet(p2, distance);
    }

    // Получения списка смежных вершин
    void GetAdjacency(int index, ArraySequence<int>* array_adjacency) {
        m_adjacency.ContainsFirst(index, array_adjacency);
    }

    // Поиск гамильтоновых циклов
    void FindHamiltonianPaths(int start_vertex, int number_vertices) {
        ArraySequence<int> path = ArraySequence<int>();
        path.Append(start_vertex);

        ArraySequence<bool> visited = ArraySequence<bool>();
        bool def = false;
        for (int i = 0; i < number_vertices; i++) {
            visited.Append(def);
        }
        visited[start_vertex] = true;

        cout << "Hamiltonian paths:" << endl;
        this->HamiltonianPaths(start_vertex, visited, &path, number_vertices);
        if (path.GetSize() == 1) cout << "Graph has not hamiltonian paths" << endl;
    }

    // Печать всех рёбер
    void PrintEdges() {
        ArraySequence<Pair<int, int>> keys = ArraySequence<Pair<int, int>>();
        m_adjacency.KEYS(&keys);
        cout << "Graph's edges" << endl;
        for (int i = 0; i < keys.GetSize(); i+=2) {
            Edge<T> edge = Edge<T>(keys[i].value_1, keys[i].value_2);
            cout << edge << endl;
        }
    }

    void PrintMatrixAdjacency(int number_vertex) {
        for (int i = 0; i < number_vertex; i++) {
            for (int j = 0; j < number_vertex; j++) {
                Pair<int, int> p = Pair<int, int>(i, j);
                cout << m_adjacency.Get(p) << " ";
            }
            cout << endl;
        }
    }

protected:
    // Вспомогательная рекурентная функция для поиска гамильтоновых циклов
    void HamiltonianPaths(int start, ArraySequence<bool> visited, ArraySequence<int>* path, int number_vertices) {
        // Печать пути если он прошёл по всему графу
        if (path->GetSize() == number_vertices) {
            for (int i = 0; i < path->GetSize(); i++) {
                cout << path->Get(i) << " ";
            }
            cout << endl;
            return;
        }

        // Создание и заполнение массива смежных с вершиной start
        ArraySequence<int> array_adjacency = ArraySequence<int>();
        this->GetAdjacency(start, &array_adjacency);

        for (int w = 0; w < array_adjacency.GetSize(); w++) {
            int s = array_adjacency[w]; // текущая вершина s

            if (!visited[s]) {
                // шаг вперёд
                visited[s] = true;
                path->Append(s);

                HamiltonianPaths(s, visited, path, number_vertices); // Рекурсивный вызов из вершины s

                // шаг назад
                visited[s] = false;
                path->Resize(path->GetSize() - 1);
            }
        }
    }

};