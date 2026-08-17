#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include <optional>

#include "Ray.h"
#include <vector>


struct Sphere  {
    Tuple origin;
    float radius;
    Matrix transform = identity();
};

struct Intersection {
    float t;
    Sphere* s;
};

Sphere randomSphere();

std::vector<Intersection> intersect(Sphere &sphere, Ray &ray);
std::optional<Intersection> hit(std::vector<Intersection> &intersections);

void set_transform(Sphere& sphere, Matrix& transform);
Ray transform(const Ray &ray, const Matrix& transform);




#endif //RAY_GEOMETRY_H
