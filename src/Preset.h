#ifndef PRESET_H
#define PRESET_H

#include <string>

struct Preset {
    int brightness = 0; // [-100,100]
    double contrast = 1.0; // [0.0, 3.0]

    bool save(const std::string &path) const;
    bool load(const std::string &path);
};

#endif // PRESET_H
