#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include "ImageProcessor.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openImage();
    void updateImage();

private:
    ImageProcessor processor_;
    QLabel *imageLabel_;
    QSlider *brightSlider_;
    QSlider *contrastSlider_;
};

#endif // MAINWINDOW_H
