#ifndef RAY_RAY_H
#define RAY_RAY_H

#include "Tuple.h"

class Ray {
private:
    Tuple origin{};
    Tuple direction{};
public:
    Ray(Tuple origin, Tuple direction);
    Tuple getOrigin() const;
    Tuple getDirection() const;
};


#endif //RAY_RAY_H
