#include <cmath>
#include <ostream>
#include <vector>
#include "point.hpp"
#include "numerics.hpp"
#pragma once

namespace tri {
    template<class T> class Edge;
    template<class T> class Edge {
    public:
        Point2D<T> p1;
        Point2D<T> p2;

        Edge(const Point2D<T> &v, const Point2D<T> &w) : p1(v), p2(w) {}

        T distance(const Point2D<T> &p0) const {
            return nums::hypo(p2.y - p1.y, p2.x - p1.x);
        }

        T length(){
            return nums::hypo(p2.x - p1.x, p2.x - p1.x);
        }

        T degree(const Edge<T> &edge) const {
            T deltaX1 = p1.x - p2.x;
            T deltaX2 = edge.p1.x - edge.p2.x;
            T deltaY1 = p1.y - p2.y;
            T deltaY2 = edge.p1.y - edge.p2.y;
            T n = deltaX1 * deltaX2 + deltaY1 * deltaY2;
            tri::Point2D<T> vec1{deltaX1, deltaY1};
            tri::Point2D<T> vec2{deltaX2, deltaY2};
            T d = vec1.norm() * vec2.norm();
            T ret = acos(n / d) * (180 / PI);
            return ret;
        }

        bool hasIntersectedPoint(const Edge<T> &edge) const {
            return p1 == edge.p1 || p2 == edge.p2 || p1 == edge.p2 || p2 == edge.p1;
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