#include "align.h"
#include <opencv2/opencv.hpp>

namespace WarpixAlign {
    cv::Mat alignImages(const cv::Mat& targetImage, const cv::Mat& baseImage, 
                        const std::vector<cv::Point2f>& targetPoints, 
                        const std::vector<cv::Point2f>& basePoints) {
        cv::Mat H = cv::findHomography(basePoints, targetPoints, cv::RANSAC);
        cv::Mat alignedImage;
        cv::warpPerspective(targetImage, alignedImage, H, baseImage.size());
        return alignedImage;
    }
}
