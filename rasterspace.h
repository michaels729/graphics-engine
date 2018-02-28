#ifndef RASTERSPACE_H
#define RASTERSPACE_H

#include <glm/glm.hpp>
#include "ndcspace.h"

class RasterSpace
{
public:
    RasterSpace(int imageWidth, int imageHeight);

    glm::vec3 getCoordinates(const glm::vec3 &ndcSpaceCoordinates, const float zCoord);

private:
    int imageWidth, imageHeight;
};

#endif // RASTERSPACE_H
