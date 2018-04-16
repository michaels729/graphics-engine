#include "QPainterFilm.h"

QPainterFilm::QPainterFilm(QPainter &qPainter, uint32_t width, uint32_t height, const float far)
    : qPainter(qPainter), width(width), height(height), depthBuffer(width * height, far)
{

}

void QPainterFilm::write(uint32_t xPos, uint32_t yPos, float zDepth, float r, float g, float b)
{
    uint32_t bufferIdx = yPos * width + xPos;
    if (zDepth < depthBuffer[bufferIdx]) {
        QPen qPen(QColor(r * 255, g * 255, b * 255));
        qPainter.setPen(qPen);
        qPainter.drawPoint(xPos, yPos);
        depthBuffer[bufferIdx] = zDepth;
    }
}
