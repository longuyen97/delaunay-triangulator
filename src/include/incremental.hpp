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
        std::vector<tri::Point2D<int>> points;

        Incremental() = default;

        explicit Incremental(const std::vector<Point2D<int>> points) {
            this->points = points;
        }

        std::vector<tri::Triangle<int>> triangulate() {
            std::vector<tri::Triangle<int>> ret;
            int minX = this->points[0].x;
            int minY = this->points[0].y;
            int maxX = this->points[0].x;
            int maxY = this->points[0].y;

            for(auto i: this->points){
                if(i.x < minX){
                    minX = i.x;
                }
                if(i.y < minY){
                    minY = i.y;
                }
                if(i.x > maxX){
                    maxX = i.x;
                }
                if(i.y > maxY){
                    maxY = i.y;
                }
            }
            auto dx = maxX - minX;
            auto dy = maxX - minY;
            auto dMax = std::max(dx, dy);
            auto midX = (minX + maxX) / 2;
            auto midY = (minY + maxY) / 2;

            Point2D<int> p1(midX - 20 * dMax, midY - dMax);
            Point2D<int> p2(midX, midY + 20 * dMax);
            Point2D<int> p3(midX + 20 * dMax, midY - dMax);
            Triangle<int> bigTriangle(p1, p2, p3);
            ret.push_back(bigTriangle);

            for(auto i = points.begin(); i != points.end();){
                std::vector<tri::Edge<int>> polygon;
                for(auto j : ret){
                    if(j.circumscribedCircleContains(*i)){
                        j.isBad = true;
                        polygon.emplace_back(j.v1, j.v2);
                        polygon.emplace_back(j.v2, j.v3);
                        polygon.emplace_back(j.v3, j.v1);
                    }
                }
                for(auto j = ret.begin(); j != ret.end();){
                    if(j->isBad){
                        j = ret.erase(j);
                    }else{
                        ++j;
                    }
                }
            }

            return ret;
        }
    };
}