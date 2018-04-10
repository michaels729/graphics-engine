#include "QPainterFilm.h"

QPainterFilm::QPainterFilm(QPainter &qPainter, QPen &qPen, uint32_t width, uint32_t height)
    : qPainter(qPainter), qPen(qPen), width(width), height(height), depthBuffer(width * height)
{
    qPainter.setPen(qPen);
}

void QPainterFilm::write(uint32_t xPos, uint32_t yPos, float zDepth, float r, float g, float b)
{
    uint32_t bufferIdx = yPos * width + xPos;
    if (zDepth < depthBuffer[bufferIdx]) {
        qPen.setColor(QColor(r * 255, g * 255, b * 255));
        qPainter.drawPoint(xPos, yPos);
        depthBuffer[bufferIdx] = zDepth;
    }
}
