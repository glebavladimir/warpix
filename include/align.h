#ifndef ALIGN_H
#define ALIGN_H

#include <opencv2/opencv.hpp>
#include <vector>

namespace WarpixAlign {
    cv::Mat alignImages(const cv::Mat& targetImage, const cv::Mat& baseImage, 
                        const std::vector<cv::Point2f>& targetPoints, 
                        const std::vector<cv::Point2f>& basePoints);
}

#endif
