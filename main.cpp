#include "mainwindow.h"
#include "drawwidget.h"
#include "fileuploadwidget.h"
#include <glm/glm.hpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    const uint32_t drawWidgetWidth = 640;
    const uint32_t drawWidgetHeight = 480;

    QApplication app(argc, argv);
    MainWindow w;

    // TODO: Retrieve values below as args
    const uint32_t ntris = 3156;
    const float nearClippingPlane = 1;
    const float farClippingPLane = 1000;
    float focalLength = 20; // in mm 
                            // 35mm Full Aperture in inches
    float filmApertureWidth = 0.980;
    float filmApertureHeight = 0.735;

    glm::mat4 view(
        0.707107, -0.331295, 0.624695, 0,
        0, 0.883452, 0.468521, 0,
        -0.707107, -0.331295, 0.624695, 0,
        -1.63871, -5.747777, -40.400412, 1);

    // TODO: Properly calculate ndc t, b, l, r values u
    int l = -1000, r = 1000, t = -1000, b = 1000;

    std::unique_ptr<const CameraSpace> cameraSpace = std::make_unique<const CameraSpace>(view);
    std::unique_ptr<const ScreenSpace> screenSpace = std::make_unique<const ScreenSpace>(nearClippingPlane);
    std::unique_ptr<const NDCSpace> ndcSpace = std::make_unique<const NDCSpace>(l, r, t, b);
    std::unique_ptr<const RasterSpace> rasterSpace = std::make_unique<const RasterSpace>(drawWidgetWidth, drawWidgetHeight);
    std::unique_ptr<Projector> projector = std::make_unique<Projector>(
            std::move(cameraSpace), std::move(screenSpace), std::move(ndcSpace), std::move(rasterSpace));

    DrawWidget dw(std::move(projector), &w);
    dw.setFocusPolicy(Qt::StrongFocus);
    dw.setMinimumWidth(drawWidgetWidth);
    dw.setMinimumHeight(drawWidgetHeight);
    dw.setMaximumWidth(drawWidgetWidth);
    dw.setMaximumHeight(drawWidgetHeight);
    w.setCentralWidget(&dw);

    FileUploadWidget uploadWidget;
    w.setMenuWidget(&uploadWidget);

    QObject::connect(&uploadWidget, SIGNAL(fileSelected(std::shared_ptr<QFile>)), &dw, SLOT(readFile(std::shared_ptr<QFile>)));

    w.show();
    return app.exec();
}
