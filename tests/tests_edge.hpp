#include <catch2/catch.hpp>
#include "edge.hpp"
#pragma once

TEST_CASE("Test edge comparision 1"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(a, b);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}

TEST_CASE("Test edge comparision 2"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(b, a);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}

TEST_CASE("Test edge comparision distance "){
    tri::Point2D<double> a(-1.0, 1.0);
    tri::Point2D<double> b(1.0, 1.0);
    tri::Edge<double> c(b, a);
    tri::Point2D<double> ZERO(0, 0);
    auto ret = c.distance(ZERO);
    REQUIRE(ret == Approx(1).epsilon(0.001));
}
