#include "../src/Matrix.h"
#include <gtest/gtest.h>

class MatrixTest : public ::testing::Test {
protected:
    Matrix m = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5},
    };
};

TEST_F(MatrixTest, Indexing) {
    EXPECT_TRUE(compare(m[0][0], 1.0));
    EXPECT_TRUE(compare(m[3][3], 16.5));
}

TEST_F(MatrixTest, EqualWhenAllElementsMatch) {
    Matrix n = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5},
    };
    EXPECT_EQ(m, n);
}

TEST_F(MatrixTest, NotEqualWhenAnyElementDiffers) {
    Matrix o = {
        {1, 2, 3, 4},
        {5.4, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5},
    };
    EXPECT_NE(m, o);
}
