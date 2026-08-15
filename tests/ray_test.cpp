#include <gtest/gtest.h>
#include <expected>

#include "Ray.h"

class RayTest : public ::testing::Test {};

TEST_F(RayTest, QueryRay) {
    Tuple origin {1, 2, 3, 1};
    Tuple direction {4, 5, 6, 0};
    Ray ray {origin, direction};

    EXPECT_EQ(ray.origin, origin);
    EXPECT_EQ(ray.direction, direction);
}
