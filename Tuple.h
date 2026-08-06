#ifndef RAY_TUPLE_H
#define RAY_TUPLE_H
#include <string>

struct Tuple {
    float x, y, z, w;
};

bool isPoint(Tuple t);
bool isVector(Tuple t);

bool operator==(Tuple t1, Tuple t2);
bool operator!=(Tuple t1, Tuple t2);

Tuple operator+(Tuple t1, Tuple t2);
Tuple operator-(Tuple t1, Tuple t2);
Tuple operator~(Tuple t1);
Tuple operator*(float s, Tuple t);
Tuple operator*(Tuple t, float s);
Tuple operator/(Tuple t, float s);


std::string printTuple(Tuple t);

#endif //RAY_TUPLE_H
