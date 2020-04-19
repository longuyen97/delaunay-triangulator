#include <cmath>
#include <ostream>
#include <vector>
#include "numerics.hpp"
#include "point.hpp"

#pragma once

namespace tri {
    template<class T>
    class Triangle;

    template<class T>
    class Triangle {
    public:
        Point2D <T> A;
        Point2D <T> B;
        Point2D <T> C;
        std::vector<Edge < T>> edges;

        Triangle(const Point2D <T> &A, const Point2D <T> &B, const Point2D <T> &C) : A(A), B(B), C(C) {
            Edge<T> AB{A, B};
            Edge<T> BC{B, C};
            Edge<T> CA{C, A};
            this->edges.push_back(AB);
            this->edges.push_back(BC);
            this->edges.push_back(CA);
        }

        T determinate() {
            T det = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
            return nums::abs(det);
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

        bool hasCommonEdge(const Triangle &triangle) const {
            for (auto edge1 : this->edges) {
                for (auto edge2 : triangle.edges) {
                    if (edge1 == edge2) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool hasCommonPoint(const Triangle &triangle) const {
            return this->A == triangle.A || this->B == triangle.B || this->C == triangle.C ||
                   this->A == triangle.B || this->B == triangle.C || this->C == triangle.A ||
                   this->A == triangle.C || this->B == triangle.A || this->C == triangle.B;
        }

        T ABC() {
            Edge<T> AB{A, B};
            Edge<T> BC{B, C};
            Edge<T> CA{C, A};
            auto c = AB.length();
            auto a = BC.length();
            auto b = CA.length();
            auto cosABC = (-(b * b) + c * c + a * a) / (2 * a * c);
            auto radABC = nums::acos(cosABC);
            return radABC * (180 / PI);
        }

        T BCA() {
            Edge<T> AB{A, B};
            Edge<T> BC{B, C};
            Edge<T> CA{C, A};
            auto c = AB.length();
            auto a = BC.length();
            auto b = CA.length();
            auto cosBCA = (-(c * c) + a * a + b * b) / (2 * a * b);
            auto radBCA = nums::acos(cosBCA);
            return radBCA * (180 / PI);
        }

        T CAB() {
            Edge<T> AB{A, B};
            Edge<T> BC{B, C};
            Edge<T> CA{C, A};
            auto c = AB.length();
            auto a = BC.length();
            auto b = CA.length();
            auto cosCAB = (-(a * a) + b * b + c * c) / (2 * b * c);
            auto radCAB = nums::acos(cosCAB);
            return radCAB * (180 / PI);
        }

        T alpha() {
            return std::max(CAB(), std::max(ABC(), BCA()));
        }

        bool isValidTriangulation(const Triangle &triangle) const {
            if (*this != triangle && this->hasCommonEdge(triangle)) {
                T sum = this->alpha() + triangle.alpha();
                return sum < 180 || nums::nearEqual(sum, 180);
            } else {
                return false;
            }
        }

        std::tuple<Triangle<T>, Triangle<T>> flip(const Triangle& triangle) const {
            return std::tuple<Triangle<T>, Triangle<T>>();
        }

        bool containsPoint(Point2D <T> &v) const {
            return v == A || v == B || v == C;
        }

        bool circumscribedCircleContains(Point2D <T> &D) const {
            const T ab = this->A.norm2();
            const T cd = this->B.norm2();
            const T ef = this->C.norm2();

            const T ax = this->A.x;
            const T ay = this->A.y;
            const T bx = this->B.x;
            const T by = this->B.y;
            const T cx = this->C.x;
            const T cy = this->C.y;

            const T circumX = (ab * (cy - by) + cd * (ay - cy) + ef * (by - ay)) /
                              (ax * (cy - by) + bx * (ay - cy) + cx * (by - ay));

            const T circumY = (ab * (cx - bx) + cd * (ax - cx) + ef * (bx - ax)) /
                              (ay * (cx - bx) + by * (ax - cx) + cy * (bx - ax));

            const Point2D<T> circum(circumX / 2, circumY / 2);
            return D.distance2(circum) <= A.distance2(circum);
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