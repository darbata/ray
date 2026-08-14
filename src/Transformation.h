#ifndef RAY_TRANSFORM_H
#define RAY_TRANSFORM_H
#include "Matrix.h"


class Transformation {
private:
    Matrix m;
public:
    Transformation() {
        this->m = identity();
    };

    Transformation translate(float x, float y, float z) {
        this->m = translation(x, y, z) * this->m;
        return *this;
    }

    Transformation scale(float x, float y, float z) {
        this->m = scale(x, y, z) * this->m;
        return *this;
    }

    Transformation rotate_x(float angle) {
        this->m = rotation_x(angle) * this->m;
        return *this;
    };

    Transformation rotate_y(float angle) {
        this->m = rotation_y(angle) * this->m;
        return *this;
    }

    Transformation rotate_z(float angle) {
        this->m = rotation_z(angle) * this->m;
        return *this;
    }

    Transformation shear(float xy, float xz, float yx, float yz, float zx, float zy) {
        this->m = shear(xy, xz, yx, yz, zx, zy);
        return *this;
    }
};

#endif //RAY_TRANSFORM_H