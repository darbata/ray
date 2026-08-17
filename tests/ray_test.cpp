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
    EXPECT_NE(intersections[0].t, intersections[1].t);
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
    EXPECT_EQ(intersections[0].t, intersections[1].t);
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

    EXPECT_EQ(intersections[0].t, -1.0);
    EXPECT_EQ(intersections[1].t, 1.0);
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
    EXPECT_EQ(intersections[0].t, -6.0);
    EXPECT_EQ(intersections[1].t, -4.0);
}

TEST_F(RayTest, AggregatingIntersects) {
    Sphere s = randomSphere();
    std::vector<Intersection> intersections {Intersection{1, &s}, Intersection{2, &s}};
    EXPECT_EQ(intersections[0].t, 1);
    EXPECT_EQ(intersections[1].t, 2);
}

TEST_F(RayTest, IntersectionIncludesObject) {
    Ray ray {point(0, 0, 5), vector(0, 0, 1)};
    Sphere s = randomSphere();
    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections[0].s, &s);
    EXPECT_EQ(intersections[1].s, &s);
}

TEST_F(RayTest, HitOnPositiveIntersections) {
    Sphere s = randomSphere();
    auto i1 = Intersection{1, &s};
    auto i2 = Intersection{2, &s};
    std::vector<Intersection> intersections {i2, i1};
    auto i = hit(intersections);

    // expect least t value to be considered 'hit'
    EXPECT_EQ(i.value().t, i1.t);
}

TEST_F(RayTest, HitOnSomeNegativeIntersection) {
    Sphere s = randomSphere();
    auto i1 = Intersection{-1, &s};
    auto i2 = Intersection{1, &s};
    std::vector<Intersection> intersections {i2, i1};
    auto i = hit(intersections);

    // only positive considered hits
    EXPECT_TRUE(i.value().t >= 0);
}

TEST_F(RayTest, HitOnAllNegativeIntersection) {
    Sphere s = randomSphere();
    auto i1 = Intersection{-1, &s};
    auto i2 = Intersection{-2, &s};
    std::vector<Intersection> intersections {i2, i1};
    auto i = hit(intersections);

    // only positive considered hits
    EXPECT_TRUE(i.has_value() == false);
}

TEST_F(RayTest, HitOnManyInteresections) {
    Sphere s = randomSphere();
    auto i1 = Intersection{5, &s};
    auto i2 = Intersection{7, &s};
    auto i3 = Intersection{-3, &s};
    auto i4 = Intersection{2, &s};
    std::vector<Intersection> intersections {i1, i2, i3, i4};
    auto i = hit(intersections);

    // always the least non-negative t
    EXPECT_EQ(i.value().t, 2);
}

TEST_F(RayTest, TransformRay) {

    auto o = point(1, 2, 3);
    auto d = vector(0, 1, 0);
    Ray ray {point(1, 2, 3), vector(0, 1, 0)};

    Ray transformed = transform(ray, translation(3, 4, 5));

    Tuple expected = point(4, 6, 8);
    EXPECT_TRUE(transformed.origin == expected);

    // direction unchanged
    EXPECT_EQ(transformed.direction, d);

}

TEST_F(RayTest, SphereDefaultTransformationIsIdentity) {
    Sphere s = randomSphere();
    Matrix expected {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    EXPECT_EQ(expected, s.transform);
}

TEST_F(RayTest, SphereSetTransform) {
    Sphere s = randomSphere();
    Matrix expected {
        {1, 2, 3, 4},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    set_transform(s, expected);
    EXPECT_EQ(expected, s.transform);
}

TEST_F(RayTest, IntersectingScaledSphere) {
    Ray ray {point(0, 0, -5), vector(0, 0, 1)};
    Sphere s = randomSphere();
    auto m = scaling(2, 2, 2);
    set_transform(s, m);

    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections[0].t, 3);
    EXPECT_EQ(intersections[1].t, 7);
}

TEST_F(RayTest, IntersectingTranslatedSphere) {
    Ray ray {point(0, 0, -5), vector(0, 0, 1)};
    Sphere s = randomSphere();
    auto m = translation(5, 0, 0);
    set_transform(s, m);

    auto intersections = intersect(s, ray);
    EXPECT_EQ(intersections.size(), 0);
}
