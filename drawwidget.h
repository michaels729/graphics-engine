#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QFile>
#include <vector>
#include <memory>
#include "projector.h"
#include "primitive.h"

using std::vector;

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(const Projector &projector, QWidget *parent = nullptr);
    ~DrawWidget();
    void paintEvent(QPaintEvent *event) override;

public slots:
    void readFile(std::shared_ptr<QFile> file);

private:
    vector<std::unique_ptr<Primitive>> objects;
    const Projector &projector;
};

#endif // DRAWWIDGET_H
