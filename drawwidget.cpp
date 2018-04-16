#include "drawwidget.h"
#include "primitive.h"
#include "projector.h"
#include "qpainterfilm.h"
#include "triangle.h"
#include <QPainter>
#include <QRegExp>
#include <QTextStream>
#include <glm/glm.hpp>

#include "test/cow.h"

DrawWidget::DrawWidget(std::unique_ptr<Projector> projector, QWidget *parent)
    : projector(std::move(projector)), QWidget(parent)
{

}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterFilm film(painter, this->width(), this->height());
    for (std::unique_ptr<Primitive> &obj : objects) {
        projector->project(*obj, film);
    }
}

void DrawWidget::readFile(std::shared_ptr<QFile> file) {
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(file.get());
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList splitLine = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);

        //Ignore blank lines and comments
        if (splitLine.size() == 0 || splitLine[0][0] == '#') {
            continue;
        }

        //v float x, float y, float z
        //  Defines a vertex at the given location.
        //  The vertex is put into a pile, starting to be numbered at 0.
        if (!splitLine[0].compare("v")) {
            float x = splitLine[1].toFloat();
            float y = splitLine[2].toFloat();
            float z = splitLine[3].toFloat();
            vertices.push_back(glm::vec3(x, y, z));
        }
        //vt float x, float y, float z
        else if (!splitLine[0].compare("vt")) {
            float x = splitLine[1].toFloat();
            float y = splitLine[2].toFloat();
            st.push_back(glm::vec3(x, y, 0.0f));
        }
    }

    // Create triangles for cow from vertices.
    // TODO: Retrieve values from OBJ file rather than header.
    for (int i = 0; i < 9468; i += 3) {
        std::unique_ptr<Primitive> obj = std::make_unique<Triangle>(
            vertices[nvertices[i]], vertices[nvertices[i + 1]], vertices[nvertices[i + 2]],
            st[stindices[i]], st[stindices[i + 1]], st[stindices[i + 2]]);
        objects.push_back(std::move(obj));
    }
}