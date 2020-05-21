#pragma once
#include <point.hpp>

namespace test_point {
    TEST_CASE("Test distance integer") {
        tri::Point2D<int> a(0.0, 0.0);
        tri::Point2D<int> b(1.0, 0.0);
        REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
        REQUIRE(a.squaredDistance(b) == Approx(1.0).epsilon(0.01));
    }

    TEST_CASE("Test distance float") {
        tri::Point2D<float> a(0.0, 0.0);
        tri::Point2D<float> b(1.0, 0.0);
        REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
        REQUIRE(a.squaredDistance(b) == Approx(1.0).epsilon(0.01));
    }

    TEST_CASE("Test distance double") {
        tri::Point2D<double> a(0.0, 0.0);
        tri::Point2D<double> b(1.0, 0.0);
        REQUIRE(a.distance(b) == Approx(1.0).epsilon(0.01));
    }

    TEST_CASE("Test norm integer") {
        tri::Point2D<int> a(1.0, 1.0);
        REQUIRE(a.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<int> b(1.0, 0.0);
        REQUIRE(b.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<int> c(0.0, 1.0);
        REQUIRE(c.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<int> d(-1.0, 0.0);
        REQUIRE(d.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<int> e(0.0, -1.0);
        REQUIRE(e.norm() == Approx(1).epsilon(0.01));
    }

    TEST_CASE("Test norm float") {
        tri::Point2D<float> a(1.0, 1.0);
        REQUIRE(a.norm() == Approx(std::sqrt(2.0)).epsilon(0.01));
        tri::Point2D<float> b(1.0, 0.0);
        REQUIRE(b.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<float> c(0.0, 1.0);
        REQUIRE(c.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<float> d(-1.0, 0.0);
        REQUIRE(d.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<float> e(0.0, -1.0);
        REQUIRE(e.norm() == Approx(1).epsilon(0.01));
    }

    TEST_CASE("Test norm double") {
        tri::Point2D<double> a(1.0, 1.0);
        REQUIRE(a.norm() == Approx(std::sqrt(2.0)).epsilon(0.01));
        tri::Point2D<double> b(1.0, 0.0);
        REQUIRE(b.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<double> c(0.0, 1.0);
        REQUIRE(c.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<double> d(-1.0, 0.0);
        REQUIRE(d.norm() == Approx(1).epsilon(0.01));
        tri::Point2D<double> e(0.0, -1.0);
        REQUIRE(e.norm() == Approx(1).epsilon(0.01));
    }
}