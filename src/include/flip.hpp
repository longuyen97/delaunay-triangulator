#pragma once

namespace tri::flip {
    /**
     * Flipping algorithm https://en.wikipedia.org/wiki/Delaunay_triangulation#Flip_algorithms
     */
    class Flip {

        /*
         * Set of coordinates defining the points to be triangulated
         */
        std::vector<tri::Point2D<double>> points;

        Flip() = default;

        explicit Flip(const std::vector<Point2D<double>>& points) {
            this->points = points;
        }

        std::set<tri::Triangle<double>> triangulate() {
            return std::set<tri::Triangle<double>>();
        }
    };
}