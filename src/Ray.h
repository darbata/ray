#ifndef RAY_RAY_H
#define RAY_RAY_H

#include "Tuple.h"

struct Ray {
    Tuple origin;
    Tuple direction;
};

Tuple position(Ray ray, float t);



#endif //RAY_RAY_H
