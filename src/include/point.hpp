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

        T distance(const Point2D<T> &p) const {
            return nums::hypo(x - p.x, y - p.y);
        }

        T distance2(const Point2D<T> &p) const {
            const T dx = x - p.x;
            const T dy = y - p.y;
            return dx * dx + dy * dy;
        }

        T norm2() const {
            return x * x + y * y;
        }

        T norm() const {
            return nums::hypo(x, y);
        }

        bool operator==(const Point2D &rhs) const {
            return nums::nearEqual(x, rhs.x) && nums::nearEqual(y, rhs.y);
        }

        bool operator!=(const Point2D &rhs) const {
            return !(rhs == *this);
        }

        bool operator>(const Point2D &rhs) const {
            return this->norm() > rhs.norm();
        }

        bool operator<(const Point2D &rhs) const {
            return this->nor() < rhs.norm();
        }

        friend std::ostream &operator<<(std::ostream &os, const Point2D &d) {
            os << "Point(x: " << d.x << " y: " << d.y << ")";
            return os;
        }
    };
}