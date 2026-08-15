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

TEST_F(RayTest, FindingPositionOnRayTravel) {
    Tuple origin = point(2, 3, 4);
    Tuple direction = vector(1, 0, 0);
    Ray ray {origin, direction};

    EXPECT_EQ(position(ray, 0), origin);
    EXPECT_EQ(position(ray, 1), point(3, 3, 4));
    EXPECT_EQ(position(ray, -1), point(1, 3, 4));
    EXPECT_EQ(position(ray, 2.5), point(4.5, 3, 4));
}

