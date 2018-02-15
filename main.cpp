#include "mainwindow.h"
#include "drawwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int width = 800, height = 600, depth = 100;
    DrawWidget dw(&w);
    dw.setFocusPolicy(Qt::StrongFocus);
    dw.resize(width, height);
    dw.makeCamera(0, width, 0, height, 0, depth);
    w.setCentralWidget(&dw);

    return a.exec();
}
