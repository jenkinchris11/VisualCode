#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <string>
#include <opencv2/opencv.hpp>
#include <exiv2/exiv2.hpp>

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

    // insert custom metadata into the loaded image
    bool insertMetadata(const std::string &key, const std::string &value);

    // TODO: implement more advanced features (masks, AI, etc.)

    const cv::Mat &image() const { return img_; }

private:
    cv::Mat img_;
    std::string loaded_path_;
};

#endif // IMAGEPROCESSOR_H
