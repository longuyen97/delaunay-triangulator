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

        /**
         * Euclidean distance
         */
        T distance(const Point2D<T> &p) const {
            return nums::hypo(x - p.x, y - p.y);
        }

        /**
         * Squared distance
         */
        T squaredDistance(const Point2D<T> &p) const {
            const T dx = x - p.x;
            const T dy = y - p.y;
            return dx * dx + dy * dy;
        }

        /**
         * Squared norm from (0, 0) to (x, y)
         */
        T squareNorm() const {
            return x * x + y * y;
        }

        /**
         * Squared norm from (0, 0) to (x, y)
         */
        T norm() const {
            return nums::hypo(x, y);
        }

        bool operator==(const Point2D &rhs) const {
            return nums::nearEqual(x, rhs.x) && nums::nearEqual(y, rhs.y);
        }

        bool operator!=(const Point2D &rhs) const {
            return !(rhs == *this);
        }

        /**
         * Compare by norm
         */
        bool operator>(const Point2D &rhs) const {
            return this->norm() > rhs.norm();
        }

        /**
         * Compare by norm
         */
        bool operator<(const Point2D &rhs) const {
            return this->norm() < rhs.norm();
        }

        friend std::ostream &operator<<(std::ostream &os, const Point2D &d) {
            os << "Point(x: " << d.x << " y: " << d.y << ")";
            return os;
        }
    };
}