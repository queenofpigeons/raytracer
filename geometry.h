#pragma once
#include <cmath>
#include <array>
#include <cassert>
#include <iostream>

struct Point {
    float x, y, z;

    Point(float x, float y, float z) : x{x}, y{y}, z{z} {};
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
    const Point operator*(const float rv) const {
        return Point(x * rv, y * rv, z * rv);
    }

    void normalize();
};

struct Ray {
    Point p, vec;

    Ray(const Point &start, const Point &end) : p(start), vec(end) {};
    Ray(const Point &end) : vec(end) {
        p = Point(0, 0, 0);
    };
};