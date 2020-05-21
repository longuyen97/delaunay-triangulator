#pragma once
#include "tests.hpp"
#include "incremental.hpp"

namespace test_incremental {
    TEST_CASE("Test find big triangle") {
        tri::Point2D<int> a(0, 0);
        tri::Point2D<int> b(10, 10);
        tri::Point2D<int> c(20, 20);
        tri::Point2D<int> d(10, 0);
        tri::Point2D<int> f(20, 0);
        tri::Point2D<int> g(0, 10);
        tri::Point2D<int> h(0, 20);
        tri::inc::Incremental incremental({a, b, c, d, f, g, h});
        auto bigTriangle = incremental.createBigTriangle();
        for (auto i : incremental.points) {
            bool pointInsideBigTriangle = bigTriangle.circumscribedCircleContains(i);
            REQUIRE(pointInsideBigTriangle);
        }
    }

    TEST_CASE("Test triangulation") {
        tri::Point2D<int> a(0, 0);
        tri::Point2D<int> b(10, 10);
        tri::Point2D<int> c(20, 20);
        tri::Point2D<int> d(10, 0);
        tri::Point2D<int> f(20, 0);
        tri::Point2D<int> g(0, 10);
        tri::Point2D<int> h(0, 20);
        tri::inc::Incremental incremental1({a, b, c, d, f, g, h});
        auto ret1 = incremental1.triangulate();
        REQUIRE(ret1.size() == 2);
    }
}