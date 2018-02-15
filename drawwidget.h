#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <vector>
#include <primitive.h>

using std::vector;

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    ~DrawWidget();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:

public slots:

private:
    vector<Primitive*> objects;
};

#endif // DRAWWIDGET_H
