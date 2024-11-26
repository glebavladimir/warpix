#include <filesystem>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    const filesystem::path cwd = std::filesystem::current_path();

    const Mat originalImage = imread(cwd / "../images/krakow_old.png");
    const Mat newImage = imread(cwd / "../images/krakow_new.png");

    if (originalImage.empty() || newImage.empty()) {
        cout << "Could not open or find the images!" << endl;
        return -1;
    }

    const vector originalPoints = {
        Point2f(1246, 647),
        Point2f(939, 704),
        Point2f(984, 786),
        Point2f(1192, 597),
        Point2f(1174, 407),
        Point2f(951, 495),
        Point2f(837, 367),
        Point2f(840, 385),
        Point2f(780, 102),
        Point2f(610, 913),
        Point2f(440, 728),
        Point2f(446, 1114),
        Point2f(1617, 875),
        Point2f(1390, 776),
        Point2f(1690, 345),
        Point2f(880, 616),
        Point2f(921, 685),
        Point2f(1183, 770),
    };

    const vector newImagePoints = {
        Point2f(1246, 647),
        Point2f(938, 706),
        Point2f(989, 786),
        Point2f(1180, 597),
        Point2f(1158, 410),
        Point2f(932, 502),
        Point2f(797, 371),
        Point2f(798, 392),
        Point2f(706, 89),
        Point2f(637, 915),
        Point2f(427, 741),
        Point2f(494, 1093),
        Point2f(1619, 847),
        Point2f(1397, 761),
        Point2f(1698, 335),
        Point2f(879, 622),
        Point2f(912, 696),
        Point2f(1190, 770),
    };

    const Mat H = findHomography(originalPoints, newImagePoints, RANSAC);

    Mat warpedImage;
    warpPerspective(newImage, warpedImage, H, originalImage.size());

    imshow("Original Image", originalImage);
    imshow("Warped Image", warpedImage);

    imwrite("images/result/aligned_image.jpg", warpedImage);

    waitKey(0);
    destroyAllWindows();

    return 0;
}