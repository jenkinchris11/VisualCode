#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <vector>

class Catalog {
public:
    explicit Catalog(const std::string &path);

    // load image file paths
    bool scan();

    const std::vector<std::string> &images() const { return images_; }

private:
    std::string path_;
    std::vector<std::string> images_;
};

#endif // CATALOG_H
