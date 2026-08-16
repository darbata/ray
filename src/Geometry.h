#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include <optional>

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

std::vector<Intersection> intersect(Sphere &sphere, Ray &ray);
std::optional<Intersection> hit(std::vector<Intersection> &intersections);

#endif //RAY_GEOMETRY_H
