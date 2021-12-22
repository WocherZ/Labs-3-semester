#include "Sequence/Sequence.hpp"
#include "Sequence/ArraySequence.hpp"
#include "Dict.hpp"
#include "Histogram.hpp"

using namespace std;

int main() {
    auto dict = new Dict<int, int>(3, 6);
    dict->Add(1, 2);
    dict->Add(5, 6);
    dict->Print();
    dict->Remove(5);
    dict->Print();
    double m[4] = {1.0, 4.0, 2.0, 7.0};
    auto arr = new ArraySequence<double>(m, 4);
    auto hist = Histogram<int, double>(arr, 4.0);
    hist.Print();
    return 0;
}
