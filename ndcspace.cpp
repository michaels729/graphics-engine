#include "ndcspace.h"

NDCSpace::NDCSpace(int l, int r, int t, int b)
    : l(l), r(r), t(t), b(b)
{

}

glm::vec2 NDCSpace::getCoordinates(const glm::vec2 &screenSpaceCoordinates) const
{
    return glm::vec2(
       2 * screenSpaceCoordinates.x - r - l / (r - l),
       2 * screenSpaceCoordinates.y - t - b / (t - b)
    );
}
