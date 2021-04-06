#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"
#include "raytracing.h"
#include "image.h"

void render(const Sphere &sphere) {
    const int width    = 1024;
    const int height   = 768;
    const float fov    = M_PI/2.;
    Image framebuffer(width, height);

    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            framebuffer.data[i + j * width] = Pixel(j / float(height), i / float(width), 0, 255);
        }
    }

    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            float x =  (2*(i + 0.5)/(float)width  - 1) * tan(fov/2.) * width/(float)height;
            float y = -(2*(j + 0.5)/(float)height - 1) * tan(fov/2.);
            Point dir = Point(x, y, -1);
            dir.normalize();
            framebuffer.data[i+j*width] = cast_ray(Ray(dir), sphere);
        }
    }

    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; ++i) {
        ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer.data[i].r)));
        ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer.data[i].g)));
        ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer.data[i].b)));
    }
    ofs.close();
}

int main() {
    Sphere sphere(Point(-3, 0, -16), 2);
    render (sphere);
    return 0;
}