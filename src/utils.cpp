#include "utils.h"
#include <opencv2/opencv.hpp>
#include <yaml-cpp/yaml.h>
#include <stdexcept>

namespace WarpixUtils {
    using namespace cv;

    bool showFirstImage = true;
    Mat img1, img2;

    Mat loadImage(const std::string &path, const std::string &label) {
        Mat image = imread(path);
        if (image.empty()) {
            throw std::runtime_error("Failed to load " + label + " image: " + path);
        }
        return image;
    }

    void saveImage(const Mat &image, const std::string &path) {
        if (!imwrite(path, image)) {
            throw std::runtime_error("Failed to save image: " + path);
        }
    }

    void renderImage() {
        showFirstImage = !showFirstImage;
        imshow("Image Comparison", showFirstImage ? img1 : img2);
    }

    void showImagesComparison(const Mat &image1, const Mat &image2) {
        img1 = image1.clone();
        img2 = image2.clone();
        showFirstImage = true;

        if (img1.empty() || img2.empty()) {
            std::cerr << "Error: One or both images are empty!" << std::endl;
            return;
        }

        namedWindow("Image Comparison", WINDOW_AUTOSIZE);
        renderImage();
        setMouseCallback("Image Comparison", [](const int event, int x, int y, int flags, void *userdata) {
            if (event == EVENT_LBUTTONDOWN) {
                renderImage();
            }
        }, nullptr);
        waitKey(0);
        destroyWindow("Image Comparison");
    }


    std::pair<std::vector<Point2f>, std::vector<Point2f> > parsePoints(const std::string &filePath) {
        YAML::Node pointsData = YAML::LoadFile(filePath);
        std::vector<Point2f> basePoints, targetPoints;

        for (const auto &point: pointsData["base_image_points"]) {
            basePoints.emplace_back(point[0].as<float>(), point[1].as<float>());
        }
        for (const auto &point: pointsData["target_image_points"]) {
            targetPoints.emplace_back(point[0].as<float>(), point[1].as<float>());
        }

        return {basePoints, targetPoints};
    }
}
