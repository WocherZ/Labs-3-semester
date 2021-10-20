#pragma once

#include "Sequence.hpp"

template<class T>
class ISorter {
public:
    virtual Sequence<T> *Sort(Sequence<T> *list, int (*cmp)(T, T)) = 0;
};

template<typename T>
class ShakeSort : public ISorter<T> {
public:
        Sequence<T> *Sort(Sequence<T> *list, int (*cmp)(T, T)) override {
            int n = list->GetSize();
            int left = 0, right = n - 1, control = n - 1;
            do {
                for (int i = left; i < right; i++) {
                    if (cmp((*list)[i], (*list)[i + 1]) > 0) {
                        swap((*list)[i], (*list)[i + 1]);
                        control = i;
                    }
                }
                right = control;
                for (int i = right; i > left; i--) {
                    if (cmp((*list)[i], (*list)[i - 1]) < 0) {
                        swap((*list)[i], (*list)[i - 1]);
                        control = i;
                    }
                }
                left = control;
            } while (left < right);

            return list;
        }
};

template<typename T>
class MergeSort : public ISorter<T> {
public:
    Sequence<T> *Sort(Sequence<T> *list, int (*cmp)(T, T)) override {
        mergeSort((*list), 0, list->GetSize() - 1, cmp);
        return list;
    }

    void mergeSort(Sequence<T> &list, int l, int r, int (*cmp)(T, T)) {
        if (l >= r) return;
        int med = (l + r) / 2;
        mergeSort(list, l, med, cmp);
        mergeSort(list, med + 1, r, cmp);
        Merge(list, l, med, r, cmp);
    }

private:
    inline void Merge(Sequence<T> &list, int l, int med, int r, int (*cmp)(T, T)) {
        int i = l, j = med + 1, size = 0;
        T a[r - l + 1];
        while (i <= med && j <= r) {
            if (cmp(list[i], list[j]) < 0) a[size++] = list[i++];
            else a[size++] = list[j++];
        }

        while (i <= med) a[size++] = list[i++];
        while (j <= r) a[size++] = list[j++];

        size = 0;
        for (i = l; i <= r; i++) list[i] = a[size++];
    }
};

template<typename T>
class ShellSort : public ISorter<T> {
public:
    Sequence<T> *Sort(Sequence<T> *list, int (*cmp)(T, T)) override {
        int n = list->GetSize();
        for (int step = n / 2; step >= 1; step /= 2) {
            for (int i = 0; i < n; i++) {
                for (int j = i + step; j < n; j += step) {
                    if (cmp((*list)[i], (*list)[j]) > 0) swap((*list)[i], (*list)[j]);
                }
            }
        }
        return list;
    }
};