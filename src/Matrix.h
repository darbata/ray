#ifndef RAY_MATRIX_H
#define RAY_MATRIX_H
#include <vector>

typedef std::vector<std::vector<float>> Matrix;

bool operator==(Matrix a, Matrix b);
bool operator!=(Matrix a, Matrix b);

Matrix operator*(const Matrix& a, const Matrix& b);

#endif //RAY_MATRIX_H
