#include "ImageProcessor.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

ImageProcessor::ImageProcessor() {}

bool ImageProcessor::load(const std::string &path) {
    img_ = cv::imread(path, cv::IMREAD_UNCHANGED);
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

void ImageProcessor::applyMask(const cv::Mat &mask) {
    if (img_.empty() || mask.empty()) return;
    cv::Mat masked;
    img_.copyTo(masked, mask);
    img_ = masked;
}
