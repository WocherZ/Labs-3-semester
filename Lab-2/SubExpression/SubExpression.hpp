#pragma once

#include <string>

#include "../Histogram/Dict.hpp"
#include "../Sequence/ArraySequence.hpp"


class SubExpression {
private:
    ArraySequence<string> m_subexpressions; // Все подвыражения

    Dict<string, int> m_result;  // Словарь с подвыражениями и кол-вом вхождений

public:
    SubExpression(const string& text, int min, int max) {
        ArraySequence<string> res;
        if (min < max && text.size() >= max) {
            string prom = string();
            for (int count = 0; count <= text.size() - min; count++) {

                if (count <= text.size() - max) {
                    for (int j = min; j <= max; j++) {
                        for (int i = count; i < j + count; i++) {
                            prom.push_back(text[i]);
                        }
                        m_subexpressions.Append(prom);
                        prom.clear();

                    }

                } else {
                    for (int j = min; j < text.size() - count + 1; j++) {
                        for (int i = count; i < count + j; i++) {
                            prom.push_back(text[i]);
                        }
                        m_subexpressions.Append(prom);
                        prom.clear();
                    }


                }
            }
        }

        int count;

        for (int i = 0; i < m_subexpressions.GetSize(); i++) {
            count = 1;
            for (int j = 0; j < m_subexpressions.GetSize(); j++) {
                if (m_subexpressions[i] == m_subexpressions[j] && i != j) count++;
            }

            if (m_result.ContainsKey(m_subexpressions[i])) {
                m_result.Set(m_subexpressions[i], count);
            } else {
                m_result.Add(m_subexpressions[i], count);
            }
        }

    }


    void Print() {
        m_subexpressions.Print();
        m_result.Print();
    }

    int FindMaxValue() {
        return m_result.MaxValue();
    }

    string FindExpression() {
        return m_result.GetValueByKey(m_result.MaxValue());
    }
};
