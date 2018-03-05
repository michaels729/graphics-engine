#ifndef QPAINTERFILM_H
#define QPAINTERFILM_H

#include <QPainter>
#include "film.h"

class QPainterFilm :
    public Film
{
public:
    QPainterFilm(QPainter &qPainter, QPen &qPen);
    void write(int posX, int posY, int r, int g, int b) override;

private:
    QPainter &qPainter;
    QPen &qPen;
};

#endif QPAINTERFILM_H
