#include "drawwidget.h"
#include "primitive.h"
#include "projector.h"
#include "qpainterfilm.h"
#include <QPainter>
#include <glm/glm.hpp>

DrawWidget::DrawWidget(const Projector &proj, QWidget *parent)
    : projector(projector), QWidget(parent)
{

}

DrawWidget::~DrawWidget()
{
    for (Primitive *obj : objects) {
        delete obj;
    }
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QPen pen;
    QPainterFilm film(painter, pen, this->width(), this->height());
    for (Primitive *obj : objects) {
        projector.project(*obj, film);
    }
}
