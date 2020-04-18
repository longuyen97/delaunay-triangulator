#ifndef TRIANGULATION_POINT_HPP
#define TRIANGULATION_POINT_HPP

#include <cmath>
#include <ostream>
#include <vector>
#include "numerics.hpp"

namespace tri {
    template<typename T> class Point2D;

    template<typename T>class Point2D {
    public:
        T x;
        T y;

        Point2D(T x, T y) : x(x), y(y) {}

        T distance(const Point2D<T> &p) {
            if constexpr (std::is_same_v<T, float>) {
                return std::hypotf(x - p.x, y - p.y);
            } else if (std::is_same_v<T, double>) {
                return std::hypot(x - p.x, y - p.y);
            } else {
                return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
            }
        }

        T distance2(const Point2D<T> &p) {
            const T dx = x - p.x;
            const T dy = y - p.y;
            return dx * dx + dy * dy;
        }

        T norm() {
            if constexpr (std::is_same_v<T, float>) {
                return std::hypotf(x, y);
            } else if (std::is_same_v<T, double>) {
                return std::hypot(x, y);
            } else {
                return std::sqrt(x * x + y * y);
            }
        }

        T norm2() {
            return x * x + y * y;
        }

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

#endif