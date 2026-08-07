#include "Canvas.h"

#include <cstdlib>

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->pixels = std::make_unique<Colour[]>(height * width);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            this->pixels[y * width + x] = Colour {0, 0, 0};
        }
    }
}

void Canvas::write_pixel(int x, int y, Colour colour) {
    if (!valid(x, y)) {
        throw std::out_of_range("attempted to access out of bounds");
    }
    this->pixels[y * this->width + x] = colour;
}

Colour Canvas::at(int x, int y) {
    if (!valid(x, y)) {
        throw std::out_of_range("attempted to access out of bounds");
    }
    return this->pixels[y * this->width + x];
}

bool Canvas::valid(int x, int y) {
    return x >= 0 && x < this->width && y >= 0 && y < this->height;
}