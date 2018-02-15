#include "raster.h"

Raster::Raster()
{

}

Raster::Raster(int imageWidth, int imageHeight)
    : imageWidth(imageWidth), imageHeight(imageHeight)
{

}

glm::vec3 Raster::getCoordinates(Camera &camera, Screen &screen)
{
    vec3 screenSpaceCoords = screen.getCoordinates(camera);
    vec3 cameraSpaceCoords = camera.getCoordinates();
    return vec3(
        (screenSpaceCoords.x + 1) / 2 * imageWidth,
        (1 - screenSpaceCoords.y) / 2 * imageHeight,
        -cameraSpaceCoords.z
    );
}
