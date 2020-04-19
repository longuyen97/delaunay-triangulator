#include <cmath>
#include <ostream>
#include <vector>
#include "point.hpp"
#include "numerics.hpp"
#pragma once

namespace tri {
    template<class T> class Edge {
    public:
        Point2D<T> v;
        Point2D<T> w;
        bool isBad{};

        Edge(const Point2D<T> &v, const Point2D<T> &w) : v(v), w(w) {
            this->isBad = false;
        }

        bool operator==(const Edge &rhs) const {
            return (v == rhs.v && w == rhs.w) || (v == rhs.w && w == rhs.v);
        }

        bool operator!=(const Edge &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
            os << "v: " << edge.v << " w: " << edge.w << " isBad: " << edge.isBad;
            return os;
        }
    };
}