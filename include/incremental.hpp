#ifndef TRIANGULATION_INCREMENTAL_H
#define TRIANGULATION_INCREMENTAL_H

#include <vector>
#include "point.hpp"
#include "triangle.hpp"

namespace tri::inc {
    template<typename T>
    class Incremental {
    public:
        std::vector<tri::Point2D<T>> points;

        Incremental() = default;

        explicit Incremental(const std::vector<Point2D<T>> points) {
            this->points = points;
        }

        std::vector<tri::Triangle<T>> triangulate() {
            return std::vector<tri::Triangle<T>>();
        }
    };
}

#endif
