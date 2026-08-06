#ifndef RAY_TUPLE_H
#define RAY_TUPLE_H

struct Tuple {
    float x, y, z, w;
};

bool operator==(Tuple t1, Tuple t2);

#endif //RAY_TUPLE_H
