#ifndef RASTERSPACE_H
#define RASTERSPACE_H

#include <glm/glm.hpp>
#include "ndcspace.h"

class RasterSpace
{
public:
    RasterSpace(int imageWidth, int imageHeight);

    glm::vec3 getCoordinates(const glm::vec2 &ndcSpaceCoordinates, const float zCoord) const;

    int getImageWidth() const;

    int getImageHeight() const;

private:
    int imageWidth, imageHeight;
};

#endif // RASTERSPACE_H
