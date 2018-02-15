#include "drawwidget.h"
#include "primitive.h"
#include <QPainter>
#include <glm/glm.hpp>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
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
    for (Primitive *obj : objects) {
        for (vec2 coord : obj->getPixelCoordinates()) {
            painter.drawPoint(
                (coord.x + 1) / 2 * this->width(),
                (1 - coord.y) / 2 * this->height()
            );
        }
    }
}

void DrawWidget::keyPressEvent(QKeyEvent *event)
{

}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{

}

