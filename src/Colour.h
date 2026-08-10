#ifndef RAY_COLOUR_H
#define RAY_COLOUR_H
#include <string>

struct Colour {
    float r, g, b;
};

bool operator == (Colour c1, Colour c2);
bool operator != (Colour c1, Colour c2);

Colour operator+(Colour c1, Colour c2);
Colour operator-(Colour c1, Colour c2);
Colour operator*(float s, Colour c);
Colour operator*(Colour c, float s);
Colour operator*(Colour c1, Colour c2);

void printColour(Colour c);


#endif //RAY_COLOUR_H
