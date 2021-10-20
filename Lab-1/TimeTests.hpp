#pragma once

#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "ISorter.hpp"
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;


template<typename T>
int Greater(T a, T b) {
    return (a > b) ? 1 : (a == b) ? 0 : -1;
}

template<typename T>
int Less(T a, T b) {
    return (a < b) ? 1 : (a == b) ? 0 : -1;
}


Sequence<int> *ArrayGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ArraySequence<int>();

    for (int i = 0; i < size; i++) {
        int num = rand() % max;
        list->Append(num);
    }
    return list;
}

Sequence<int> *ListGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ListSequence<int>();

    for (int i = 0; i < size; i++) {
        int num = rand() % max;
        list->Append(num);
    }
    return list;
}

Sequence<int> *BestArrayGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ArraySequence<int>();

    for (int i = 0; i < size; i++) {
        int num = i;
        list->Append(num);
    }
    return list;
}

Sequence<int> *BestListGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ListSequence<int>();

    for (int i = 0; i < size; i++) {
        int num = i;
        list->Append(num);
    }
    return list;
}

Sequence<int> *WorstArrayGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ArraySequence<int>();

    for (int i = 0; i < size; i++) {
        int num = size - i;
        list->Append(num);
    }
    return list;
}

Sequence<int> *WorstListGenerator(int size, int max = 1000) {
    Sequence<int> *list = new ListSequence<int>();

    for (int i = 0; i < size; i++) {
        int num = size - i;
        list->Append(num);
    }
    return list;
}

template<typename T>
long long TimeTestSort(Sequence<T> *list, ISorter<T> *sorter, int (*cmp)(T, T), int measurements = 1) {
    Sequence<T> *save_list = list->Clone();
    long long sum_time = 0;
    for (int i = 0; i < measurements; i++) {
        auto start = steady_clock::now();
        sorter->Sort(list, cmp);
        auto end = steady_clock::now();
        auto time = duration_cast<microseconds>(end - start);
        sum_time += time.count();
        list = save_list->Clone();
    }
    long long result = sum_time / measurements;
    free(save_list);
    return result;
}

template<typename T>
void TimeTestFunc(const string& sortName,
                  const string& generatorName,
                  const string& structName,
                  ISorter<T> *sorter,
                  Sequence<T> *(*generator)(int n, int max),
                  int (*cmp)(T, T), int min_size, int max_size, int step_size, int measurements = 1, int max_element = 1000) {
    cout << structName << sortName << generatorName << endl;
    string filename = "../graphics/" + structName + "/" + sortName + "_" + generatorName + ".txt";
    ofstream file;
    file.open(filename, ios::out);
    for (int i = min_size; i <= max_size; i += step_size) {
        Sequence<T> *list = generator(i, max_element);
        long long result = TimeTestSort(list, sorter, cmp, measurements);
        file << i << " " << result << "\n";
        free(list);
    }
    file.close();

}

void TimeTest(int min_size, int max_size, int step_size, int measurements) {
   // Для динамического массива
    TimeTestFunc("ShakeSorting", "RandomGenerator", "Array", new ShakeSort<int>(),
                 ArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("MergeSorting", "RandomGenerator", "Array", new MergeSort<int>(),
                 ArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("ShellSorting", "RandomGenerator", "Array", new ShellSort<int>(),
                 ArrayGenerator, Greater, min_size, max_size, step_size, measurements);

    TimeTestFunc("ShakeSorting", "BestGenerator", "Array", new ShakeSort<int>(),
                 BestArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("MergeSorting", "BestGenerator", "Array", new MergeSort<int>(),
                 BestArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("ShellSorting", "BestGenerator", "Array", new ShellSort<int>(),
                 BestArrayGenerator, Greater, min_size, max_size, step_size, measurements);

    TimeTestFunc("ShakeSorting", "WorstGenerator", "Array", new ShakeSort<int>(),
                 WorstArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("MergeSorting", "WorstGenerator", "Array", new MergeSort<int>(),
                 WorstArrayGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("ShellSorting", "WorstGenerator", "Array", new ShellSort<int>(),
                 WorstArrayGenerator, Greater, min_size, max_size, step_size, measurements);

    // Для списка
    TimeTestFunc("ShakeSorting", "RandomGenerator", "List", new ShakeSort<int>(),
                 ListGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("MergeSorting", "RandomGenerator", "List", new MergeSort<int>(),
                 ListGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("ShellSorting", "RandomGenerator", "List", new ShellSort<int>(),
                 ListGenerator, Greater, min_size, max_size, step_size, measurements);

    TimeTestFunc("ShakeSorting", "BestGenerator", "List", new ShakeSort<int>(),
                 BestListGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("MergeSorting", "BestGenerator", "List", new MergeSort<int>(),
                 BestListGenerator, Greater, min_size, max_size, step_size, measurements);
    TimeTestFunc("ShellSorting", "BestGenerator", "List", new ShellSort<int>(),
                 BestListGenerator, Greater, min_size, max_size, step_size, measurements);

   TimeTestFunc("ShakeSorting", "WorstGenerator", "List", new ShakeSort<int>(),
                 WorstListGenerator, Greater, min_size, max_size, step_size, measurements);
   TimeTestFunc("MergeSorting", "WorstGenerator", "List", new MergeSort<int>(),
                 WorstListGenerator, Greater, min_size, max_size, step_size, measurements);
   TimeTestFunc("ShellSorting", "WorstGenerator", "List", new ShellSort<int>(),
                 WorstListGenerator, Greater, min_size, max_size, step_size, measurements);

    cout << "Time tests done! You can see results in files" << endl;
}

