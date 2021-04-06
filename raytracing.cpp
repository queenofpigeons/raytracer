#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include "raytracing.h"

bool Sphere::ray_intersect(const Ray &dir, float &t0) const{
    Point L = center - dir.start;
    float tca = L * dir.end;
    float d2 = L * L - tca * tca;
    if (d2 > radius * radius)
        return false;
    float thc = sqrtf(radius * radius - d2);
    t0       = tca - thc;
    float t1 = tca + thc;
    if (t0 < 0) t0 = t1;
    if (t0 < 0) return false;
    return true;
}

Pixel cast_ray(const Ray &dir, const Sphere &sphere) {
    float sphere_dist = std::numeric_limits<float>::max();
    if (!sphere.ray_intersect(dir, sphere_dist)) {
        return Pixel(0.8, 0.2, 0.7, 1);
    }
    return Pixel(0.4, 0.4, 0.3, 1);
}