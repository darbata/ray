#include <expected>

#include "../src/Matrix.h"
#include <gtest/gtest.h>

#include "Tuple.h"

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


TEST_F(MatrixTest, MatrixMatrixMultiplication) {
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };
    Matrix B = {
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}
    };

    Matrix expected = {
        {20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}
    };

    EXPECT_EQ(A*B, expected);
}

TEST_F(MatrixTest, MatrixVectorMultiplication) {
    Matrix A {
        {1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1} // identity last row
    };

    Tuple v {1, 2, 3, 1};

    Tuple expected {18, 24, 33, 1};
    Tuple result = A*v;

    EXPECT_EQ(expected, result);
}

TEST_F(MatrixTest, IdentityMatrixMatrixMultiplication) {
    Matrix I {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    Matrix A {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    EXPECT_EQ(I*A, A);
}

TEST_F(MatrixTest, IdentityMatrixVectorMultiplication) {
    Matrix I {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    Tuple v {1, 2, 3, 1};
    EXPECT_EQ(I*v, v);
}

TEST_F(MatrixTest, TransposeMatrix) {
    Matrix A {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    Matrix transposed {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };

    EXPECT_EQ(transpose(A), transposed);
}

TEST_F(MatrixTest, Submatrix4) {
    Matrix A {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // delete row 1 and column 2 (0-index)
    Matrix expected {
        {1, 2, 4},
        {9, 10, 12},
        {13, 14, 16}
    };

    EXPECT_EQ(submatrix(A, 1, 2), expected);
}

TEST_F(MatrixTest, Submatrix2) {
    Matrix A {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    Matrix  expected {
        {4, 5},
        {7, 8},
    };

    EXPECT_EQ(submatrix(A, 0, 2), expected);
}

TEST_F(MatrixTest, MinorAndCofactor) {
    Matrix A {
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    };

    EXPECT_EQ(minor(A, 0, 0), -12);
    EXPECT_EQ(cofactor(A, 0, 0), -12);
    EXPECT_EQ(minor(A, 1, 0), 25);
    EXPECT_EQ(cofactor(A, 1, 0), -25);
}

TEST_F(MatrixTest, Determinant3) {
    Matrix A {
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}
    };

    EXPECT_EQ(cofactor(A, 0, 0), 56);
    EXPECT_EQ(cofactor(A, 0, 1), 12);
    EXPECT_EQ(cofactor(A, 0, 2), -46);
    EXPECT_EQ(determinant(A), -196);
}

TEST_F(MatrixTest, Determinant4) {
    Matrix A {
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}
    };

    EXPECT_EQ(cofactor(A, 0, 0), 690);
    EXPECT_EQ(cofactor(A, 0, 1), 447);
    EXPECT_EQ(cofactor(A, 0, 2), 210);
    EXPECT_EQ(cofactor(A, 0, 3), 51);
    EXPECT_EQ(determinant(A), -4071);
}

// Testing an invertible matrix for invertibility
// |  6 |  4 |  4 |  4 |
// |  5 |  5 |  7 |  6 |
// |  4 | -9 |  3 | -7 |
// |  9 |  1 |  7 | -6 |
// determinant(A) = -2120
// A is invertible
//
// Testing a noninvertible matrix for invertibility
// Given the following 4x4 matrix A:
//  	    | -4 |  2 | -2 | -3 |
//  	    |  9 |  6 |  2 |  6 |
//  	    |  0 | -5 |  1 | -5 |
//  	    |  0 |  0 |  0 |  0 |
//Then determinant(A) = 0

TEST_F(MatrixTest, InvertibleMatrix) {
    Matrix A {
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}
    };

    // Matrix is invertible
    EXPECT_EQ(determinant(A), -2120);
}

TEST_F(MatrixTest, NonInvertibleMatrix) {
    Matrix A {
        {-4, 2, -2, -3},
        {9, 6, 2, 6},
        {0, -5, 1, -5},
        {0, 0, 0, 0}
    };

    // Matrix is NOT invertible
    EXPECT_EQ(determinant(A), 0);
}

TEST_F(MatrixTest, InvertMatrix) {
    Matrix A {
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}
    };

    Matrix expected {
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    };

    EXPECT_EQ(determinant(A), 532);
    EXPECT_EQ(cofactor(A, 2, 3), -160);
    EXPECT_EQ(cofactor(A, 3, 2), 105);
    EXPECT_TRUE(inverse(A)==expected);
}

TEST_F(MatrixTest, InvertMatrix2) {
    Matrix A {
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    };

    Matrix expected {
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    };

    EXPECT_TRUE(inverse(A) == expected);
}

TEST_F(MatrixTest, InvertMatrix3) {
    Matrix A {
        {9, 3, 0, 9},
        {-5, -2, -6, -3},
        {-4, 9, 6, 4},
        {-7, 6, 6, 2}
    };

    Matrix expected {
        {-0.04074, -0.07778, 0.14444, -0.22222},
        {-0.07778, 0.03333, 0.36667, -0.33333},
        {-0.02901, -0.14630, -0.10926, 0.12963},
        {0.17778, 0.06667, -0.26667, 0.33333}
    };

    EXPECT_TRUE(inverse(A) == expected);
}

TEST_F(MatrixTest, NegateTransformationUsingInverse) {
    Matrix A {
        {3, -9, 7, 3},
        {3, -8, 2, -9},
        {-4, 4, 4, 1},
        {-6, 5, -1, -1}
    };

    Matrix B {
        {8, 2, 2, 2},
        {3, -1, 7, 0},
        {7, 0, 5, 4},
        {6, -2, 0, 5}
    };

    Matrix C = A * B;

    EXPECT_TRUE(C * inverse(B) == A);
}

TEST_F(MatrixTest, Translation) {
    Tuple point {-3, 4, 5, 1};
    Tuple expected {2, 1, 7, 1};
    EXPECT_TRUE(translation(5, -3, 2) * point == expected);
}

TEST_F(MatrixTest, InverseTranslation) {
    // inverse translation moves point in opposite direction
    Tuple point {-3, 4, 5, 1};
    Tuple expected {-8, 7, 3, 1};
    EXPECT_TRUE(inverse(translation(5, -3, 2)) * point == expected);
}

TEST_F(MatrixTest, TranslationIgnoresVectors) {
    Tuple v {-3, 4, 5, 0};
    EXPECT_TRUE(translation(5, -3, 2) * v == v);
}

TEST_F(MatrixTest, ScalingPoint) {
    Tuple p {-4, 6, 8, 1};
    Tuple expected {-8, 18, 32, 1};
    EXPECT_TRUE(scaling(2, 3, 4) * p == expected);
}

TEST_F(MatrixTest, ScalingVector) {
    Tuple v {-4, 6, 8, 0};
    Tuple expected {-8, 18, 32, 0};
    EXPECT_TRUE(scaling(2, 3, 4) * v == expected);
}

TEST_F(MatrixTest, ScalingVectorByInverse) {
    Tuple v {-4, 6, 8, 0};
    Tuple expected {-2, 2, 2, 0};
    EXPECT_TRUE(inverse(scaling(2, 3, 4)) * v == expected);
}

TEST_F(MatrixTest, ReflectionByScaling) {
    Tuple v {-4, 6, 8, 0};
    Tuple expected {4, 6, 8, 0};
    EXPECT_TRUE(scaling(-1, 1, 1) * v == expected);
}