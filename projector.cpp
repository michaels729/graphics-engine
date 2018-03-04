#include "projector.h"

Projector::Projector(const CameraSpace &cameraSpace, const ScreenSpace &screenSpace,
                     const NDCSpace &ndcSpace, const RasterSpace &rasterSpace)
    : cameraSpace(cameraSpace), screenSpace(screenSpace), ndcSpace(ndcSpace), rasterSpace(rasterSpace)
{

}

glm::vec3 Projector::project(glm::vec3 worldCoordinates)
{
    glm::vec3 cameraSpaceCoords = cameraSpace.getCoordinates(worldCoordinates);
    glm::vec2 screenSpaceCoords = screenSpace.getCoordinates(cameraSpaceCoords);
    glm::vec2 ndcSpaceCoords = ndcSpace.getCoordinates(screenSpaceCoords);
    return rasterSpace.getCoordinates(ndcSpaceCoords, cameraSpaceCoords.z);
}
