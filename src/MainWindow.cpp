#include "MainWindow.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QAction>
#include <QImage>
#include <QPixmap>
#include <opencv2/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto openAction = menuBar()->addAction("Open");
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    imageLabel_ = new QLabel(this);
    imageLabel_->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel_);

    brightSlider_ = new QSlider(Qt::Horizontal, this);
    brightSlider_->setRange(-100, 100);
    brightSlider_->setValue(0);
    connect(brightSlider_, &QSlider::valueChanged, this, &MainWindow::updateImage);
    layout->addWidget(brightSlider_);

    contrastSlider_ = new QSlider(Qt::Horizontal, this);
    contrastSlider_->setRange(50, 150);
    contrastSlider_->setValue(100);
    connect(contrastSlider_, &QSlider::valueChanged, this, &MainWindow::updateImage);
    layout->addWidget(contrastSlider_);

    setCentralWidget(central);
    resize(800, 600);
}

void MainWindow::openImage() {
    QString file = QFileDialog::getOpenFileName(this, "Open Image");
    if (file.isEmpty()) return;
    processor_.load(file.toStdString());
    brightSlider_->setValue(0);
    contrastSlider_->setValue(100);
    updateImage();
}

void MainWindow::updateImage() {
    if (processor_.image().empty()) return;
    ImageProcessor proc = processor_; // copy to preserve original
    proc.adjustBrightness(brightSlider_->value());
    proc.adjustContrast(contrastSlider_->value() / 100.0);

    cv::Mat rgb;
    cv::cvtColor(proc.image(), rgb, cv::COLOR_BGR2RGB);
    QImage img(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
    imageLabel_->setPixmap(QPixmap::fromImage(img));
}
