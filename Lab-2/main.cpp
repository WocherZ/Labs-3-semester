#include "Sequence/Sequence.hpp"
#include "Sequence/ArraySequence.hpp"
#include "Keyboard_Tests.hpp"
#include "SubExpression/SubExpressionTests.hpp"
#include "Paginator/PaginatorAutoTest.hpp"

using namespace std;

int main() {
    int choose1;
    do {
        cout << "1. Histogram " << endl;
        cout << "2. Subexpressions " << endl;
        cout << "3. Paginator " << endl;
        cout << "4. Auto Expression test" << endl;
        cout << "5. Auto Paginator test" << endl;
        cout << "6. Exit" << endl;
        cin >> choose1;

        switch (choose1) {
            case 1:
                Histogram_test();
                break;

            case 2:
                SubExpressions_test();
                break;

            case 3:
                Paginator_test();
                break;

            case 4:
                SubExpressionAutoTest();
                break;

            case 5:
                PaginatorAutoTest();
                break;

            case 6:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Enter a number from the list" << endl;
        }
        cout << endl;
    } while (choose1 != 6);
    return 0;
}
