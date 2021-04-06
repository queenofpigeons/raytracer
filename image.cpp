#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include "image.h"

int Pixel::normalize(float f) {
    int res = f * 255;
    return res;
}