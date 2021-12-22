#pragma once
#include "Dict.hpp"
#include "Sort.hpp"
#include "Sequence/Sequence.hpp"

using namespace std;

template<typename TKey, typename TElement>
class Histogram {
private:
    Dict<TKey, TElement> m_dict;

public:
    Histogram(Sequence<TElement>* array , int intervals, int (*cmp)(TElement, TElement)=Greater) {
        ShakeSort<TElement>().Sort(array, cmp);

        TElement start = array->GetFirst();
        TElement end = array->GetLast();
        TElement range = (end - start) / intervals;

        for (int i = 0; i < intervals; i++) {
            m_dict.Add(i, 0);
            for (int j = 0; j < array->GetSize(); j++) {
                TElement element = array->Get(j);
                if (start + (range * i) <= element && element < start + range * (i + 1)) {
                        m_dict.Set(i, m_dict.Get(i) + 1);
                }
            }
        }

        int last_index = intervals - 1;
        if (m_dict.ContainsKey(last_index)) {
            m_dict.Set(last_index, m_dict.Get(last_index) + 1);
        } else {
            m_dict.Add(last_index, 1);
        }
    }

    Histogram(Sequence<TElement>* array, double range, int (*cmp)(TElement, TElement)=Greater) {
        ShakeSort<TElement>().Sort(array, cmp);

        TElement start = array->GetFirst();
        TElement end = array->GetLast();

        int k = 0;
        int current = 0;
        while (end >= start + range * k) {
            if (!m_dict.ContainsKey(k)) {
                m_dict.Add(k, 0);
            }
            for (int i = current; i < array->GetSize(); i++) {
                TElement element = array->Get(i);
                cout << element << endl;
                if (start + range * k <= element && element < start + range * (k + 1)) {
                    m_dict.Set(k, m_dict.Get(k) + 1);
                    current++;
                } else {
                    current = i;
                    break;
                }

            }
            k++;
        }
    }

    void Print() {
        m_dict.Print();
    }
};

