#include "config.h"
#include <stdexcept>

namespace WarpixConfig {
    Config parseArguments(const int argc, char* argv[]) {
        Config config;
        for (int i = 1; i < argc; i += 2) {
            if (std::string arg = argv[i]; arg == "--base") {
                config.baseImagePath = argv[i + 1];
            } else if (arg == "--target") {
                config.targetImagePath = argv[i + 1];
            } else if (arg == "--output") {
                config.outputImagePath = argv[i + 1];
            } else if (arg == "--points") {
                config.pointsFilePath = argv[i + 1];
            } else {
                throw std::invalid_argument("Unknown argument: " + arg);
            }
        }
        return config;
    }
}
