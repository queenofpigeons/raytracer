#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include "geometry.h"

void Point::normalize() {
    float norm = sqrt(*this * *this);
    x /= norm;
    y /= norm;
    z /= norm;
}