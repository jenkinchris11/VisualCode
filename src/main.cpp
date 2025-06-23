#include "Catalog.h"
#include "ImageProcessor.h"
#include <iostream>
#include <filesystem>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <catalog_path>" << std::endl;
        return 1;
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
        // placeholder: automatic AI analysis would go here
        proc.adjustBrightness(10); // example operation
        proc.adjustContrast(1.2);  // example operation

        // insert simple AI metadata
        proc.insertMetadata("Exif.Image.Software", "VisualCode AI v1");

        // save to output folder
        std::string output =
            "processed_" + std::filesystem::path(path).filename().string();
        proc.save(output);
        std::cout << "Processed " << path << " -> " << output << std::endl;
    }

    std::cout << "Processing complete." << std::endl;
    return 0;
}
