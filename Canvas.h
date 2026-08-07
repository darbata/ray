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
    Canvas(int width, int height);
    void write_pixel(int x, int y, Colour colour);
    Colour at(int x, int y);
private:
    std::size_t height, width;
    std::unique_ptr<Colour[]> pixels;
    bool valid(int x, int y);
};


#endif //RAY_CANVAS_H
