#pragma once

template<typename TKey, typename TElement>
class IDictionary {
public:
    virtual void Print() = 0;

    virtual TElement Get(TKey key) = 0;

    virtual TElement operator[](TKey val) = 0;

    virtual bool ContainsKey(TKey key) = 0;

    virtual void Add(TKey key, TElement val) = 0;

    virtual void Set(TKey key, TElement value) = 0;

    virtual void Remove(TKey key) = 0;

    virtual ~IDictionary() = default;
};