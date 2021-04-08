#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"
#include "raytracing.h"
#include "image.h"

void render(const std::vector<Sphere> &spheres) {
    const int width    = 1024;
    const int height   = 1024;
    const float fov    = M_PI/2.;
    Image framebuffer(width, height);

    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            framebuffer.data[i + j * width] = Pixel(j / float(height), i / float(width), 0, 255);
        }
    }

    Point camera = Point(0, 0, -50);
    for (int j = 0; j<height; j++) {
        for (int i = 0; i < width; i++) {
            float x = (float)(i - width / 2.) / width;
            float y = (float)(j - height / 2.) / height;
            Point dir = Point(-camera.x + x, -camera.y + y, -camera.z - 49);
            dir.normalize();
            //std::cout << dir.x << " " << dir.y << " " << dir.z << std::endl;
            framebuffer.data[i + j * width] = cast_ray(Ray(camera, dir), spheres);
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
    Material      ivory(Pixel(0.4, 0.4, 0.3, 1));
    Material red_rubber(Pixel(0.3, 0.1, 0.1, 1));

    std::vector<Sphere> spheres;
    spheres.push_back(Sphere(Point(-3, 0, -16), 2, ivory));
    spheres.push_back(Sphere(Point(-1.0, -1.5, -12), 2, red_rubber));
    spheres.push_back(Sphere(Point( 1.5, -0.5, -18), 3, red_rubber));
    spheres.push_back(Sphere(Point( 7, 5, -18), 4, ivory));

    render(spheres);
    return 0;
}