#include <catch2/catch.hpp>
#include "point.hpp"
#pragma once

TEST_CASE("Test distance integer") {
    tri::Point2D<int> a(0.0, 0.0);
    tri::Point2D<int> b(1.0, 0.0);
    REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
    REQUIRE(a.distance2(b) == Approx(1.0).epsilon(0.01));
}

TEST_CASE("Test distance float") {
    tri::Point2D<float> a(0.0, 0.0);
    tri::Point2D<float> b(1.0, 0.0);
    REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
    REQUIRE(a.distance2(b) == Approx(1.0).epsilon(0.01));
}

TEST_CASE("Test distance double") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
}

TEST_CASE("Test norm integer") {
    tri::Point2D<int> a(1.0, 1.0);
    REQUIRE(a.norm() == Approx(1).epsilon(0.01));
    REQUIRE(a.norm2() == Approx(2).epsilon(0.01));
}

TEST_CASE("Test norm float") {
    tri::Point2D<float> a(1.0, 1.0);
    REQUIRE(a.norm() == Approx(std::sqrt(2.0)).epsilon(0.01));
    REQUIRE(a.norm2() == Approx(2.0).epsilon(0.01));
}

TEST_CASE("Test norm double") {
    tri::Point2D<double> a(1.0, 1.0);
    REQUIRE(a.norm() == Approx(std::sqrt(2.0)).epsilon(0.01));
    REQUIRE(a.norm2() == Approx(2.0).epsilon(0.01));
}
