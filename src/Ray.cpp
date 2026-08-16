#include "Ray.h"

// Scale direction by some scalar `t`. May also be interpreted as 'time'.
// Add origin offset.
Tuple position(Ray ray, float t) {
    return ray.origin + ray.direction * t;
}

void transform(Ray &ray, Matrix transformation) {
    ray.origin = transformation * ray.origin;
}