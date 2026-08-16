#include <gtest/gtest.h>
#include <expected>

#include "Geometry.h"
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

TEST_F(RayTest, RayIntersectsSphereAtTwoPoints) {
    Ray ray {
        point(0, 0, -5),
        vector(0, 0, 1)
    };
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections.size(), 2);

    // not the same intercept
    EXPECT_NE(intersections[0], intersections[1]);
}

TEST_F(RayTest, RayIntersectsAtTangent) {
    Ray ray {
        point(0, 1, -5),
        vector(0, 0, 1)
    };
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections.size(), 2);

    // same intercept
    EXPECT_EQ(intersections[0], intersections[1]);
}

TEST_F(RayTest, NoIntercept) {
    Ray ray {
        point(0, 2, -5),
        vector(0, 0, 1)
    };
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections.size(), 0);
}

TEST_F(RayTest, RayInsideSphere) {
    Ray ray {
        point(0, 0, 0),
        vector(0, 0, 1)
    };
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections.size(), 2);

    EXPECT_EQ(intersections[0], -1.0);
    EXPECT_EQ(intersections[1], 1.0);
}

TEST_F(RayTest, SphereBehindRay) {
    Ray ray {
        point(0, 0, 5),
        vector(0, 0, 1)
    };
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);

    // rays travel infinitely in both directions
    // therefore intersects in opposite direction to direction vector of ray
    EXPECT_EQ(intersections[0], -6.0);
    EXPECT_EQ(intersections[1], -4.0);
}