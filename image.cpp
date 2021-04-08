#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include "image.h"

void Pixel::normalize() {
    r *= 255;
    g *= 255;
    b *= 255;
}