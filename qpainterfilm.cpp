#include "QPainterFilm.h"

QPainterFilm::QPainterFilm(QPainter &qPainter, QPen &qPen)
    : qPainter(qPainter), qPen(qPen)
{
    qPainter.setPen(qPen);
}

void QPainterFilm::write(int posX, int posY, int r, int g, int b)
{
    qPen.setColor(QColor(r, g, b));
    qPainter.drawPoint(posX, posY);
}
