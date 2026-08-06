#include "Tuple.h"
#include <stdexcept>

const float epsilon = 0.0001;


bool isPoint(Tuple t) {
    return abs(t.w - 1.0) < epsilon;
}

bool isVector(Tuple t) {
    return abs(t.w - 0.0) < epsilon;
}

bool operator==(Tuple t1, Tuple t2) {
    if (
        abs(t1.x - t2.x) >= epsilon ||
        abs(t1.y - t2.y) >= epsilon ||
        abs(t1.z - t2.z) >= epsilon ||
        abs(t1.w - t2.w) >= epsilon
    ) {
        return false;
    }
    return true;
}

bool operator!=(Tuple t1, Tuple t2) {
    if (
    abs(t1.x - t2.x) >= epsilon ||
    abs(t1.y - t2.y) >= epsilon ||
    abs(t1.z - t2.z) >= epsilon ||
    abs(t1.w - t2.w) >= epsilon
    ) {
        return true;
    }
    return false;
}

Tuple operator+(Tuple t1, Tuple t2) {
    if (isPoint(t1) && isPoint(t2)) {
        throw new std::invalid_argument("Can't add two points");
    }

    Tuple sum = {
        t1.x + t2.x,
        t1.y + t2.y,
        t1.z + t2.z,
        t1.w + t2.w
    };

    return sum;
}

Tuple operator-(Tuple t1, Tuple t2) {
    if (isVector(t1) && isPoint(t2)) {
        throw new std::invalid_argument("Can't subtract a point from a vector");
    }

    Tuple sum = {
        t1.x - t2.x,
        t1.y - t2.y,
        t1.z - t2.z,
        t1.w - t2.w
    };

    return sum;
}

