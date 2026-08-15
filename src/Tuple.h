#ifndef RAY_TUPLE_H
#define RAY_TUPLE_H
#include <string>

struct Tuple {
    float x, y, z, w;
};

Tuple point(float x, float y, float z);
Tuple vector(float x, float y, float z);

bool isPoint(Tuple t);
bool isVector(Tuple t);

bool operator==(Tuple t1, Tuple t2);
bool operator!=(Tuple t1, Tuple t2);

Tuple operator+(Tuple t1, Tuple t2);
Tuple operator-(Tuple t1, Tuple t2);
Tuple operator-(Tuple t);
Tuple operator*(float s, Tuple t);
Tuple operator*(Tuple t, float s);
Tuple operator/(Tuple t, float s);

float magnitude(Tuple t);
Tuple normalise(Tuple t);

float dot(Tuple t1, Tuple t2);
Tuple cross(Tuple t1, Tuple t2);

void printTuple(Tuple t);

#endif //RAY_TUPLE_H
