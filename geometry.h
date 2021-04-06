#pragma once
#include <cmath>
#include <array>
#include <cassert>
#include <iostream>

struct Point {
    int x, y, z;

    Point(int x, int y, int z) : x{x}, y{y}, z{z} {};
    Point() : x(0), y(0), z(0) {};

    const Point operator+(const Point& rv) const {
        return Point(x + rv.x, y + rv.y, z + rv.z);
    }
    const Point operator-(const Point& rv) const {
        return Point(x - rv.x, y - rv.y, z - rv.z);
    }
    const float operator*(const Point& rv) const {
        return x * rv.x + y * rv.y + z * rv.z;
    }

    void normalize();
};

struct Ray {
    Point start, end;

    Ray(const Point &start, const Point &end) : start(start), end(end) {};
    Ray(const Point &end) : end(end) {
        start = Point(0, 0, 0);
    };

    const Ray operator+(const Ray& rv) const {
        return Ray(start + rv.start, end + rv.end);
    }
    const Ray operator-(const Ray& rv) const {
        return Ray(start - rv.start, end - rv.end);
    }
};