#include <cassert>
#include <iostream>

#include "Tuple.h"

const float epsilon = 0.001f;

void static test() {

    Tuple t1 {4.3, -4.2, 3.1, 1.0};
    assert(isPoint(t1));

    Tuple t2 {4.3, -4.2, 3.1, 0.0};
    assert(isVector(t2));

    Tuple expected;
    expected = Tuple{8.6, -8.4, 6.2, 1.0};
    assert((t1+t2)==expected);
    expected = Tuple{0.0, 0.0, 0.0, 1.0};
    assert((t1-t2)==expected);
    expected = Tuple{-4.3, 4.2, -3.1, 1.0};
    assert((~t2)==expected);
    expected = Tuple{8.6, -8.4, 6.2, 0.0};
    assert((2*t2)==expected);
    expected = Tuple{2.15, -2.10, 1.55, 0.0};
    assert((t2/2)==expected);
    std::cout << "tests passed" << std::endl;
    assert(magnitude(Tuple{1, 0 , 0, 0.0}) == 1);
    assert(magnitude(Tuple{0, 1 , 0, 0.0}) == 1);
    assert(magnitude(Tuple{0, 0 , 1, 0.0}) == 1);
    assert(magnitude(Tuple{0, 0 , 2, 0.0}) == 2);
}

int main() {
    const auto lang = "C++";
    test();
    return 0;
}
