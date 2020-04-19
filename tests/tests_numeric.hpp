#pragma once

#include <catch2/catch.hpp>
#include "numerics.hpp"

TEST_CASE("Test Near equal") {
    REQUIRE(nums::nearEqual(1.0, 1.0001));
    REQUIRE(nums::nearEqual(1000000000000.0, 1000000000000.0001));
}

TEST_CASE("Test absolute") {
    REQUIRE(nums::nearEqual(1.0, nums::abs(-1.0)));
    REQUIRE(nums::nearEqual(1, nums::abs(-1)));
    REQUIRE(nums::nearEqual(1.0f, nums::abs(-1.0f)));
}

TEST_CASE("Test Hypo") {
    REQUIRE(nums::nearEqual(3.0, nums::hypo(0.0, 3.0)));
    REQUIRE(nums::nearEqual(4.0, nums::hypo(0.0, 4.0)));
    REQUIRE(nums::nearEqual(3.16, nums::hypo(1.0, 3.0)));
}

TEST_CASE("Test Half") {
    REQUIRE(nums::nearEqual(3.0, nums::half(6.0)));
    REQUIRE(nums::nearEqual(4.0f, nums::half(8.0f)));
    REQUIRE(nums::nearEqual(3, nums::half(7)));
}

