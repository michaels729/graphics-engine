#define _USE_MATH_DEFINES

#include "mainwindow.h"
#include "drawwidget.h"
#include "fileuploadwidget.h"
#include <glm/glm.hpp>
#include <QApplication>
#include <iostream>
#include <math.h>

static const float inchToMm = 25.4;
enum FitResolutionGate { kFill = 0, kOverscan };

void computeScreenCoordinates(
    const float &filmApertureWidth,
    const float &filmApertureHeight,
    const uint32_t &imageWidth,
    const uint32_t &imageHeight,
    const FitResolutionGate &fitFilm,
    const float &nearClippingPLane,
    const float &focalLength,
    float &left, float &right, float &top, float &bottom)
{
    float filmAspectRatio = filmApertureWidth / filmApertureHeight;
    float deviceAspectRatio = imageWidth / (float)imageHeight;

    top = ((filmApertureHeight * inchToMm / 2) / focalLength) * nearClippingPLane;
    right = ((filmApertureWidth * inchToMm / 2) / focalLength) * nearClippingPLane;

    // field of view (horizontal)
    float fov = 2 * 180 / M_PI * atan((filmApertureWidth * inchToMm / 2) / focalLength);
    std::cerr << "Field of view " << fov << std::endl;

    float xscale = 1;
    float yscale = 1;

    switch (fitFilm) {
    default:
    case kFill:
        if (filmAspectRatio > deviceAspectRatio) {
            xscale = deviceAspectRatio / filmAspectRatio;
        }
        else {
            yscale = filmAspectRatio / deviceAspectRatio;
        }
        break;
    case kOverscan:
        if (filmAspectRatio > deviceAspectRatio) {
            yscale = filmAspectRatio / deviceAspectRatio;
        }
        else {
            xscale = deviceAspectRatio / filmAspectRatio;
        }
        break;
    }

    right *= xscale;
    top *= yscale;

    bottom = -top;
    left = -right;
}

int main(int argc, char *argv[])
{
    const uint32_t imageWidth = 640;
    const uint32_t imageHeight = 480;

    QApplication app(argc, argv);
    MainWindow w;

    // TODO: Retrieve values below as args
    const uint32_t ntris = 3156;
    const float nearClippingPlane = 1;
    const float farClippingPlane = 1000;
    float focalLength = 20; // in mm 
                            // 35mm Full Aperture in inches
    float filmApertureWidth = 0.980;
    float filmApertureHeight = 0.735;

    glm::mat4 view(
        0.707107, -0.331295, 0.624695, 0,
        0, 0.883452, 0.468521, 0,
        -0.707107, -0.331295, 0.624695, 0,
        -1.63871, -5.747777, -40.400412, 1);

    float l, r, t, b;

    computeScreenCoordinates(
        filmApertureWidth, filmApertureHeight,
        imageWidth, imageHeight,
        kOverscan,
        nearClippingPlane,
        focalLength,
        l, r, t, b);

    std::unique_ptr<const CameraSpace> cameraSpace = std::make_unique<const CameraSpace>(view);
    std::unique_ptr<const ScreenSpace> screenSpace = std::make_unique<const ScreenSpace>(nearClippingPlane);
    std::unique_ptr<const NDCSpace> ndcSpace = std::make_unique<const NDCSpace>(l, r, t, b);
    std::unique_ptr<const RasterSpace> rasterSpace = std::make_unique<const RasterSpace>(imageWidth, imageHeight);
    std::unique_ptr<Projector> projector = std::make_unique<Projector>(
            std::move(cameraSpace), std::move(screenSpace), std::move(ndcSpace), std::move(rasterSpace));

    DrawWidget dw(std::move(projector), farClippingPlane, &w);
    dw.setFocusPolicy(Qt::StrongFocus);
    dw.setMinimumWidth(imageWidth);
    dw.setMinimumHeight(imageHeight);
    dw.setMaximumWidth(imageWidth);
    dw.setMaximumHeight(imageHeight);
    w.setCentralWidget(&dw);

    FileUploadWidget uploadWidget;
    w.setMenuWidget(&uploadWidget);

    QObject::connect(&uploadWidget, SIGNAL(fileSelected(std::shared_ptr<QFile>)), &dw, SLOT(readFile(std::shared_ptr<QFile>)));

    w.show();
    return app.exec();
}
