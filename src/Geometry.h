#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include "Ray.h"
#include <vector>

struct Sphere {
    Tuple origin;
    float radius;
};

Sphere randomSphere();

std::vector<float> intersect(Sphere, Ray);

#endif //RAY_GEOMETRY_H
