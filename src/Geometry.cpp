#include "Geometry.h"

#include <complex>

float discriminant(Sphere sphere, Ray ray);

Sphere randomSphere() {
    Tuple origin = point(0, 0, 0);
    float radius = 1.0;
}

std::vector<float> intersect(Sphere sphere, Ray ray) {

    // determines if ray intersect with ray at all use 'discriminant'
    Tuple sphere_to_ray = ray.origin - point(0, 0, 0);

    auto a = dot(ray.direction, ray.direction);
    auto b = 2 * dot(ray.direction, sphere_to_ray);
    auto c = dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = b*b - 4 * a * c;

    if (discriminant < 0) {
        return {};
    }

    // now ray must intersect at least once or twice
    // find t solutions where ray intersects with sphere
    return {
        (-b - sqrt(discriminant)) / (2*a),
        (-b + sqrt(discriminant)) / (2*a)
    };
}

