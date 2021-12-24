#pragma once
#include "Paginator.hpp"

void PaginatorAutoTest() {
    string test = string("word words");
    int number = 5;
    cout << "Test string:" << test << endl;
    cout << "Number symbols: " << number << endl;
    Paginator<string, int> test_pag = Paginator<string, int>(test, number);
    test_pag.Print();
}