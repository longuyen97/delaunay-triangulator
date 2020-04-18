#include <cmath>
#include <ostream>
#include <vector>
#include "numerics.hpp"
#include "point.hpp"
#pragma once

namespace tri {
    template<class T>
    class Triangle {
    public:
        Point2D<T> v1;
        Point2D<T> v2;
        Point2D<T> v3;
        bool isBad;

        Triangle(const Point2D<T> &v1, const Point2D<T> &v2, const Point2D<T> &v3) : v1(v1), v2(v2), v3(v3) {
            isBad = false;
        }

        bool contains(Point2D<T> &v) {
            return v == v1 || v == v2 || v == v3;
        }

        bool circumscribedCircleContains(Point2D<T> &v) {
            T ax = v1.x - v.x;
            T ay = v1.y - v.y;
            T bx = v2.x - v.x;
            T by = v2.y - v.y;
            T cx = v3.x - v.x;
            T cy = v3.y - v.y;
            return (ax * ax + ay * ay) *
                   (bx * cy - cx * by) -
                   (bx * bx + by * by) *
                   (ax * cy - cx * ay) +
                   (cx * cx + cy * cy) *
                   (ax * by - bx * ay) > 0;
        }

        bool operator==(const Triangle &rhs) const {
            return (v1 == rhs.v1 && v2 == rhs.v2 && v3 == rhs.v3) ||
                   (v1 == rhs.v2 && v2 == rhs.v3 && v3 == rhs.v1) ||
                   (v1 == rhs.v3 && v2 == rhs.v1 && v3 == rhs.v2);
        }

        bool operator!=(const Triangle &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
            os << "Triangle(v1: " << triangle.v1 << " v2: " << triangle.v2 << " v3: " << triangle.v3 << " isBad: "
               << triangle.isBad << ")";
            return os;
        }
    };
}