#include "mainwindow.h"
#include "drawwidget.h"
#include "fileuploadwidget.h"
#include <glm/glm.hpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    // TODO: Retrieve values below as args
    const uint32_t ntris = 3156;
    const float nearClippingPlane = 1;
    const float farClippingPLane = 1000;
    float focalLength = 20; // in mm 
                            // 35mm Full Aperture in inches
    float filmApertureWidth = 0.980;
    float filmApertureHeight = 0.735;

    const unsigned int width = 640;
    const unsigned int height = 480;
    glm::mat4 view(
        0.707107, -0.331295, 0.624695, 0,
        0, 0.883452, 0.468521, 0,
        -0.707107, -0.331295, 0.624695, 0,
        -1.63871, -5.747777, -40.400412, 1);

    // TODO: Properly calculate ndc t, b, l, r values u
    int l = 0, r = 200, t = 0, b = 200;

    const CameraSpace cameraSpace(view);
    const ScreenSpace screenSpace(nearClippingPlane);
    const NDCSpace ndcSpace(l, r, t, b);
    const RasterSpace rasterSpace(width, height);
    Projector projector(cameraSpace, screenSpace, ndcSpace, rasterSpace);

    DrawWidget dw(projector, &w);
    dw.setFocusPolicy(Qt::StrongFocus);
    dw.resize(width, height);
    w.setCentralWidget(&dw);

    FileUploadWidget uploadWidget;
    w.setMenuWidget(&uploadWidget);

    QObject::connect(&uploadWidget, SIGNAL(fileSelected(std::shared_ptr<QFile>)), &dw, SLOT(readFile(std::shared_ptr<QFile>)));

    return app.exec();
}
