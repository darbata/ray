#include "Geometry.h"

#include <complex>

float discriminant(Sphere sphere, Ray ray);

Sphere randomSphere() {
    Tuple origin = point(0, 0, 0);
    float radius = 1.0;
    return {origin, radius};
}

std::vector<Intersection> intersect(Sphere &sphere, Ray &ray) {

    // apply sphere transformation
    // can't transform sphere directly, so transform world space (including ray) itself by the inverse
    auto localRay = transform(ray, inverse(sphere.transform));

    // determines if ray intersect with ray at all use 'discriminant'
    Tuple sphere_to_ray = localRay.origin - point(0, 0, 0);

    auto a = dot(localRay.direction, localRay.direction);
    auto b = 2 * dot(localRay.direction, sphere_to_ray);
    auto c = dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = b*b - 4 * a * c;

    if (discriminant < 0) {
        return {};
    }

    // now ray must intersect at least once or twice
    // find t solutions where ray intersects with sphere

    Intersection i1 {
        (-b - sqrt(discriminant)) / (2*a),
        &sphere
    };

    Intersection i2 {
        (-b + sqrt(discriminant)) / (2*a),
        &sphere
    };

    return {i1, i2};
}


std::optional<Intersection> hit(std::vector<Intersection> &intersections) {
    std::optional<Intersection> i;
    float min_t = std::numeric_limits<float>::max();
    for (auto &intersection : intersections) {
        if (intersection.t > min_t || intersection.t < 0) {
            continue;
        }

        if (intersection.t < min_t) {
            min_t = intersection.t;
            i = intersection;
        }
    }

    return i;
}

void set_transform(Sphere &sphere, const Matrix &transform) {
    sphere.transform = transform;
}

