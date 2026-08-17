#ifndef RAY_RAY_H
#define RAY_RAY_H

#include "Matrix.h"
#include "Tuple.h"

struct Ray {
    Tuple origin;
    Tuple direction;
};

Tuple position(Ray ray, float t);
Ray transform(const Ray &ray, const Matrix &transform);




#endif //RAY_RAY_H
