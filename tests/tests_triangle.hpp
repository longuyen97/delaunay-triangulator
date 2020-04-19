#include <catch2/catch.hpp>
#include "triangle.hpp"

#pragma once

TEST_CASE("Test triangle contains") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(3.0, 0.0);
    tri::Point2D<double> c(1.5, 3.0);
    tri::Point2D<double> d(1.5, 1.5);
    tri::Triangle<double> e(a, b, c);
    REQUIRE(e.circumscribedCircleContains(d));
    tri::Point2D<double> f(15, 15);
    REQUIRE(!e.circumscribedCircleContains(f));
    REQUIRE((e.containsPoint(a) && e.containsPoint(b) && e.containsPoint(c)));
}

TEST_CASE("Test triangle's area") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(3.0, 0.0);
    tri::Point2D<double> c(3.0, 3.0);
    tri::Triangle<double> d{a, b, c};
    double ret = d.area();
    REQUIRE(ret == Approx(4.5).epsilon(0.001));
}

TEST_CASE("Test have intersected point"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(3.0, 0.0);
    tri::Point2D<double> c(1.5, 3.0);
    tri::Triangle<double> d(a, b, c);

    tri::Point2D<double> e(1.0, 1.0);
    tri::Point2D<double> f(3.0, 0.0);
    tri::Point2D<double> g(2.0, 2.0);
    tri::Triangle<double> h(e, f, g);
    REQUIRE(h.hasIntersectedPoint(d));
    REQUIRE(d.hasIntersectedPoint(h));
}
