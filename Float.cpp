#include "Float.h"

#include <cmath>
#include <iostream>
#include <ostream>

const float epsilon = 0.00001f;

bool compare(float f1, float f2) {
    return fabs(f1 - f2) <= epsilon;
}


