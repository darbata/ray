#include "gtest/gtest.h"
#include "Colour.h"

TEST(ColourTest, ComponentsAreStored) {
    Colour c{-0.5, 0.4, 1.7};
    EXPECT_TRUE(compare(c.r, -0.5));
    EXPECT_TRUE(compare(c.g, 0.4));
    EXPECT_TRUE(compare(c.b, 1.7));
}

TEST(ColourTest, Addition) {
    EXPECT_EQ(Colour({0.9, 0.6, 0.75}) + Colour({0.7, 0.1, 0.25}),
              (Colour{1.6, 0.7, 1.0}));
}

TEST(ColourTest, Subtraction) {
    EXPECT_EQ(Colour({0.9, 0.6, 0.75}) - Colour({0.7, 0.1, 0.25}),
              (Colour{0.2, 0.5, 0.5}));
}

TEST(ColourTest, ScalarMultiplication) {
    EXPECT_EQ(2 * Colour({0.2, 0.3, 0.4}), (Colour{0.4, 0.6, 0.8}));
}
