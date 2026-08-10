#include "Colour.h"

#include <iostream>

#include "Float.h"

bool operator==(Colour c1, Colour c2) {
    return compare(c1.r, c2.r) && compare(c1.g, c2.g) && compare(c1.b, c2.b);
}

bool operator!=(Colour c1, Colour c2) {
    return !(c1 == c2);
}

Colour operator+(Colour c1, Colour c2) {
    return Colour {
        c1.r + c2.r,
       c1.g + c2.g,
       c1.b + c2.b
    };
}

Colour operator-(Colour c1, Colour c2) {
    return Colour {
        c1.r - c2.r,
       c1.g - c2.g,
       c1.b - c2.b
    };
}

Colour operator*(float s, Colour c) {
    return {
        c.r * s,
        c.g * s,
        c.b * s
    };
}

Colour operator*(Colour c, float s) {
    return s*c;
}

Colour operator*(Colour c1, Colour c2) {
    return Colour {
        c1.r * c2.r,
       c1.g * c2.g,
       c1.b * c2.b
    };
}

void printColour(Colour c) {
    std::cout << c.r << " " << c.g << " " << c.b << std::endl;
}