#include "Ray.h"

// Scale direction by some scalar `t`. May also be interpreted as 'time'.
// Add origin offset.
Tuple position(Ray ray, float t) {
    return ray.origin + ray.direction * t;
}

Ray transform(const Ray &ray, const Matrix &transform) {
    return {
        transform * ray.origin,
        transform * ray.direction
    };
}
