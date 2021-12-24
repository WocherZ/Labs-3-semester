#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "Dict.hpp"
#include "Sort.hpp"
#include "../Sequence/Sequence.hpp"

using namespace std;

template<typename TKey, typename TElement>
class Histogram {
private:
    Dict<TKey, TElement> m_dict;
    int m_intervals;
    double m_range;
    TElement m_start;

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

        m_intervals = intervals;
        m_range = range;
        m_start = start;
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
        m_intervals = m_dict.GetSize();
        m_range = range;
        m_start = start;
    }

    void Print() {
        m_dict.Print();
    }

    void SaveInFile(const string& file_name, bool show=false) {
        string file_path = "../Histogram/histogram_data/" + file_name;
        ofstream file(file_path);
        file << m_intervals << " " << m_range << " " << m_start;
        if (show) file << " T\n";
        else file << " F\n";
        file.close();
        m_dict.WriteToFile(file_path);
    }
};

