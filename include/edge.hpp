#ifndef TRIANGULATION_EDGE_HPP
#define TRIANGULATION_EDGE_HPP

#include <cmath>
#include <ostream>
#include <vector>
#include "point.hpp"
#include "numerics.hpp"

namespace tri {
    template<typename T> class Edge {
    public:
        Point2D<T> v;
        Point2D<T> w;

        Edge(const Point2D<T> &v, const Point2D<T> &w) : v(v), w(w) {}

        bool operator==(const Edge &rhs) const {
            return (v == rhs.v && w == rhs.w) || (v == rhs.w && w == rhs.v);
        }

        bool operator!=(const Edge &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
            os << "Edge(v: " << edge.v << " w: " << edge.w << ")";
            return os;
        }
    };
}

#endif
