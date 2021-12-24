#pragma once
#include "Paginator.hpp"

void PaginatorAutoTest() {
    int k = 1;
    cout << "TEST №" << k << endl;
    string test = string("word words");
    int number = 5;
    cout << "Test string:" << test << endl;
    cout << "Number symbols: " << number << endl;
    Paginator<string, int> test_pag = Paginator<string, int>(test, number);
    test_pag.Print();
    k++;

    cout << "TEST №" << k << endl;
    test = string("qw abc");
    number = 4;
    cout << "Test string:" << test << endl;
    cout << "Number symbols: " << number << endl;
    test_pag = Paginator<string, int>(test, number);
    test_pag.Print();
    k++;


    cout << "TEST №" << k << endl;
    test = string("qwer abcde");
    number = 6;
    cout << "Test string:" << test << endl;
    cout << "Number symbols: " << number << endl;
    test_pag = Paginator<string, int>(test, number);
    test_pag.Print();
    k++;
}