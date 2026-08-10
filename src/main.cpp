#include "Colour.h"
#include "Canvas.h"

int main() {
    Canvas c = Canvas(40, 40);
    printColour(c.at(20, 20));
    c.write_pixel(20, 20, Colour{0.5, 1.0, 0.5});
    printColour(c.at(20, 20));
    canvas_to_ppm(&c);
    return 0;
}