#pragma once
#include "SubExpression.hpp"

void SubExpressionAutoTest() {
    int min = 1, max = 4;
    string text = string("qwerqweqwq");
    cout << "Test string: " << text << endl;
    cout << "Min - " << min << endl;
    cout << "Max - " << max << endl;
    SubExpression test = SubExpression(text, min, max);
    test.Print();
    cout << "Expression: " << test.FindExpression() << endl;
    cout << "Count: " << test.FindMaxValue() << endl;
}