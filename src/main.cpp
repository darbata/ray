#include <math.h>

#include "Colour.h"
#include "Canvas.h"
#include "Matrix.h"
#include "Tuple.h"

int main() {
    int size = 240;
    Colour white {255, 255, 255};
    Canvas c = Canvas(size, size);

    Tuple twelve {0, 80, 0, 1.0};
    for (int hour = 0; hour < 12; ++hour) {
        Tuple p = rotation_z(hour * M_PI / 6) * twelve;
        int x = static_cast<int>(p.x + size / 2.0);
        int y = static_cast<int>(size / 2.0 - p.y);
        c.write_pixel(x, y, white);
    }


    canvas_to_ppm(&c);
    return 0;
}
