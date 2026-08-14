#include "Matrix.h"

#include <iostream>

#include "Float.h"
#include "Tuple.h"

void print_matrix(const Matrix &a);

bool operator==(Matrix a, Matrix b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (!compare(a[i][j], b[i][j])) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(Matrix a, Matrix b) {
    return !(a == b);
}
Matrix operator* (const Matrix& a, const Matrix& b) {
    if (a[0].size() != b.size()) {
        throw std::logic_error("Matrix multiplication not possible");
    }

    if (a.size() != 4 || a[0].size() != 4) {
        throw std::logic_error("Have only implemented 4x4 matrices");
    }

    auto height = a.size();
    auto width = b[0].size();

    Matrix result(height, std::vector<float>(width, 0.0f));

    for (int i = 0; i < height; i++) {
        Tuple a_row_vec {a[i][0], a[i][1], a[i][2], a[i][3]};
        for (int j = 0; j < width; j++) {
            Tuple b_col_vec {b[0][j], b[1][j], b[2][j], b[3][j]};
            result[i][j] = dot(a_row_vec, b_col_vec);
        }
    }

    return result;
}

Tuple operator*(const Matrix &A, const Tuple &v) {
    std::vector<float> dimensions {};
    for (const auto & i : A) {
        Tuple a_row_vec {i[0], i[1], i[2], i[3]};
        dimensions.push_back(dot(a_row_vec, v));
    }

    return Tuple(dimensions[0], dimensions[1], dimensions[2], dimensions[3]);
}

Matrix transpose(const Matrix &a) {
    auto height = a.size();
    auto width = a[0].size();

    Matrix result(width, std::vector<float>(height, 0.0f));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result[i][j] = a[j][i];
        }
    }

    return result;
}

Matrix submatrix(const Matrix &a, int row, int col) {
    // return matrix with row and column removed
    if (row < 0 || row >= a.size() || col < 0 || col >= a[0].size()) {
        throw std::logic_error("Matrix submatrix not possible");
    }

    Matrix result {};

    for (int i = 0; i < a.size(); i++) {
        if (i == row) continue;
        result.emplace_back();
        for (int j = 0; j < a[0].size(); j++) {
            if (j == col) continue;
            result.back().push_back(a[i][j]);
        }
    }


    return result;

}

Matrix inverse(const Matrix &a) {
    auto d = determinant(a);
    if (d == 0) {
        throw std::logic_error("Matrix invert not possible as determinant is 0");
    }

    Matrix result {};

    for (int i = 0; i < a.size(); i++) {
        result.emplace_back();
        for (int j = 0; j < a[0].size(); j++) {
            auto c = cofactor(a, i, j) / d;
            result.back().push_back(c);
        }
    }

    return transpose(result);
}

Matrix translation(float x, float y, float z) {
    return {
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1},
    };
}

// scale by negative value to achieve reflection
Matrix scaling(float x, float y, float z) {
    return {
        {x, 0, 0, 0},
        {0, y, 0, 0},
        {0, 0, z, 0},
        {0, 0, 0, 1},
    };
}

Matrix rotation_x(float angle) {
    return {
        {1, 0, 0, 0},
        {0, cosf(angle), -sinf(angle), 0},
        {0, sinf(angle), cosf(angle), 0},
        {0, 0, 0, 1}
    };
}

Matrix rotation_y(float angle) {
    return {
        {cosf(angle), 0, sinf(angle), 0},
        {0, 1, 0, 0},
        {-sinf(angle), 0, cosf(angle), 0},
        {0, 0, 0, 1}
    };
}

Matrix rotation_z(float angle) {
    return {
        {cosf(angle), -sinf(angle), 0, 0},
        {sinf(angle), cosf(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
}

Matrix shear(float xy, float xz, float yx, float yz, float zx, float zy) {
    return {
        {1, xy, xz, 0},
        {yx, 1, yz, 0},
        {zx, zy, 1, 0},
        {0, 0, 0, 1}
    };
}

float determinant(const Matrix &a) {
    if (a.size() != a[0].size()) {
        throw std::logic_error("Matrix determinant not possible on non-square matrix");
    }

    if (a.size() == 2) {
        return (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
    }

    float d {};

    for (int col = 0; col < a[0].size(); col++) {
        d += a[0][col] *  cofactor(a, 0, col);
    }

    return d;
}

float minor(const Matrix &a, int row, int col) {
    return determinant(submatrix(a, row, col));
}

float cofactor(const Matrix &a, int row, int col) {
    float m = minor(a, row, col);
    return (row + col) % 2 == 0 ? m : float(0.0 - m);
}

void print_matrix(const Matrix &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


