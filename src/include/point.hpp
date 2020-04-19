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

        T norm() const {
            if constexpr (std::is_same_v<T, float>) {
                return std::hypotf(x, y);
            } else if (std::is_same_v<T, double>) {
                return std::hypot(x, y);
            } else {
                return std::sqrt(x * x + y * y);
            }
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