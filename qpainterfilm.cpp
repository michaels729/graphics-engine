#include "QPainterFilm.h"

QPainterFilm::QPainterFilm(QPainter &qPainter, QPen &qPen, int width, int height)
    : qPainter(qPainter), qPen(qPen), width(width), height(height), depthBuffer(width * height)
{
    qPainter.setPen(qPen);
}

void QPainterFilm::write(int xPos, int yPos, int zDepth, int r, int g, int b)
{
    int bufferIdx = yPos * width + xPos;
    if (zDepth < depthBuffer[bufferIdx]) {
        qPen.setColor(QColor(r, g, b));
        qPainter.drawPoint(xPos, yPos);
        depthBuffer[bufferIdx] = zDepth;
    }
}
