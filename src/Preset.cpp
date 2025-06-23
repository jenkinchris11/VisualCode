#include "Preset.h"
#include <fstream>

bool Preset::save(const std::string &path) const {
    std::ofstream out(path);
    if (!out) return false;
    out << brightness << "\n" << contrast << "\n";
    return true;
}

bool Preset::load(const std::string &path) {
    std::ifstream in(path);
    if (!in) return false;
    in >> brightness >> contrast;
    return true;
}
