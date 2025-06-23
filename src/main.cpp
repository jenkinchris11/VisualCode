#include "Catalog.h"
#include "ImageProcessor.h"
#include "Preset.h"
#include <iostream>
#include <filesystem>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <catalog_path> [preset_file]" << std::endl;
        return 1;
    }

    Preset preset;
    if (argc > 2) {
        if (!preset.load(argv[2])) {
            std::cerr << "Failed to load preset " << argv[2] << std::endl;
            return 1;
        }
    } else {
        preset.brightness = 10;
        preset.contrast = 1.2;
    }

    Catalog catalog(argv[1]);
    if (!catalog.scan()) {
        std::cerr << "Failed to scan catalog" << std::endl;
        return 1;
    }

    std::cout << "Loaded " << catalog.images().size() << " images." << std::endl;

    // simple loop through images
    for (const auto &path : catalog.images()) {
        ImageProcessor proc;
        if (!proc.load(path)) {
            std::cerr << "Failed to load " << path << std::endl;
            continue;
        }
        proc.adjustBrightness(preset.brightness);
        proc.adjustContrast(preset.contrast);

        // apply mask to center region as a basic example
        cv::Mat mask(proc.image().size(), CV_8UC1, cv::Scalar(0));
        cv::Rect rect(proc.image().cols/4, proc.image().rows/4,
                      proc.image().cols/2, proc.image().rows/2);
        cv::rectangle(mask, rect, cv::Scalar(255), cv::FILLED);
        proc.applyMask(mask);

        // save to output folder
        std::string output = "processed_" + std::string(std::filesystem::path(path).filename());
        proc.save(output);
        std::cout << "Processed " << path << " -> " << output << std::endl;
    }

    std::cout << "Processing complete." << std::endl;
    return 0;
}
