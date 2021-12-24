#pragma once
#include "SubExpression.hpp"

void SubExpressionAutoTest() {
    int k = 1;
    cout << "TEST №" << k << endl;
    int min = 1, max = 4;
    string text = string("qwerqweqwq");
    cout << "Test string: " << text << endl;
    cout << "Min - " << min << endl;
    cout << "Max - " << max << endl;
    SubExpression test = SubExpression(text, min, max);
    test.Print();
    cout << "Expression: " << test.FindExpression() << endl;
    cout << "Count: " << test.FindMaxValue() << endl;
    k++;

    cout << "TEST №" << k << endl;
    min = 1, max = 3;
    text = string("qwe qwq");
    cout << "Test string: " << text << endl;
    cout << "Min - " << min << endl;
    cout << "Max - " << max << endl;
    test = SubExpression(text, min, max);
    test.Print();
    cout << "Expression: " << test.FindExpression() << endl;
    cout << "Count: " << test.FindMaxValue() << endl;
    k++;

    cout << "TEST №" << k << endl;
    min = 2, max = 3;
    text = string("qwe qwq");
    cout << "Test string: " << text << endl;
    cout << "Min - " << min << endl;
    cout << "Max - " << max << endl;
    test = SubExpression(text, min, max);
    test.Print();
    cout << "Expression: " << test.FindExpression() << endl;
    cout << "Count: " << test.FindMaxValue() << endl;
}