#pragma once

#include "DirectedGraph.hpp"

// Неориентированный граф
template<typename T>
class Graph {
public:
    DischargedMatrix<int, T> m_adjacency; // Матрица смежности

    // Constructor
    explicit Graph(ArraySequence<Edge<T>> edges) {
        m_adjacency = DischargedMatrix<int, T>(); // Init empty matrix

        for (int i = 0; i < edges.GetSize(); i++) {
            int start = edges[i].start;
            int finish = edges[i].finish;
            T distance = edges[i].distance;
            Pair<int, int> p1 = Pair<int, int>(start, finish);
            Pair<int, int> p2 = Pair<int, int>(finish, start);

            // Добавление симметричных элементов
            // (В дальнейшем нужно переделать чтобы использовать меньше памяти)
            m_adjacency.AddOrSet(p1, distance);
            m_adjacency.AddOrSet(p2, distance);
        }
    }

    // Получения списка смежных вершин
    void GetAdjacency(int index, ArraySequence<int>* array_adjacency) {
        m_adjacency.ContainsFirst(index, array_adjacency);
    }

};

template<typename T>
void HamiltonianPaths(Graph<T>& graph, int start, ArraySequence<bool> visited, ArraySequence<int>* path, int number_vertices) {

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
    graph.GetAdjacency(start, &array_adjacency);

    for (int w = 0; w < array_adjacency.GetSize(); w++) {
        int s = array_adjacency[w]; // текущая вершина s

        if (!visited[s]) {
            // шаг вперёд
            visited[s] = true;
            path->Append(s);

            HamiltonianPaths(graph, s, visited, path, number_vertices); // Рекурсивный вызов из вершины s

            // шаг назад
            visited[s] = false;
            path->Resize(path->GetSize() - 1);
        }
    }
}