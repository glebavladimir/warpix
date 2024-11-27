#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace WarpixConfig {
    struct Config {
        std::string baseImagePath;
        std::string targetImagePath;
        std::string outputImagePath;
        std::string pointsFilePath;
    };

    Config parseArguments(int argc, char* argv[]);
}

#endif
