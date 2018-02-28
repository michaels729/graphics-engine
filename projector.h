#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <glm/glm.hpp>
#include <cameraspace.h>
#include <screenspace.h>
#include <ndcspace.h>
#include <rasterspace.h>

class Projector
{
public:
    Projector(const CameraSpace &cameraSpace, const ScreenSpace &screenSpace,
              const NDCSpace &ndcSpace, const RasterSpace &rasterSpace);
    glm::vec3 project(glm::vec3 worldCoordinates);

private:
    const CameraSpace &cameraSpace;
    const ScreenSpace &screenSpace;
    const NDCSpace &ndcSpace;
    const RasterSpace &rasterSpace;
};

#endif // PROJECTOR_H
