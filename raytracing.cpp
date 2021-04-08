#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits>
#include "raytracing.h"

bool Sphere::ray_intersect(const Ray &dir, float &t0) const{
    Point L = center - dir.p;
    float tca = L * dir.vec;
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

bool scene_intersect(const Ray &dir, const std::vector<Sphere> &spheres, Point &hit, Point &N, Material &material) {
    float spheres_dist = std::numeric_limits<float>::max();
    for (size_t i = 0; i < spheres.size(); i++) {
        float dist_i;
        if (spheres[i].ray_intersect(dir, dist_i) && dist_i < spheres_dist) {
            spheres_dist = dist_i;
            hit = dir.p + dir.vec * dist_i;
            N = hit - spheres[i].center;
            N.normalize();
            material = spheres[i].material;
        }
    }
    return spheres_dist < 1000;
}

Pixel cast_ray(const Ray &dir, const std::vector<Sphere> &spheres) {
    float sphere_dist = std::numeric_limits<float>::max();
    Point point, N;
    Material material;
    if (!scene_intersect(dir, spheres, point, N, material)) {
        return Pixel(0.1, 0.1, 0.1,1);
    }
    return material.color;
    /*
    if (sphere.ray_intersect(dir, sphere_dist)) {
        return Pixel(0.2, 0.2, 0.3, 1);
        //return Pixel((dir.p.x + 1) / 2 * 255, (dir.p.y + 1) / 2 * 255, (dir.p.z + 1) / 2 * 255, 1);
    } 
    //return Pixel(0.8, 0.2, 0.7, 1);
    return Pixel((dir.vec.x + 1.) / 2, (dir.vec.y + 1.) / 2, (dir.vec.z + 1.) / 2, 1);
    */
}