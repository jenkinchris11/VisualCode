#include "ImageProcessor.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <exiv2/exiv2.hpp>

ImageProcessor::ImageProcessor() {}

bool ImageProcessor::load(const std::string &path) {
    img_ = cv::imread(path, cv::IMREAD_UNCHANGED);
    if (!img_.empty()) {
        loaded_path_ = path;
    } else {
        loaded_path_.clear();
    }
    return !img_.empty();
}

bool ImageProcessor::save(const std::string &path) {
    if (img_.empty()) return false;
    return cv::imwrite(path, img_);
}

void ImageProcessor::adjustBrightness(int value) {
    if (img_.empty()) return;
    img_.convertTo(img_, -1, 1, value);
}

void ImageProcessor::adjustContrast(double alpha) {
    if (img_.empty()) return;
    img_.convertTo(img_, -1, alpha, 0);
}

bool ImageProcessor::insertMetadata(const std::string &key, const std::string &value) {
    if (loaded_path_.empty()) return false;
    try {
        auto image = Exiv2::ImageFactory::open(loaded_path_);
        image->readMetadata();
        Exiv2::ExifData &exifData = image->exifData();
        exifData[key] = value;
        image->setExifData(exifData);
        image->writeMetadata();
        return true;
    } catch (const Exiv2::Error &e) {
        return false;
    }
}
