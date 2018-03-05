#include "projector.h"

Projector::Projector(const CameraSpace &cameraSpace, const ScreenSpace &screenSpace,
                     const NDCSpace &ndcSpace, const RasterSpace &rasterSpace)
    : cameraSpace(cameraSpace), screenSpace(screenSpace), ndcSpace(ndcSpace), rasterSpace(rasterSpace)
{

}

std::vector<glm::vec3> Projector::project(Primitive &primitive) const
{
    std::vector<glm::vec3> rasterPoints;
    for (const glm::vec3 worldCoordinates : primitive.getVertices()) {
        glm::vec3 cameraSpaceCoords = cameraSpace.getCoordinates(worldCoordinates);
        glm::vec2 screenSpaceCoords = screenSpace.getCoordinates(cameraSpaceCoords);
        glm::vec2 ndcSpaceCoords = ndcSpace.getCoordinates(screenSpaceCoords);
        rasterPoints.push_back(rasterSpace.getCoordinates(ndcSpaceCoords, cameraSpaceCoords.z));
    }
    return rasterPoints;
}
