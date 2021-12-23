#pragma once
#include "../Sequence/Sequence.hpp"


template<typename T>
int Greater(T a, T b) {
    return (a > b) ? 1 : (a == b) ? 0 : -1;
}

template<typename T>
int Less(T a, T b) {
    return (a < b) ? 1 : (a == b) ? 0 : -1;
}

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