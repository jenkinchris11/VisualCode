#include "Catalog.h"
#include <filesystem>

namespace fs = std::filesystem;

Catalog::Catalog(const std::string &path) : path_(path) {}

bool Catalog::scan() {
    images_.clear();
    try {
        for (const auto &entry : fs::directory_iterator(path_)) {
            if (!entry.is_regular_file()) continue;
            auto ext = entry.path().extension().string();
            if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".dng" || ext == ".tiff" || ext == ".bmp") {
                images_.push_back(entry.path().string());
            }
        }
    } catch (const std::exception &e) {
        return false;
    }
    return true;
}
