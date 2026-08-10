#include "Tuple.h"
#include "gtest/gtest.h"

class TupleTest : public ::testing::Test {
protected:
    Tuple point{4.3, -4.2, 3.1, 1.0};
    Tuple vector{4.3, -4.2, 3.1, 0.0};
};

TEST_F(TupleTest, TupleWithWOneIsAPoint) {
    EXPECT_TRUE(isPoint(point));
    EXPECT_FALSE(isVector(point));
}

TEST_F(TupleTest, TupleWithWZeroIsAVector) {
    EXPECT_TRUE(isVector(vector));
    EXPECT_FALSE(isPoint(vector));
}

TEST_F(TupleTest, Addition) {
    EXPECT_EQ(point + vector, (Tuple{8.6, -8.4, 6.2, 1.0}));
}

TEST_F(TupleTest, Subtraction) {
    EXPECT_EQ(point - vector, (Tuple{0.0, 0.0, 0.0, 1.0}));
}

TEST_F(TupleTest, Negation) {
    EXPECT_EQ(-vector, (Tuple{-4.3, 4.2, -3.1, 0.0}));
}

TEST_F(TupleTest, ScalarMultiplication) {
    EXPECT_EQ(2 * vector, (Tuple{8.6, -8.4, 6.2, 0.0}));
}

TEST_F(TupleTest, ScalarDivision) {
    EXPECT_EQ(vector / 2, (Tuple{2.15, -2.10, 1.55, 0.0}));
}

TEST(TupleMagnitude, UnitAxesHaveMagnitudeOne) {
    EXPECT_TRUE(compare(magnitude(Tuple{1, 0, 0, 0.0}), 1.0));
    EXPECT_TRUE(compare(magnitude(Tuple{0, 1, 0, 0.0}), 1.0));
    EXPECT_TRUE(compare(magnitude(Tuple{0, 0, 1, 0.0}), 1.0));
}

TEST(TupleMagnitude, ArbitraryVector) {
    EXPECT_TRUE(compare(magnitude(Tuple{1, 2, 3, 0.0}), std::sqrt(14.0)));
}

TEST(TupleMagnitude, NormalisedTupleHasMagnitudeOne) {
    Tuple t{4.3, -4.2, 3.1, 1.0};
    EXPECT_TRUE(compare(magnitude(normalise(t)), 1.0));
}

TEST(TupleProducts, DotProduct) {
    EXPECT_TRUE(compare(dot(Tuple{1, 2, 3, 0.0}, Tuple{2, 3, 4, 0.0}), 20.0));
}

TEST(TupleProducts, CrossProduct) {
    EXPECT_EQ(cross(Tuple{1, 2, 3, 0.0}, Tuple{2, 3, 4, 0.0}),
              (Tuple{-1, 2, -1, 0.0}));
}

TEST(TupleProducts, CrossProductIsAntiCommutative) {
    Tuple a{1, 2, 3, 0.0};
    Tuple b{2, 3, 4, 0.0};
    EXPECT_EQ(cross(b, a), (Tuple{1, -2, 1, 0.0}));
}