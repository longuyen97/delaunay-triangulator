#include <catch2/catch.hpp>
#include "incremental.hpp"
#pragma once

TEST_CASE("Test find big triangle"){
    tri::Point2D<double> a(0, 0);
    tri::Point2D<double> b(10, 10);
    tri::Point2D<double> c(20, 20);
    tri::Point2D<double> d(10, 0);
    tri::Point2D<double> f(20, 0);
    tri::Point2D<double> g(0, 10);
    tri::Point2D<double> h(0, 20);
    tri::inc::Incremental incremental({a, b, c, d, f, g, h});
    auto bigTriangle = incremental.createBigTriangle();
    for(auto i : incremental.points){
        bool pointInsideBigTriangle = bigTriangle.circumscribedCircleContains(i);
        REQUIRE(pointInsideBigTriangle);
    }
}

TEST_CASE("Test triangulation"){
    tri::Point2D<double> a(0, 0);
    tri::Point2D<double> b(10, 10);
    tri::Point2D<double> c(20, 20);
    tri::Point2D<double> d(10, 0);
    tri::Point2D<double> f(20, 0);
    tri::Point2D<double> g(0, 10);
    tri::Point2D<double> h(0, 20);
    tri::inc::Incremental incremental({a, b, c, d, f, g, h});
    REQUIRE(incremental.points.size() == 7);
    auto ret = incremental.triangulate();
    REQUIRE(ret.size() == 5);
}