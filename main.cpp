#include <cassert>
#include <iostream>

#include "Colour.h"
#include "Float.h"
#include "Tuple.h"
#include <cmath>

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
    expected = Tuple{-4.3, 4.2, -3.1, 0.0};
    assert((-t2)==expected);
    expected = Tuple{8.6, -8.4, 6.2, 0.0};
    assert((2*t2)==expected);
    expected = Tuple{2.15, -2.10, 1.55, 0.0};
    assert((t2/2)==expected);
    assert(magnitude(Tuple{1, 0 , 0, 0.0}) == 1);
    assert(magnitude(Tuple{0, 1 , 0, 0.0}) == 1);
    assert(magnitude(Tuple{0, 0 , 1, 0.0}) == 1);
    assert(compare(magnitude(Tuple{1, 2 , 3, 0.0}), sqrt(14)));
    assert(magnitude(normalise(t1)) == 1);
    assert(dot(Tuple{1, 2, 3, 0.0}, Tuple{2, 3, 4, 0.0}) == 20);
    Tuple c = cross(Tuple{1, 2, 3, 0.0}, Tuple{2, 3, 4, 0.0});
    expected = Tuple{-1, 2, -1, 0.0};
    assert(c == expected);

    auto colour = Colour{-0.5, 0.4, 1.7};
    assert(compare(colour.r, -0.5));
    assert(compare(colour.g, 0.4));
    assert(compare(colour.b, 1.7));

    auto c1 = Colour {0.9, 0.6, 0.75};
    auto c2 = Colour {0.7, 0.1, 0.25};


    std::cout << "tests passed" << std::endl;
}

int main() {
    test();
    return 0;
}