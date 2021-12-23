#include "Sequence/Sequence.hpp"
#include "Sequence/ArraySequence.hpp"
#include "Histogram/Dict.hpp"
#include "Histogram/Histogram.hpp"
#include "Paginator/Paginator.hpp"

using namespace std;

int main() {
    auto dict = new Dict<int, int>(3, 6);
    dict->Add(1, 2);
    dict->Add(5, 6);
    dict->Print();
    dict->Remove(5);
    dict->Print();
    double m[6] = {1.0, 4.0, 7.0, 6.0, 5.5, 6.5};
    auto arr = new ArraySequence<double>(m, 6);
    auto hist = Histogram<int, double>(arr, 3.0);
    hist.Print();
    hist.SaveInFile("data.txt", true);

    string test = string("ab tre");
    Paginator<string, int> alpha = Paginator<string, int>(test, 10);
    alpha.Print();
    return 0;
}
