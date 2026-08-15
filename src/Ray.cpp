#include "Ray.h"

Ray::Ray(const Tuple origin, const Tuple direction) {
    if (!isPoint(origin) || !isVector(direction)) {
        throw std::invalid_argument("origin must be a point and direction must be a vector");
    }
    this->origin = origin;
    this->direction = direction;
}

Tuple Ray::getOrigin() const {
    return this->origin;
}

Tuple Ray::getDirection() const {
    return this->direction;
}