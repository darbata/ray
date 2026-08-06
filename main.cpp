#include <cassert>
#include <iostream>

#include "Tuple.h"

const float epsilon = 0.001f;

void static test() {

    // Point
    Tuple t1 {4.3, -4.2, 3.1, 1.0};
    assert(std::abs(t1.x - 4.3) < epsilon);
    assert(std::abs(t1.y - -4.2) < epsilon);
    assert(std::abs(t1.z - 3.1) < epsilon);
    assert(std::abs(t1.w - 1.0) < epsilon);

    Tuple t2 {4.3, -4.2, 3.1, 0.0};
    assert(std::abs(t2.x - 4.3) < epsilon);
    assert(std::abs(t2.y - -4.2) < epsilon);
    assert(std::abs(t2.z - 3.1) < epsilon);
    assert(std::abs(t2.w - 0.0) < epsilon);

    Tuple t3 {4.3, -4.2, 3.1, 0.0};
    assert(t1 != t3);
    assert(t2 == t3);

    Tuple expected;
    expected = Tuple{8.6, -8.4, 6.2, 1.0};
    assert((t1+t2)==expected);
    expected = Tuple{0.0, 0.0, 0.0, 1.0};
    assert((t1-t2)==expected);


    std::cout << "Tests passed!\n";

}

int main() {
    const auto lang = "C++";
    test();
    return 0;
}
