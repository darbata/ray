#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include "Ray.h"
#include <vector>


struct Sphere  {
    Tuple origin;
    float radius;
};

struct Intersection {
    float t;
    Sphere* s;
};

Sphere randomSphere();
std::vector<Intersection> intersect(Sphere, Ray);

#endif //RAY_GEOMETRY_H
