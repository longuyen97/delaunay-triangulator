#include <cmath>
#include <ostream>
#include <vector>
#include "numerics.hpp"
#include "point.hpp"

#pragma once

namespace tri {
    template<class T>
    class Triangle {
    public:
        Point2D <T> A;
        Point2D <T> B;
        Point2D <T> C;
        std::vector<Edge < T>> edges;

        Triangle(const Point2D <T> &v1, const Point2D <T> &v2, const Point2D <T> &v3) : A(v1), B(v2), C(v3) {
            Edge<T> v1v2{v1, v2};
            Edge<T> v2v3{v2, v3};
            Edge<T> v3v1{v3, v1};
            this->edges.push_back(v1v2);
            this->edges.push_back(v2v3);
            this->edges.push_back(v3v1);
        }

        T area() const {
            auto i1 = A.x * (B.y - C.y);
            auto i2 = B.x * (C.y - A.y);
            auto i3 = C.x * (A.y - B.y);
            auto ret = (i1 + i2 + i3) / 2;
            if constexpr (std::is_same_v<T, float>) {
                return fabsf(ret);
            } else if (std::is_same_v<T, double>) {
                return fabs(ret);
            } else {
                return abs(ret);
            }
        }

        bool containsPoint(Point2D <T> &v) const {
            return v == A || v == B || v == C;
        }

        bool circumscribedCircleContains(Point2D <T> &v) const {
            T ax = A.x - v.x;
            T ay = A.y - v.y;
            T bx = B.x - v.x;
            T by = B.y - v.y;
            T cx = C.x - v.x;
            T cy = C.y - v.y;
            return (ax * ax + ay * ay) *
                   (bx * cy - cx * by) -
                   (bx * bx + by * by) *
                   (ax * cy - cx * ay) +
                   (cx * cx + cy * cy) *
                   (ax * by - bx * ay) > 0;
        }

        bool operator==(const Triangle<T> &rhs) const {
            return (A == rhs.A && B == rhs.B && C == rhs.C) ||
                   (A == rhs.B && B == rhs.C && C == rhs.A) ||
                   (A == rhs.C && B == rhs.A && C == rhs.B);
        }

        bool operator!=(const Triangle<T> &rhs) const {
            return !(rhs == *this);
        }

        bool operator<(const Triangle<T> &rhs) const {
            return area() < rhs.area();
        }

        bool operator>(const Triangle<T> &rhs) const {
            return area() > rhs.area();
        }

        friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
            os << "Triangle(v1: " << triangle.A << " v2: " << triangle.B << " v3: " << triangle.C << ")";
            return os;
        }
    };
}