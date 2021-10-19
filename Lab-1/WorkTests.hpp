#pragma once

#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "ISorter.hpp"
#include "TimeTests.hpp"

template<typename T>
int CheckGreaterSort(Sequence<T> *list) {
    for (int i = 0; i < list->GetSize() - 1; i++) {
        if ((*list)[i] > (*list)[i + 1]) return 0;
    }
    return 1;
}

template<typename T>
int CheckLessSort(Sequence<T> *list) {
    for (int i = 0; i < list->GetSize() - 1; i++) {
        if ((*list)[i] < (*list)[i + 1]) return 0;
    }
    return 1;
}

template<typename T>
int GreaterSortTest(ISorter<T> *sorter, Sequence<T> *list) {
    sorter->Sort(list, Greater);
    return CheckGreaterSort(list);
}

template<typename T>
int LessSortTest(ISorter<T> *sorter, Sequence<T> *list) {
    sorter->Sort(list, Less);
    return CheckLessSort(list);
}


void ArraySortsTest(int size = 10) {
    string structName = "Array";
    Sequence<int> *list = ArrayGenerator(size);
    cout << "Random Array: ";
    list->Print();
    Sequence<int> *save_list = list->Clone();

    cout << "Greater sorting for " + structName + ":" << endl;
    cout << "Shake sort: ";
    if (GreaterSortTest(new ShakeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Merge sort: ";
    if (GreaterSortTest(new MergeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Shall sort: ";
    if (GreaterSortTest(new ShallSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();

    cout << "Less sorting for " + structName + ":" << endl;
    cout << "Shake sort: ";
    if (LessSortTest(new ShakeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Merge sort: ";
    if (LessSortTest(new MergeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Shall sort: ";
    if (LessSortTest(new ShallSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();

    free(list);
    free(save_list);
    cout << endl;
}

void ListSortsTest(int size = 10) {
    string structName = "List";
    Sequence<int> *list = ListGenerator(size);
    cout << "Random List: ";
    list->Print();
    Sequence<int> *save_list = list->Clone();

    cout << "Greater sorting for " + structName + ":" << endl;
    cout << "Shake sort: ";
    if (GreaterSortTest(new ShakeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Merge sort: ";
    if (GreaterSortTest(new MergeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Shall sort: ";
    if (GreaterSortTest(new ShallSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();

    cout << "Less sorting for " + structName + ":" << endl;
    cout << "Shake sort: ";
    if (LessSortTest(new ShakeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Merge sort: ";
    if (LessSortTest(new MergeSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();
    cout << "Shall sort: ";
    if (LessSortTest(new ShallSort<int>(), list)) cout << "OK" << endl;
    else cout << structName << "WRONG" << endl;
    list = save_list->Clone();

    free(list);
    free(save_list);
    cout << endl;
}

void WorkTest(int size = 10) {
    ArraySortsTest(size);
    ListSortsTest(size);

    cout << "Work tests done!" << endl;
}