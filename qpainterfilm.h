#ifndef QPAINTERFILM_H
#define QPAINTERFILM_H

#include <QPainter>
#include "film.h"

class QPainterFilm :
    public Film
{
public:
    QPainterFilm(QPainter &qPainter, QPen &qPen, int width, int height);
    void write(int xPos, int yPos, int zDepth, int r, int g, int b) override;

private:
    QPainter &qPainter;
    QPen &qPen;
    int const width, const height;
    std::vector<int> depthBuffer;
};

#endif QPAINTERFILM_H
