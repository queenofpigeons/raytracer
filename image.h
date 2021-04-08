#pragma once
#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include "geometry.h"

struct Pixel {
    float r, g, b, a;

    Pixel(float r, float g, float b, float a) : r{r}, g{g}, b{b}, a{a} {};

    Pixel() : r(0), g(0), b(0), a(0) {};

    void normalize();
};

struct Image {
    int width, height;
    Pixel *data = nullptr;

    Image(int height, int width) : width(width), height(height) {
        data = new Pixel[height * width];
    };

    ~Image() {
        if (data != nullptr){
            delete data;
        }
    }
};
