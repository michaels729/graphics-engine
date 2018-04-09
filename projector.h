#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <memory>
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
    Projector(std::unique_ptr<const CameraSpace> cameraSpace,
        std::unique_ptr<const ScreenSpace> screenSpace,
        std::unique_ptr<const NDCSpace> ndcSpace,
        std::unique_ptr<const RasterSpace> rasterSpace);

    void project(Primitive &primitive, Film &film) const;

private:
    std::unique_ptr<const CameraSpace> cameraSpace;
    std::unique_ptr<const ScreenSpace> screenSpace;
    std::unique_ptr<const NDCSpace> ndcSpace;
    std::unique_ptr<const RasterSpace> rasterSpace;

    glm::vec3 convertToRaster(const glm::vec3 &worldCoordinates) const;
};

#endif // PROJECTOR_H
