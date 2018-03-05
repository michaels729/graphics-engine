#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <vector>
#include <glm/glm.hpp>
#include <QPainter>
#include "cameraspace.h"
#include "screenspace.h"
#include "ndcspace.h"
#include "rasterspace.h"
#include "primitive.h"
#include "film.h"

class Projector
{
public:
    Projector(const CameraSpace &cameraSpace, const ScreenSpace &screenSpace,
              const NDCSpace &ndcSpace, const RasterSpace &rasterSpace);

    std::vector<glm::vec3> project(Primitive &object, Film &film) const;

private:
    const CameraSpace &cameraSpace;
    const ScreenSpace &screenSpace;
    const NDCSpace &ndcSpace;
    const RasterSpace &rasterSpace;

    glm::vec3 Projector::convertToRaster(const glm::vec3 &worldCoordinates) const;
};

#endif // PROJECTOR_H
