#include "rasterspace.h"

RasterSpace::RasterSpace(int imageWidth, int imageHeight)
    : imageWidth(imageWidth), imageHeight(imageHeight)
{

}

glm::vec3 RasterSpace::getCoordinates(const glm::vec2 &ndcSpaceCoordinates, const float zCoord) const
{
    return glm::vec3(
        (ndcSpaceCoordinates.x + 1) / 2 * imageWidth,
        (1 - ndcSpaceCoordinates.y) / 2 * imageHeight,
        -zCoord // Negate so we can compare as a positive depth values.
    );
}
