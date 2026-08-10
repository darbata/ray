//
// Created by Darren Batarina on 8/8/2026.
//

#include "Matrix.h"
#include "Float.h"

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
