#ifndef TRIANGULATION_INCREMENTAL_H
#define TRIANGULATION_INCREMENTAL_H

#include <vector>
#include "point.hpp"
#include "triangle.hpp"
#include "edge.hpp"

namespace tri::inc {
    /**
     * Bowyer Watson Algorithm https://en.wikipedia.org/wiki/Bowyer%E2%80%93Watson_algorithm
     */
    template<typename T>
    class Incremental {
    public:
        /*
         * Set of coordinates defining the points to be triangulated
         */
        std::vector<tri::Point2D<T>> points;

        Incremental() = default;

        explicit Incremental(const std::vector<Point2D<T>> points) {
            this->points = points;
        }

        std::vector<tri::Triangle<T>> triangulate() {
            std::vector<tri::Triangle<T>> ret;

            T minX = this->points[0].x;
            T minY = this->points[0].y;
            T maxX = this->points[0].x;
            T maxY = this->points[0].y;

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

            Point2D<T> p1(midX - 20 * dMax, midY - dMax);
            Point2D<T> p2(midX, midY + 20 * dMax);
            Point2D<T> p3(midX + 20 * dMax, midY - dMax);
            Triangle<T> bigTriangle(p1, p2, p3);
            ret.push_back(bigTriangle);

            for(auto i = points.begin(); i != points.end();){
                std::vector<tri::Edge<T>> polygon;
                for(auto j : ret){
                    if(j.circumscribedCircleContains(*i)){
                        j.isBad = true;
                        polygon.push_back(Edge{j.a, j.b});
                        polygon.push_back(Edge{j.b, j.c});
                        polygon.push_back(Edge{j.c, j.a});
                    }
                }
                for(auto j = ret.begin(); ret != ret.end();){
                    if(*j.isBad){
                        j = ret.erase(j);
                    }
                }
            }

            return ret;
        }
    };
}

#endif