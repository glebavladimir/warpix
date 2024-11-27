#include <iostream>
#include "config.h"
#include "utils.h"
#include "align.h"

using namespace std;

void processAlignment(const string& baseImagePath, const string& targetImagePath,
                      const string& outputImagePath, const string& pointsFilePath) {
    cout << "Loading images..." << endl;
    const auto baseImage = WarpixUtils::loadImage(baseImagePath, "base");
    const auto targetImage = WarpixUtils::loadImage(targetImagePath, "target");

    cout << "Parsing points..." << endl;
    auto [basePoints, targetPoints] = WarpixUtils::parsePoints(pointsFilePath);

    if (basePoints.size() != targetPoints.size() || basePoints.size() < 4) {
        throw runtime_error("Insufficient or mismatched points for alignment.");
    }

    cout << "Aligning images..." << endl;
    const auto alignedImage = WarpixAlign::alignImages(targetImage, baseImage, targetPoints, basePoints);

    cout << "Saving aligned image..." << endl;
    WarpixUtils::saveImage(alignedImage, outputImagePath);

    cout << "Showing image comparison..." << endl;
    WarpixUtils::showImagesComparison(baseImage, alignedImage);

    cout << "Alignment complete. Output saved to " << outputImagePath << endl;
}

int main(const int argc, char* argv[]) {
    try {
        if (argc < 5 || string(argv[1]) == "--help") {
            cout << "Usage: Warpix --base <base_image> --target <target_image> --output <output_image> --points <points_file>" << endl;
            return 0;
        }

        auto [baseImagePath, targetImagePath, outputImagePath, pointsFilePath] = WarpixConfig::parseArguments(argc, argv);
        processAlignment(baseImagePath, targetImagePath, outputImagePath, pointsFilePath);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}
