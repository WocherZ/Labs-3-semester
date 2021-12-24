#include "Histogram/Histogram.hpp"
#include "Sequence/ArraySequence.hpp"
#include "Paginator/Paginator.hpp"
#include "SubExpression/SubExpression.hpp"

void Histogram_test() {
    int dimension = 0;


    cout << "Enter dimension of sequence" << endl;
    cin >> dimension;

    if (dimension > 0) {
        int m[dimension];
        cout << "Enter elements:" << endl;
        for (int i = 0; i < dimension; i++) {
            cin >> m[i];
        }

        auto array = new ArraySequence<int>(m, dimension);

        int choose;
        cout << "Intervals(1) or Range(2)?" << endl;
        cin >> choose;
        if (choose == 1) {
            int intervals;
            cout << "Enter number intervals:" << endl;
            cin >> intervals;
            Histogram<int, int> hist = Histogram<int, int>(array, intervals);


            int show;
            bool is_showed;
            cout << "Show histogram?" << endl;
            cout << "0 or 1 - NO or YES" << endl;
            cin >> show;
            if (show == 1) is_showed = true;
            else is_showed = false;

            hist.SaveInFile("data.txt", is_showed);
            hist.Print();

        } else {
            double range;
            cout << "Enter range:" << endl;
            cin >> range;
            Histogram<int, int> hist = Histogram<int, int>(array, range);


            int show;
            bool is_showed;
            cout << "Show histogram?" << endl;
            cout << "0 or 1 - NO or YES" << endl;
            cin >> show;
            if (show == 1) is_showed = true;
            else is_showed = false;

            hist.SaveInFile("data.txt", is_showed);
            hist.Print();
        }

    } else {
        cout << "Wrong dimension" << endl;
    }
}

void SubExpressions_test() {
    string text;
    int min, max;
    cout << "Enter your string ot text" << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, text);
    cout << "Enter min length os subexpression" << endl;
    cin >> min;
    cout << "Enter max length os subexpression" << endl;
    cin >> max;
    SubExpression test = SubExpression(text, min, max);
    cout << "Expression: " << test.FindExpression() << endl;
    cout << "Count: " << test.FindMaxValue() << endl;
}


void Paginator_test() {
    string text = string();
    int number;
    cout << "Enter your string ot text" << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, text);
    cout << "Enter number symbols" << endl;
    cin >> number;
    Paginator<string, int> test_pag = Paginator<string, int>(text, number);
    test_pag.Print();
}