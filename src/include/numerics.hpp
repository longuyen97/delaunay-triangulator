#include <cmath>

#pragma once

#define PI 3.14159265359

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

    template<class T>
    T abs(T a) {
        if constexpr (std::is_same_v<T, float>) {
            return fabsf(a);
        } else if (std::is_same_v<T, double>) {
            return fabs(a);
        } else {
            return std::abs(a);
        }
    }


    template<class T>
    T hypo(T x, T y) {
        if constexpr (std::is_same_v<T, float>) {
            return std::hypotf(x, y);
        } else if (std::is_same_v<T, double>) {
            return std::hypot(x, y);
        } else {
            return std::sqrt(pow(x, 2) + pow(y, 2));
        }
    }

    template<typename T>
    T half(const T x) {
        if constexpr (std::is_same_v<T, float>) {
            return 0.5f * x;
        } else if constexpr (std::is_same_v<T, double>) {
            return 0.5l * x;
        } else {
            return 0.5 * x;
        }
    }

    template<typename T>
    T acos(T x) {
        if (x < -1.0) {
            x = -1.0;
        } else if (x > 1.0) {
            x = 1.0;
        }
        return std::acos(x);
    }
}