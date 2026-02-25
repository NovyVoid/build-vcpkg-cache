#include <QtWidgets/QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    // Basic Qt init
    QApplication a(argc, argv);
    
    // Basic OpenCV init
    cv::Mat image = cv::Mat::zeros(100, 100, CV_8UC3);
    
    std::cout << "Cache Triggered Successfully!" << std::endl;
    return 0;
}