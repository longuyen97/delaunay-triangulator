#include <cmath>
#include <ostream>
#include <vector>
#include "point.hpp"
#include "numerics.hpp"
#pragma once

namespace tri {
    template<class T> class Edge {
    public:
        Point2D<T> p1;
        Point2D<T> p2;

        Edge(const Point2D<T> &v, const Point2D<T> &w) : p1(v), p2(w) {}

        T distance(const Point2D<T> &p0) const {
            T n = abs((p2.x - p1.y)*p0.x - (p2.x - p1.x) * p0.y + p2.x * p1.y - p2.y * p1.x);
            if constexpr (std::is_same_v<T, float>) {
                return n / std::hypotf(p2.y - p1.y, p2.x - p1.x);
            } else if (std::is_same_v<T, double>) {
                return n / std::hypot(p2.y - p1.y, p2.x - p1.x);
            } else {
                return n / std::sqrt(pow(p2.y -p1.y, 2) + pow(p2.x - p1.x, 2));
            }
        }

        bool operator==(const Edge &rhs) const {
            return (p1 == rhs.p1 && p2 == rhs.p2) || (p1 == rhs.p2 && p2 == rhs.p1);
        }

        bool operator!=(const Edge &rhs) const {
            return !(rhs == *this);
        }

        bool operator<(const Edge &rhs) const {
            Point2D<T> ZERO(0, 0);
            return distance(ZERO) < rhs.distance(ZERO);
        }

        bool operator>(const Edge &rhs) const {
            Point2D<T> ZERO(0, 0);
            return distance(ZERO) > rhs.distance(ZERO);
        }

        friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
            os << "Edge(" << "v: " << edge.p1 << " w: " << edge.p2 << ")";
            return os;
        }
    };
}