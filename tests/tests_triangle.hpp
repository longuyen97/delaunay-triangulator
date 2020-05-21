#pragma once
#include "triangle.hpp"

namespace test_triangle {
    TEST_CASE("Test triangle contains") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(1.5, 3.0);
        tri::Point2D<double> d(1.5, 1.5);
        tri::Triangle<double> e(a, b, c);
        REQUIRE(e.circumscribedCircleContains(d));
        tri::Point2D<double> f(15, 15);
        REQUIRE_FALSE(e.circumscribedCircleContains(f));
        REQUIRE((e.containsPoint(a) && e.containsPoint(b) && e.containsPoint(c)));
        REQUIRE(e.circumscribedCircleContains(a));
        REQUIRE(e.circumscribedCircleContains(b));
        REQUIRE(e.circumscribedCircleContains(c));
    }

    TEST_CASE("Test triangle's area") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(3.0, 3.0);
        tri::Triangle<double> d{a, b, c};
        double ret = d.area();
        REQUIRE(ret == Approx(4.5).epsilon(0.001));
    }

    TEST_CASE("Test have intersected point") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(1.5, 3.0);
        tri::Triangle<double> d(a, b, c);

        tri::Point2D<double> e(1.0, 1.0);
        tri::Point2D<double> f(3.0, 0.0);
        tri::Point2D<double> g(2.0, 2.0);
        tri::Triangle<double> h(e, f, g);
        REQUIRE(h.hasCommonPoint(d));
        REQUIRE(d.hasCommonPoint(h));
    }

    TEST_CASE("Test have intersected edge") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(1.5, 3.0);
        tri::Triangle<double> t1(a, b, c);

        tri::Point2D<double> e(0.0, 0.0);
        tri::Point2D<double> f(3.0, 0.0);
        tri::Point2D<double> g(2.0, 2.0);
        tri::Triangle<double> t2(e, f, g);

        tri::Point2D<double> h(1.0, 1.0);
        tri::Point2D<double> i(3.0, 0.0);
        tri::Point2D<double> k(2.5, 3.0);
        tri::Triangle<double> t3(h, i, k);
        auto ret1 = t2.hasCommonEdge(t1);
        REQUIRE(ret1);
        auto ret2 = t1.hasCommonEdge(t2);
        REQUIRE(ret2);
        auto ret3 = t3.hasCommonEdge(t1);
        REQUIRE_FALSE(ret3);
        auto ret4 = t1.hasCommonEdge(t3);
        REQUIRE_FALSE(ret4);
    }

    TEST_CASE("Test alpha angle of a triangle 1") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(3.0, 3.0);
        tri::Triangle<double> d(a, b, c);
        auto ABC = d.ABC();
        auto BCA = d.BCA();
        auto CAB = d.CAB();
        REQUIRE(ABC + BCA + CAB == Approx(180).epsilon(0.01));
        REQUIRE(d.alpha() == Approx(90).epsilon(0.01));
    }

    TEST_CASE("Test alpha angle of a triangle 2") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(10.0, 1.0);
        tri::Triangle<double> d(a, b, c);
        auto ret = d.alpha();
        REQUIRE(ret == Approx(171.86).epsilon(0.001));
    }

    TEST_CASE("Test determinante non-colinear") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(3.0, 3.0);
        tri::Triangle<double> d(a, b, c);
        auto ret = d.determinate();
        REQUIRE(ret == Approx(9).epsilon(0.001));
    }

    TEST_CASE("Test determinante colinear") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(3.0, 0.0);
        tri::Point2D<double> c(5.0, 0.0);
        tri::Triangle<double> d(a, b, c);
        auto ret = d.determinate();
        REQUIRE(ret == Approx(0).epsilon(0.001));
    }
}