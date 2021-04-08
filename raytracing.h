#pragma once
#include <cmath>
#include <array>
#include <cassert>
#include <iostream>
#include "image.h"

struct Sphere {
    Point center;
    float radius;
    Material material;

    Sphere(const Point &c, const float &r, const Material &material) : center(c), radius(r), material(material) {}

    bool ray_intersect(const Ray &dir, float &t0) const;
};

Pixel cast_ray(const Ray &dir, const Sphere &sphere);

bool scene_intersect(const Ray &dir, const std::vector<Sphere> &spheres, Point &hit, Point &N, Material &material);

struct Material {
    Pixel color;

    Material(const Pixel &color) : color(color) {}
    Material() : color() {}
};