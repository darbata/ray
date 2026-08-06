#include "Tuple.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

const float epsilon = 0.0001;

bool isPoint(Tuple t) {
    return abs(t.w - 1.0) < epsilon;
}

bool isVector(Tuple t) {
    return abs(t.w - 0.0) < epsilon;
}

bool operator==(Tuple t1, Tuple t2) {
    if (abs(t1.x - t2.x) >= epsilon || abs(t1.y - t2.y) >= epsilon || abs(t1.z - t2.z) >= epsilon)
    {
        return false;
    }
    return true;
}

bool operator!=(Tuple t1, Tuple t2) {
    std::cout << t1.x << " " << t1.y << " " << t1.z << std::endl;
    std::cout << t2.x << " " << t2.y << " " << t2.z << std::endl;
    if (abs(t1.x - t2.x) >= epsilon || abs(t1.y - t2.y) >= epsilon || abs(t1.z - t2.z) >= epsilon)
    {
        return true;
    }
    return false;
}

Tuple operator+(Tuple t1, Tuple t2) {
    if (isPoint(t1) && isPoint(t2)) {
        throw new std::invalid_argument("Can't add two points");
    }

    Tuple sum = {t1.x + t2.x,t1.y + t2.y,t1.z + t2.z,t1.w + t2.w};

    return sum;
}

Tuple operator-(Tuple t1, Tuple t2) {
    if (isVector(t1) && isPoint(t2)) {
        throw new std::invalid_argument("Can't subtract a point from a vector");
    }

    Tuple sum = {t1.x - t2.x,t1.y - t2.y,t1.z - t2.z,t1.w - t2.w};

    return sum;
}

Tuple operator~(Tuple t1) {
    if (isPoint(t1)) {
        throw new std::invalid_argument("Can't negate a point");
    }

    float x = 0.0 - t1.x;
    float y = 0.0 - t1.y;
    float z = 0.0 - t1.z;

    return Tuple { x, y, z, t1.w };
}

Tuple operator*(float s, Tuple t) {
    if (isPoint(t)) {
        throw new std::invalid_argument("Can't scale points");
    }

    return Tuple { s * t.x, s * t.y, s * t.z, t.w };
}

Tuple operator*(Tuple t, float s) {
    if (isPoint(t)) {
        throw new std::invalid_argument("Can't scale points");
    }

    return Tuple { s * t.x, s * t.y, s * t.z, t.w };
}

Tuple operator/(Tuple t, float s) {
    if (isPoint(t)) {
        throw new std::invalid_argument("Can't scale points");
    }
    return Tuple { t.x/s,  t.y/s,  t.z/s, t.w };
}

float magnitude(Tuple t) {
    return sqrt(pow(t.x,2) + pow(t.y,2) + pow(t.z,2) + pow(t.w,2));
}

Tuple normalise(Tuple t) {
    float m = magnitude(t);
    return Tuple {
        t.x/m,t.y/m,t.z/m,t.w/m
    };
}

float dot(Tuple t1, Tuple t2) {
    return t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w;
}

std::string printTuple(Tuple t) {
    std::cout << t.w << " " << t.y << " " << t.z << " " << t.w << std::endl;
}
