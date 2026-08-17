#include <math.h>

#include "Colour.h"
#include "Canvas.h"
#include "Geometry.h"
#include "Matrix.h"
#include "Ray.h"
#include "Tuple.h"

// function builds sphere and draws intersecting lines to
int main() {



    // camera is 10 steps backward from world origin
    // camera is facing directly towards world origin
    Ray camera {
        point(0, 0, -10),
        vector(0, 0, 1)
    };

    // sphere exists at world origin
    Sphere sphere = randomSphere();
    set_transform(sphere, translation(0, 0, -5));

    // canvas is 2D plane that spans x and y (is plane on z-axis)
    // therefore shoot rays from camera origin to each pixel on canvas
    // paint any 'hits' red

    int size = 240;
    Colour red {255, 0, 0};
    Canvas c = Canvas(size, size);

    double wall_size = 30.0;
    double wall_z = 10.0;
    double pixel_size = wall_size / size;
    double half = wall_size / 2;

    int world_z = 10;
    for (int y = 0; y < size; ++y) {
        int world_y = half - pixel_size * y;
        for (int x = 0; x < size; ++x) {
            int world_x = -half + pixel_size * x;

            auto position = point(world_x, world_y, world_z);

            Ray ray {camera.origin, normalise(position - camera.origin)};
            auto intersections = intersect(sphere, ray);
            if (hit(intersections).has_value()) {
                c.write_pixel(x, y, red);
            }
        }
    }

    canvas_to_ppm(&c);
    return 0;
}
