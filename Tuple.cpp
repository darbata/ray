//
// Created by Darren Batarina on 6/8/2026.
//

#include "Tuple.h"

const float epsilon = 0.0001;

bool operator==(Tuple t1, Tuple t2) {
    return (
        t1.x - t2.x < epsilon &&
        t1.y - t2.y < epsilon &&
        t1.z - t2.z < epsilon &&
        t1.w - t2.w < epsilon
    );
}
