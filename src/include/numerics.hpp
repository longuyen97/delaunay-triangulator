#include <cmath>
#pragma once

namespace nums {
    template<class T>
    bool nearEqual(T a, T b) {
        if constexpr (std::is_same_v<T, float>) {
            return (std::abs(a - b) <= 0.001 * std::min(std::abs(a), std::abs(b)));
        } else if (std::is_same_v<T, double>) {
            return (std::abs(a - b) <= 0.001f * std::min(std::abs(a), std::abs(b)));
        } else {
            return a == b;
        }
    }
}