#include "Canvas.h"

#include <algorithm>
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

int clamp(float colour_value) {
    const int MAX_COLOUR_VALUE = 255;
    return std::clamp(int(colour_value*MAX_COLOUR_VALUE), 0, MAX_COLOUR_VALUE);
}

void canvas_to_ppm(Canvas *canvas) {
    std::ofstream ppm;
    ppm.open("canvas.ppm");

    if (!ppm.is_open()) {
        throw std::logic_error("canvas_to_ppm() could not open");
    }

    // the dimensions of the image and the maximum colour value for either r, g or b
    // PPM only integer values
    ppm << "P3" << std::endl;


    ppm << canvas->width << " " << canvas->height << " " << 255 << std::endl;

    for (int y = 0; y < canvas->height; ++y) {
        for (int x = 0; x < canvas->width; ++x) {
            Colour colour = canvas->at(x, y);
            ppm << clamp(colour.r) << " " << clamp(colour.g) << " " << clamp(colour.b);
            if (x != canvas->width - 1) {
                ppm << "   ";
            } else {
                ppm << std::endl;
            }
        }
    }

    ppm.close();
}

