#include <cmath>
#include <ostream>
#include <vector>
#include "numerics.hpp"
#pragma once

namespace tri {
    template<class T> class Point2D;
    template<class T>class Point2D {
    public:
        T x;
        T y;

        Point2D(T x, T y) : x(x), y(y) {}

        bool operator==(const Point2D &rhs) const {
            return nums::nearEqual(x, rhs.x) && nums::nearEqual(y, rhs.y);
        }

        bool operator!=(const Point2D &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Point2D &d) {
            os << "Point(x: " << d.x << " y: " << d.y << ")";
            return os;
        }
    };
}