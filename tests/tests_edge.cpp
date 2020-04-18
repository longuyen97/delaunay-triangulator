#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "edge.hpp"

TEST_CASE("Test edge 1"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(a, b);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}

TEST_CASE("Test edge 2"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(b, a);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}
