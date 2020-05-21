#include "incremental.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdlib>
#include <ctime>
#define SIZE 1000

inline void drawLines(cv::Mat& mat, const tri::Triangle<long double>& triangle){
    cv::line(mat, cv::Point(triangle.A.x, triangle.A.y), cv::Point(triangle.B.x, triangle.B.y), cv::Scalar(255, 255, 255), 1);
    cv::line(mat, cv::Point(triangle.B.x, triangle.B.y), cv::Point(triangle.C.x, triangle.C.y), cv::Scalar(255, 255, 255), 1);
    cv::line(mat, cv::Point(triangle.C.x, triangle.C.y), cv::Point(triangle.A.x, triangle.A.y), cv::Scalar(255, 255, 255), 1);
}

inline void drawPoint(cv::Mat& mat, tri::Point2D<long double> point2D){
    cv::circle(mat, cv::Point(point2D.x, point2D.y), 2, cv::Scalar(255, 255, 255));
}

inline std::vector<tri::Point2D<long double>> randomPoints(){
    std::vector<tri::Point2D<long double>> ret;
    std::srand(std::time(nullptr));
    for(int i = 0; i < 10; i++){
        int x = rand() % SIZE + 1;
        int y = rand() % SIZE + 1;
        ret.emplace_back(x, y);
    }
    return ret;
}

int main(){
    cv::Mat image = cv::Mat::zeros(SIZE, SIZE, CV_8UC3);

    std::vector<tri::Point2D<long double>> points = randomPoints();
    for(const auto &p: points){
        drawPoint(image, p);
    }

    tri::inc::Incremental incremental(points);
    std::set<tri::Triangle<long double>> triangles = incremental.triangulate();
    for(const auto &t: triangles){
        drawLines(image, t);
    }
    cv::imwrite("output.png", image);
    return 0;
}