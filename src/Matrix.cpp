#include "Matrix.h"
#include "Float.h"
#include "Tuple.h"

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