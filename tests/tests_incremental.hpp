#include <catch2/catch.hpp>
#include "incremental.hpp"
#pragma once

TEST_CASE("Test triangulation"){
    tri::Point2D<int> a(0, 0);
    tri::Point2D<int> b(1, 1);
    tri::Point2D<int> c(2, 2);
    tri::Point2D<int> d(1, 0);
    tri::Point2D<int> f(2, 0);
    tri::Point2D<int> g(0, 1);
    tri::Point2D<int> h(0, 2);
    tri::inc::Incremental incremental({a, b, c, d, f, g, h});
    REQUIRE(incremental.points.size() == 7);
}