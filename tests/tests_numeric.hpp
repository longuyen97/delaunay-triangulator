#pragma once
#include "tests.hpp"
#include "numerics.hpp"

namespace test_numeric {
    TEST_CASE("Test Near equal") {
        REQUIRE(nums::nearEqual(1.0, 1.0001));
        REQUIRE(nums::nearEqual(1000000000000.0, 1000000000000.0001));
    }

    TEST_CASE("Test absolute") {
        auto ret1 = nums::abs(-1.0);
        auto eqa1 = nums::nearEqual(1.0, ret1);
        REQUIRE(eqa1);
        auto ret2 = nums::abs(-1);
        auto eqa2 = nums::nearEqual(1, ret2);
        REQUIRE(eqa2);
        auto ret3 = nums::abs(-1.0f);
        auto eqa3 = nums::nearEqual(1.0f, ret3);
        REQUIRE(eqa3);
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
}