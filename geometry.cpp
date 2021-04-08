#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include "geometry.h"

void Point::normalize() {
    float norm = sqrt(x*x + y*y + z*z);
    x /= norm;
    y /= norm;
    z /= norm;
}