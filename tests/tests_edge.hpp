#pragma once
#include "tests.hpp"
#include "edge.hpp"

TEST_CASE("Test edge comparision 1") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(a, b);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}

TEST_CASE("Test edge comparision 2") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> e(b, a);
    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(1.0, 0.0);
    tri::Edge<double> f(c, d);
    REQUIRE(e == f);
}

TEST_CASE("Test edge comparision distance ") {
    tri::Point2D<double> a(-1.0, 1.0);
    tri::Point2D<double> b(1.0, 1.0);
    tri::Edge<double> c(b, a);
    tri::Point2D<double> ZERO(0, 0);
    auto ret = c.distance(ZERO);
    REQUIRE(ret == Approx(1).epsilon(0.001));
}

TEST_CASE("Test edge's length") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 0.0);
    tri::Edge<double> c(b, a);
    auto ret = c.length();
    REQUIRE(ret == Approx(1).epsilon(0.001));
}

TEST_CASE("Test edge's angle") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(3.0, 0.0);
    tri::Point2D<double> c(3.0, 3.0);
    tri::Edge<double> ab{a, b};
    tri::Edge<double> bc{b, c};
    tri::Edge<double> ca{c, a};

    auto ret = ab.degree(bc);
    REQUIRE(ret == Approx(90).epsilon(0.001));
    ret = bc.degree(ab);
    REQUIRE(ret == Approx(90).epsilon(0.001));

    ret = bc.degree(ca);
    REQUIRE(ret == Approx(45).epsilon(0.001));
    ret = ca.degree(bc);
    REQUIRE(ret == Approx(45).epsilon(0.001));

    ret = ca.degree(ab);
    REQUIRE(ret == Approx(45).epsilon(0.001));
    ret = ab.degree(ca);
    REQUIRE(ret == Approx(45).epsilon(0.001));
}

TEST_CASE("Test edge intersected point") {
    tri::Point2D<double> a(0.0, 0.0);
    tri::Point2D<double> b(1.0, 1.0);

    tri::Point2D<double> c(0.0, 0.0);
    tri::Point2D<double> d(-1.0, -1.0);

    tri::Point2D<double> e(-1.0, -1.0);
    tri::Point2D<double> f(-2.0, 0.0);

    tri::Edge<double> g(a, b);
    tri::Edge<double> h(c, d);
    tri::Edge<double> i(e, f);

    REQUIRE(g.hasIntersectedPoint(h));
    REQUIRE(h.hasIntersectedPoint(g));

    REQUIRE(h.hasIntersectedPoint(i));
    REQUIRE(i.hasIntersectedPoint(h));

    REQUIRE_FALSE(i.hasIntersectedPoint(g));
    REQUIRE_FALSE(g.hasIntersectedPoint(i));
}
