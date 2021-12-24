#pragma once

#include "../Histogram/Dict.hpp"
#include "../Sequence/ArraySequence.hpp"

#include <vector>
#include <string>

template<typename TKey, typename TElement>
class Paginator {
private:
    Dict<TKey, TElement> m_pages;

public:
    Paginator(const string& text, int number_symbols) {

        ArraySequence<string> words;

        string med;
        int check = 0;

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ' || i == text.size() - 1) {
                for (int j = check; j < i; j++) {
                    med.push_back(text[j]);
                }

                if (i == text.size() - 1 && text[i] != ' ') med.push_back(text[i]);

                check = i + 1;

                if ( i != text.size() - 1) {
                    words.Append(med);
                } else {
                    words.Append(med);
                }
                med.clear();
            }
        }

        int length = 0;
        int page = 1;
        int page1_size = number_symbols / 2;
        int page10_size = 3 * number_symbols / 4;

        ArraySequence<TElement> pag;
        string word;

        for (int i = 0; i < words.GetSize(); i++) {
            word = words[i];
            if (i != words.GetSize() -1) word.push_back(' ');
            for (char j : word) {
                if (page == 1 && length > number_symbols / 2) {
                    if (j != ' ') page++;

                } else if (length >= (page - 1) * number_symbols + page1_size) {
                    if (j != ' ') page++;

                } else if (page % 10 == 0 && length >= (page - 2) * number_symbols + page1_size + page10_size) {
                    if (j != ' ') page++;

                }
                length++;
            }
            pag.Append(page);
        }

        for (int i = 0; i < words.GetSize(); i++) {
            m_pages.Add(words[i], pag[i]);
        }


    }

    void Print() {
        m_pages.Print();
    }
};