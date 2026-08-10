//
// Created by Darren Batarina on 6/8/2026.
//

#ifndef RAY_CANVAS_H
#define RAY_CANVAS_H
#include <cstddef>
#include <memory>

#include "Colour.h"

class Canvas {
public:
    std::size_t height, width;
    Canvas(int width, int height);
    void write_pixel(int x, int y, Colour colour);
    Colour at(int x, int y);
private:
    std::unique_ptr<Colour[]> pixels;
    bool valid(int x, int y);
};

void canvas_to_ppm(Canvas* canvas);

#endif //RAY_CANVAS_H
