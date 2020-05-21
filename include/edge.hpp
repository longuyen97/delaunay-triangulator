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

        /**
         * Calculate the distance from this line to a single point
         * @param p0 point p0
         * @return euclidean distance between this edge and point p0
         */
        T distance(const Point2D<T> &p0) const {
            T n = nums::abs((p2.x - p1.y)*p0.x - (p2.x - p1.x) * p0.y + p2.x * p1.y - p2.y * p1.x);
            return n / nums::hypo(p2.y - p1.y, p2.x - p1.x);
        }

        /**
         * Length of this edge
         * @return length of this edge
         */
        T length(){
            return nums::hypo(p2.x - p1.x, p2.y - p1.y);
        }

        /**
         * Calculate the angle between this edge and another edge
         * @param edge other edge
         * @return degree angle between this edge and the other edge
         */
        T degree(const Edge<T> &edge) const {
            T deltaX1 = p1.x - p2.x;
            T deltaX2 = edge.p1.x - edge.p2.x;
            T deltaY1 = p1.y - p2.y;
            T deltaY2 = edge.p1.y - edge.p2.y;
            T n = deltaX1 * deltaX2 + deltaY1 * deltaY2;
            tri::Point2D<T> vec1{deltaX1, deltaY1};
            tri::Point2D<T> vec2{deltaX2, deltaY2};
            T d = vec1.norm() * vec2.norm();
            T rad = acos(n / d);
            T ret = rad * (180 / PI);
            return ret;
        }

        /**
         * Check if this line and the other line has a common endpoint
         * @param edge other line
         * @return true of two line has at least one common end point
         */
        bool hasCommonPoint(const Edge<T> &edge) const {
            return p1 == edge.p1 || p2 == edge.p2 || p1 == edge.p2 || p2 == edge.p1;
        }

        bool operator==(const Edge &rhs) const {
            return (p1 == rhs.p1 && p2 == rhs.p2) || (p1 == rhs.p2 && p2 == rhs.p1);
        }

        bool operator!=(const Edge &rhs) const {
            return !(rhs == *this);
        }

        /**
         * Compare two edge by the distance from a edge to (0, 0)
         * @param rhs other edge
         * @return true if this edge is nearer to (0, 0) than the other edge
         */
        bool operator<(const Edge &rhs) const {
            Point2D<T> ZERO(0, 0);
            return distance(ZERO) < rhs.distance(ZERO);
        }

        /**
         * Compare two edge by the distance from a edge to (0, 0)
         * @param rhs other edge
         * @return true if this edge is further from (0, 0) than the other edge
         */
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