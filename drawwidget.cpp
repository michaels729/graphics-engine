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
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QPen pen;
    QPainterFilm film(painter, pen, this->width(), this->height());
    for (std::unique_ptr<Primitive> &obj : objects) {
        projector.project(*obj, film);
    }
}

void DrawWidget::readFile(std::shared_ptr<QFile> file) {
    // TODO
}