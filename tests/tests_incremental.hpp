#pragma once
#include "incremental.hpp"

namespace test_incremental {
    TEST_CASE("Test find big triangle") {
        tri::Point2D<long double> a(0, 0);
        tri::Point2D<long double> b(10, 10);
        tri::Point2D<long double> c(20, 20);
        tri::Point2D<long double> d(10, 0);
        tri::Point2D<long double> f(20, 0);
        tri::Point2D<long double> g(0, 10);
        tri::Point2D<long double> h(0, 20);
        tri::inc::Incremental incremental({a, b, c, d, f, g, h});
        auto bigTriangle = incremental.createBigTriangle();
        for (auto i : incremental.points) {
            REQUIRE(bigTriangle.circumscribedCircleContains(i));
        }
    }

    TEST_CASE("Test triangulation") {
        tri::Point2D<long double> a(0, 0);
        tri::Point2D<long double> b(10, 10);
        tri::Point2D<long double> c(20, 20);
        tri::Point2D<long double> d(10, 0);
        tri::Point2D<long double> f(20, 0);
        tri::Point2D<long double> g(0, 10);
        tri::Point2D<long double> h(0, 20);
        tri::Point2D<long double> i(10, 20);
        tri::Point2D<long double> k(20, 10);
        tri::inc::Incremental incremental1({a, b, c, d, f, g, h, i, k});
        auto ret1 = incremental1.triangulate();
        //REQUIRE(ret1.size() == 2);
    }
}