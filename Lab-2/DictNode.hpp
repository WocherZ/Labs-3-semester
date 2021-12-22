#pragma once

using namespace std;

template<typename TKey, typename TElement>
class DictNode {
private:
    TKey m_key;
    TElement m_value;

public:
    DictNode() {
        m_key = TKey();
        m_value = 0;
    }

    DictNode(TKey key1, TElement value1) {
        m_key = key1;
        m_value = value1;
    }

    void SetKey(TKey key1) {
        m_key = key1;
    }

    void SetValue(TElement value1) {
        m_value = value1;
    }

    TKey GetKey() {
        return m_key;
    }

    TElement GetValue() {
        return m_value;
    }

    void Print() {
        cout << m_key << ": " << m_value;
    }

    TElement operator[](TKey key) {
        if (m_key == key) return m_value;
    }

    bool operator==(const DictNode<TKey, TElement>& dictNode) {
        if (m_key == dictNode.m_key && m_value == dictNode.m_value) return true;
        else return false;
    }

    DictNode<TKey, TElement>&operator=(const DictNode<TKey, TElement>& dictNode) {
        this->m_key = dictNode.m_key;
        this->m_value = dictNode.m_value;
        return *this;
    }
};