#pragma once

#include "Dict.hpp"

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 value_1;
    T2 value_2;

    // Constructors
    Pair<T1, T2>() {
        value_1 = T1();
        value_2 = T2();
    }
    Pair<T1, T2>(T1 arg_1, T2 arg_2) {
        value_1 = arg_1;
        value_2 = arg_2;
    }

    // Operations

    T1 GetFirst() {
        return value_1;
    }

    T2 GetSecond() {
        return value_2;
    }

    // Operators

    friend ostream& operator<< (ostream &out, const Pair &p) {
        out << "(" << p.value_1 << ", " << p.value_2 << ")";
    }

    bool operator==(const Pair<T1, T2>& p) {
        if (value_1 == p.value_1 && value_2 == p.value_2) return true;
        else return false;
    }

    Pair<T1, T2>&operator=(const Pair<T1, T2>& p) {
        this->value_1 = p.value_1;
        this->value_2 = p.value_2;
        return *this;
    }

    bool operator!=(const Pair<T1, T2>& p) {
        if (value_1 != p.value_1 || value_2 != p.value_2) return true;
        else return false;
    }

};

template<typename TIndex, typename TValue>
class DischargedMatrix {
private:
    Dict<Pair<TIndex, TIndex>, TValue> m_elements;

    // Matrix:
    //
    //       | Index | Index
    // ---------------------
    // Index | value | value
    // ---------------------
    // Index | value | value

public:
    // Constructors
    DischargedMatrix<TIndex, TValue>() {
        m_elements = Dict<Pair<TIndex, TIndex>, TValue>();
    }

    DischargedMatrix<TIndex, TValue>(Pair<TIndex, TIndex> pair_indexes, TValue value) {
        m_elements = Dict<Pair<TIndex, TIndex>, TValue>(pair_indexes, value);
    }


    // Operations
    int GetSize() {
        return m_elements.GetSize();
    }

    // Добавление индексов и значения
    void Add(Pair<TIndex, TIndex> pair_indexes, TValue value) {
        m_elements.Add(pair_indexes, value);
    }

    // Установить паре индексов значение
    void Set(Pair<TIndex, TIndex> pair_indexes, TValue value) {
        m_elements.Set(pair_indexes, value);
    }

    // Проверка на содержание индексов в матрице
    bool ContainsIndexes(Pair<TIndex, TIndex> pair_indexes) {
        return m_elements.ContainsKey(pair_indexes);
    }

    // Добавить/Установить
    void AddOrSet(Pair<TIndex, TIndex> pair_indexes, TValue value) {
        m_elements.AddOrSet(pair_indexes, value);
    }

    // Удаление
    void Remove(Pair<TIndex, TIndex> pair_indexes) {
        m_elements.Remove(pair_indexes);
    }

    // Печать словаря матрицы
    void PrintDict() {
        m_elements.Print();
    }

    // Получить значение по индексам
    TValue Get(Pair<TIndex, TIndex> pair_indexes) {
        if (ContainsIndexes(pair_indexes)) {
            return m_elements.Get(pair_indexes);
        } else {
            return TValue(); // return 0
            // throw invalid_argument("KeyError");
        }
    }

    // Все ключи записываются в sequence
    void KEYS(ArraySequence<Pair<TIndex, TIndex>>* sequence) {
        m_elements.KEYS(sequence);
    }

    // Все значения записываются в sequence
    void VALUES(ArraySequence<TValue>* sequence) {
        m_elements.VALUES(sequence);
    }

    // Нахождение элементов в которые ведёт элемент index
    void ContainsFirst(TIndex index, ArraySequence<TIndex>* sequence) {
        auto keys = new ArraySequence<Pair<TIndex, TIndex>>();
        this->m_elements.KEYS(keys);
        for (int i = 0; i < keys->GetSize(); i++) {
            Pair<int, int> p = keys->Get(i);
            if (p.GetFirst() == index) sequence->Append(p.GetSecond());

        }
    }

    // Нахождение элементов которые ведут в элемент index
    void ContainsSecond(TIndex index, Sequence<TIndex>* sequence) {
        ArraySequence<Pair<TIndex, TIndex>> keys = ArraySequence<Pair<TIndex, TIndex>>();
        KEYS(keys);
        for (int i = 0; i < keys.GetSize(); i++) {
            if (keys[i].value_2 == index) sequence->Append(keys[i].value_1);
        }
    }

    // Destructor
    ~DischargedMatrix<Pair<TIndex, TIndex>, TValue>() = default;

};