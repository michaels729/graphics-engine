#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <vector>
#include <glm/glm.hpp>
#include "cameraspace.h"
#include "screenspace.h"
#include "ndcspace.h"
#include "rasterspace.h"
#include "primitive.h"

class Projector
{
public:
    Projector(const CameraSpace &cameraSpace, const ScreenSpace &screenSpace,
              const NDCSpace &ndcSpace, const RasterSpace &rasterSpace);

    std::vector<glm::vec3> project(Primitive &object) const;

private:
    const CameraSpace &cameraSpace;
    const ScreenSpace &screenSpace;
    const NDCSpace &ndcSpace;
    const RasterSpace &rasterSpace;
};

#endif // PROJECTOR_H
