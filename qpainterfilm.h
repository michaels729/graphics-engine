#ifndef QPAINTERFILM_H
#define QPAINTERFILM_H

#include <QPainter>
#include "film.h"

class QPainterFilm :
    public Film
{
public:
    QPainterFilm(QPainter &qPainter, QPen &qPen, uint32_t width, uint32_t height);
    void write(uint32_t xPos, uint32_t yPos, float zDepth, float r, float g, float b) override;

private:
    QPainter &qPainter;
    QPen &qPen;
    uint32_t const width, const height;
    std::vector<float> depthBuffer;
};

#endif QPAINTERFILM_H
