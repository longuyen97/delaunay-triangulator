#include <vector>
#include <set>
#include <algorithm>
#include "point.hpp"
#include "triangle.hpp"
#include "edge.hpp"

#pragma once

namespace tri::inc {
    /**
     * Bowyer Watson Algorithm https://en.wikipedia.org/wiki/Bowyer%E2%80%93Watson_algorithm
     */
    class Incremental {
    public:
        /*
         * Set of coordinates defining the points to be triangulated
         */
        std::vector<tri::Point2D<long long>> points;

        Incremental() = default;

        explicit Incremental(const std::vector<Point2D<long long>>& points) {
            this->points = points;
        }

        /**
         * Create a very big triangle which enclose every point
         * @return a very big triangle
         */
        Triangle<long long> createBigTriangle(){
            auto minX = points[0].x;
            auto minY = points[0].y;
            auto maxX = minX;
            auto maxY = minY;


            for (auto i: this->points) {
                if (i.x < minX) { minX = i.x; }
                if (i.y < minY) { minY = i.y; }
                if (i.x > maxX) { maxX = i.x; }
                if (i.y > maxY) { maxY = i.y; }
            }

            const auto dx = maxX - minX;
            const auto dy = maxY - minY;
            const auto deltaMax = std::max(dx, dy);
            const auto midX = nums::half(minX + maxX);
            const auto midY = nums::half(minY + maxY);

            const Point2D<long long> p1(midX - 20 * deltaMax, midY - deltaMax);
            const Point2D<long long> p2(midX, midY + 20 * deltaMax);
            const Point2D<long long> p3(midX + 20 * deltaMax, midY - deltaMax);
            return Triangle<long long>{p1, p2, p3};
        }

        /**
         * Triangulate the point set with the incremental algorithm
         * @return a set of distinct triangles that form the triangulation of the point set
         */
        std::set<tri::Triangle<long long>> triangulate() {
            /*
             * Create and insert the artificial big triangle as the first result
             */
            auto bigTriangle = createBigTriangle();
            std::set<tri::Triangle<long long>> triangles{bigTriangle};

            /*
             * Iterate point for point of the point set
             */
            for (auto &point : points) {
                std::set<tri::Edge<long long>> polygon;
                std::set<tri::Edge<long long>> badEdges;
                std::set<tri::Triangle<long long>> badTriangles;

                /*
                 * Find bad triangles
                 * Add edges of bad triangles to polygon
                 */
                for (const auto& triangle : triangles) {
                    if (triangle.circumscribedCircleContains(point)) {
                        badTriangles.insert(triangle);
                        polygon.insert(tri::Edge<long long>(triangle.A, triangle.B));
                        polygon.insert(tri::Edge<long long>(triangle.B, triangle.C));
                        polygon.insert(tri::Edge<long long>(triangle.C, triangle.A));
                    }
                }

                /*
                 * Find bad edges
                 */
                for (auto edge1 = polygon.begin(); edge1 != polygon.end(); edge1++) {
                    for (auto edge2 = std::next(edge1, 1); edge2 != polygon.end(); edge2++) {
                        if (*edge1 == *edge2) {
                            badEdges.insert(*edge1);
                            badEdges.insert(*edge2);
                        }
                    }
                }

                /*
                 * Remove bad triangle
                 */
                for (auto triangle = triangles.begin(); triangle != triangles.end();) {
                    if (std::find(badTriangles.begin(), badTriangles.end(), *triangle) != badTriangles.end()) {
                        triangle = triangles.erase(triangle);
                    } else {
                        ++triangle;
                    }
                }

                /*
                 * Remove bad edges. Construct from edge and current point a new triangle
                 */
                for (auto edge = polygon.begin(); edge != polygon.end();) {
                    if (std::find(badEdges.begin(), badEdges.end(), *edge) != badEdges.end()) {
                        edge = polygon.erase(edge);
                    } else {
                        tri::Triangle<long long> newTriangle{edge->p2, point, edge->p1};
                        triangles.insert(newTriangle);
                        ++edge;
                    }
                }
            }

            /*
             * Delete the big triangle from the result
             * and every other triangle that does not have have original points
             */
            for (auto triangle = triangles.begin(); triangle != triangles.end();) {
                if ((*triangle).hasCommonPoint(bigTriangle)) {
                    triangle = triangles.erase(triangle);
                }else{
                    triangle++;
                }
            }

            return triangles;
        }
    };
}