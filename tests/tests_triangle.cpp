#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "triangle.hpp"

TEST_CASE("Test triangle"){
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(3.0, 0.0);
    tri::Point2D<double> c(1.5, 3.0);
    tri::Point2D<double> d(1.5, 1.5);
    tri::Triangle<double> e(a, b, c);
    REQUIRE(e.circumscribedCircleContains(d));
    tri::Point2D<double> f(15, 15);
    REQUIRE(!e.circumscribedCircleContains(f));
    REQUIRE((e.contains(a) && e.contains(b) && e.contains(c)));
}
