#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <string>
#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
    ImageProcessor();

    // load image from file
    bool load(const std::string &path);

    // save image to file
    bool save(const std::string &path);

    // adjust brightness [-100,100]
    void adjustBrightness(int value);

    // adjust contrast [0.0, 3.0]
    void adjustContrast(double alpha);

    // Apply a mask before saving/processing. Non-zero mask pixels are kept.
    void applyMask(const cv::Mat &mask);

    // TODO: implement more advanced features (AI tools, etc.)

    const cv::Mat &image() const { return img_; }

private:
    cv::Mat img_;
};

#endif // IMAGEPROCESSOR_H
