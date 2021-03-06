#include "screenspace.h"

ScreenSpace::ScreenSpace(float near)
  : near(near)
{

}

glm::vec2 ScreenSpace::getCoordinates(const glm::vec3 &cameraSpaceCoordinates) const
{
    return glm::vec2(
        near * cameraSpaceCoordinates.x / -cameraSpaceCoordinates.z,
        near * cameraSpaceCoordinates.y / -cameraSpaceCoordinates.z
    );
}
