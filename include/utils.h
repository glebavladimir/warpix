#ifndef UTILS_H
#define UTILS_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

namespace WarpixUtils {
    cv::Mat loadImage(const std::string& path, const std::string& label);
    void saveImage(const cv::Mat& image, const std::string& path);
    void showImagesComparison(const cv::Mat &image1, const cv::Mat &image2);
    std::pair<std::vector<cv::Point2f>, std::vector<cv::Point2f>> parsePoints(const std::string& filePath);
}

#endif
