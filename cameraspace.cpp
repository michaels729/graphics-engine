#include "cameraspace.h"
#include "glm/vec4.hpp"

CameraSpace::CameraSpace(glm::mat4 view)
    : view(view)
{

}

glm::vec3 CameraSpace::getCoordinates(const glm::vec3 &worldCoordinates) const
{
    return glm::vec3(view * glm::vec4(worldCoordinates, 1.0f));
}
