#ifndef RAY_MATRIX_H
#define RAY_MATRIX_H
#include <vector>

#include "Tuple.h"

typedef std::vector<std::vector<float>> Matrix;

bool operator==(Matrix a, Matrix b);
bool operator!=(Matrix a, Matrix b);

Matrix operator*(const Matrix& a, const Matrix& b);
Tuple operator*(const Matrix& a, const Tuple& b);

Matrix transpose(const Matrix& a);
Matrix submatrix(const Matrix& a, int row, int col);
Matrix inverse(const Matrix& a);
Matrix translation(float x, float y, float z);
Matrix scaling(float x, float y, float z);
Matrix rotation_x(float angle);
Matrix rotation_y(float angle);
Matrix rotation_z(float angle);

float determinant(const Matrix& a);
float minor(const Matrix& a, int row, int col);
float cofactor(const Matrix& a, int row, int col);

#endif //RAY_MATRIX_H
