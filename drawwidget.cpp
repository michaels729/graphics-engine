#include "drawwidget.h"
#include "primitive.h"
#include "projector.h"
#include <QPainter>
#include <glm/glm.hpp>

DrawWidget::DrawWidget(const Projector &projector, QWidget *parent)
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
    for (Primitive *obj : objects) {
        for (const glm::vec2 &p : projector.project(*obj)) {
            painter.drawPoint(p.x, p.y);
        }
    }
}

void DrawWidget::keyPressEvent(QKeyEvent *event)
{

}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{

}

