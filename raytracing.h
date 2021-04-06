#pragma once
#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include "image.h"

struct Sphere {
    Point center;
    float radius;

    Sphere(const Point &c, const float &r) : center(c), radius(r) {}

    bool ray_intersect(const Ray &dir, float &t0) const;
};

Pixel cast_ray(const Ray &dir, const Sphere &sphere);