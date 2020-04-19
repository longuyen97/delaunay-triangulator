#include <vector>
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
        std::vector<tri::Point2D<double>> points;

        Incremental() = default;

        explicit Incremental(const std::vector<Point2D<double>> points) {
            this->points = points;
        }

        std::vector<tri::Triangle<double>> triangulate() {
            /*
             * Find appropriate coordinates for a ridiculous big triangle.
             * Find the smallest x, y and biggest x, y, make a triangle out of those two points and their delta
             */
            std::vector<tri::Triangle<double>> triangles;
            double minX = DBL_MAX;
            double minY = DBL_MAX;
            double maxX = -DBL_MAX;
            double maxY = -DBL_MAX;

            for(auto i: this->points){
                if(i.x < minX){minX = i.x;}
                if(i.y < minY){minY = i.y;}
                if(i.x > maxX){maxX = i.x;}
                if(i.y > maxY){maxY = i.y;}
            }
            auto dMax = std::max(maxX - minX, maxY - minY);
            auto midX = (minX + maxX) / 2;
            auto midY = (minY + maxY) / 2;

            /*
             * Points found, create the big triangle.
             */
            Point2D<double> p1(midX - 20 * dMax, midY - dMax);
            Point2D<double> p2(midX, midY + 20 * dMax);
            Point2D<double> p3(midX + 20 * dMax, midY - dMax);

            /*
             * Insert the artificial big triangle as the first result
             */
            Triangle<double> bigTriangle(p1, p2, p3);
            triangles.push_back(bigTriangle);

            /*
             * Iterate point for point of the point set
             */
            for(auto & point : points){
                std::vector<tri::Edge<double>> polygon;
                for(auto triangle : triangles){
                    if(triangle.circumscribedCircleContains(point)){
                        triangle.isBad = true;
                        polygon.emplace_back(triangle.v1, triangle.v2);
                        polygon.emplace_back(triangle.v2, triangle.v3);
                        polygon.emplace_back(triangle.v3, triangle.v1);
                    }
                }
                for(auto triangle = triangles.begin(); triangle != triangles.end();){
                    if(triangle->isBad){
                        triangle = triangles.erase(triangle);
                    }else{
                        ++triangle;
                    }
                }
                for(auto edge1 = polygon.begin(); edge1 != polygon.end(); edge1++){
                    for(auto edge2 = edge1 + 1; edge2 != polygon.end(); edge2++){
                        if(*edge1 == *edge2){
                            edge1->isBad = true;
                            edge2->isBad = true;
                        }
                    }
                }
                for(auto edge = polygon.begin(); edge != polygon.end();){
                    if(edge->isBad){
                        edge = polygon.erase(edge);
                    }else{
                        ++edge;
                    }
                }
            }

            /*
             * Delete the big triangle from the result
             */
            for(auto triangle = triangles.begin(); triangle != triangles.end();){
                if(*triangle == bigTriangle){
                    triangles.erase(triangle);
                    break;
                }
            }

            return triangles;
        }
    };
}