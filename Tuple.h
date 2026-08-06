#ifndef RAY_TUPLE_H
#define RAY_TUPLE_H

struct Tuple {
    float x, y, z, w;
};

bool isPoint(Tuple t);
bool isVector(Tuple t);

bool operator==(Tuple t1, Tuple t2);

Tuple operator+(Tuple t1, Tuple t2);
Tuple operator-(Tuple t1, Tuple t2);
// Tuple operator~(Tuple t1);


#endif //RAY_TUPLE_H
