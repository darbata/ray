//
// Created by Darren Batarina on 8/8/2026.
//

#ifndef RAY_MATRIX_H
#define RAY_MATRIX_H
#include <vector>


typedef std::vector<std::vector<float>> Matrix;

bool operator==(Matrix a, Matrix b);
bool operator!=(Matrix a, Matrix b);

bool operator*(Matrix a, Matrix b);



#endif //RAY_MATRIX_H
