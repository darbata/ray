#include "Canvas.h"

#include <cstdlib>
#include <filesystem>
#include <fstream>

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

void canvas_to_ppm(Canvas *canvas) {
    std::ofstream ppm;
    ppm.open("canvas.ppm");

    if (!ppm.is_open()) {
        throw std::logic_error("canvas_to_ppm() could not open");
    }

    // the dimensions of the image and the maximum colour value for either r, g or b
    ppm << "P3" << std::endl;
    ppm << canvas->width << " " << canvas->height << " " << 1.0 << std::endl;

    for (int y = 0; y < canvas->height; ++y) {
        for (int x = 0; x < canvas->width; ++x) {
            Colour colour = canvas->at(x, y);
            ppm << colour.r << " " << colour.g << " " << colour.b;

            if (x != canvas->width - 1) {
                ppm << "   ";
            } else {
                ppm << std::endl;
            }
        }
    }

    ppm.close();
}