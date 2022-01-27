#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "DictNode.hpp"
#include "IDictionary.hpp"
#include "../Sequence/Sequence.hpp"
#include "../Sequence/ArraySequence.hpp"

using namespace std;

template<typename TKey, typename TElement>
class Dict: public IDictionary<TKey, TElement> {
private:
    DictNode<TKey, TElement>* m_memory;
    int m_size;

public:
    // Constructors
    Dict<TKey, TElement>() {
        m_memory = new DictNode<TKey, TElement>[0];
        m_size = 0;
    }

    Dict<TKey, TElement>(TKey key, TElement value) {
        m_memory = new DictNode<TKey, TElement>[1];
        m_memory[0].SetKey(key);
        m_memory[0].SetValue(value);
        m_size = 1;
    }

    Dict<TKey, TElement>(TKey* array1, TElement* array2, int size) {
        m_memory = new DictNode<TKey, TElement>[size];
        for (int i = 0; i < size; i++) {
            m_memory[i].SetKey(array1[i]);
            m_memory[i].SetValue(array2[i]);
        }
        m_size = size;
    }

    // Operations

    int GetSize() {
        return m_size;
    }

    void Print() override {
        cout << "{ ";
        for (int i = 0; i < m_size; i++) {
            m_memory[i].Print();
            if (i < m_size - 1) cout << ", ";
        }
        cout << " }" << endl;
    }

    // Оператор индексирования
    TElement operator[](TKey key) {
        for (int i = 0; i < m_size; i++) {
            if (m_memory[i].GetKey() == key) return m_memory[i].GetValue();
        }
        throw invalid_argument("KeyError");
    }

    // Получение значения по ключу
    TElement Get(TKey key) {
        for (int i = 0; i < m_size; i++) {
            if (m_memory[i].GetKey() == key) return m_memory[i].GetValue();
        }
        throw invalid_argument("KeyError");
    }

    // Получение ключа по значению
    TKey GetKeyByValue(TElement value) {
        for (int i = 0; i < m_size; i++) {
            if (m_memory[i].GetValue() == value) return m_memory[i].GetKey();
        }
        throw invalid_argument("KeyError: value not in dictionary");
    }

    // Проверка вхождения ключа в словарь
    bool ContainsKey(TKey key) {
        for (int i = 0; i < m_size; i++) {
            if (m_memory[i].GetKey() == key) return true;
        }
        return false;
    }

    // Оператор присваивания
    Dict<TKey, TElement>&operator=(const Dict<TKey, TElement>& dict) {
        m_memory = new DictNode<TKey, TElement>[dict.m_size];
        m_size = dict.m_size;
        for (int i = 0; i < m_size; i++) m_memory[i] = dict.m_memory[i];
        return *this;
    }

    // Добавить ключ-значение
    void Add(TKey key, TElement value) {
        auto result_memory = new DictNode<TKey, TElement>[m_size + 1];
        for (int i = 0; i < this->m_size; i++) result_memory[i] = this->m_memory[i];
        result_memory[m_size] = DictNode<TKey, TElement>(key, value);
        this->m_memory = result_memory;
        this->m_size = m_size + 1;
    }

    // Установить значение
    void Set(TKey key, TElement value) {
        for (int i = 0; i < m_size; i++) {
            if (m_memory[i].GetKey() == key) {
                m_memory[i].SetValue(value);
                return;
            }
        }
        throw invalid_argument("KeyError");
    }

    // Добавление/Установить значение
    void AddOrSet(TKey key, TElement value) {
        if (ContainsKey(key)) {
            Set(key, value);
        } else {
            Add(key, value);
        }
    }

    // Удаление
    void Remove(TKey key) {
        if (this->ContainsKey(key)) {
            int check = 0;
            auto result_memory = new DictNode<TKey, TElement>[m_size - 1];
            for (int i = 0; i < m_size; i++) {
                if (m_memory[i].GetKey() != key && !check) {
                    result_memory[i - check] = this->m_memory[i];
                } else {
                    check = 1;
                }
            }
            this->m_memory = result_memory;
            this->m_size = m_size - 1;
        } else {
            throw invalid_argument("KeyError");
        }
    }

    // Запись в файл
    void WriteToFile(const string& path) {
        ofstream file(path, ios_base::app);
        for (int i = 0; i < m_size; i++) {
            file << m_memory[i].GetKey() << ": " << m_memory[i].GetValue() << "\n";
        }
        file.close();
    }

    // Поиск максимального значения
    TElement MaxValue() {
        TElement max = m_memory[0].GetValue();
        for (int i = 1; i < m_size; i++) {
            if (m_memory[i].GetValue() > max) max = m_memory[i].GetValue();
        }
        return max;
    }


    // Все ключи записываются в sequence
    void KEYS(ArraySequence<TKey>* sequence) {
        if (sequence->GetSize() != 0) {
            throw invalid_argument("Not valid sequence; Size must be 0");
        } else {
            for (int i = 0; i < m_size; i++) {
                sequence->Append(m_memory[i].GetKey());
            }
        }
    }

    // Все значения записываются в sequence
    void VALUES(ArraySequence<TElement>* sequence) {
        if (sequence->GetSize() != 0) {
            throw invalid_argument("Not valid sequence; Size must be 0");
        } else {
            for (int i = 0; i < m_size; i++) {
                sequence->Append(m_memory[i].GetValue());
            }
        }
    }

    //Destructor
    ~Dict<TKey, TElement>() = default;
};