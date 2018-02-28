#include "cameraspace.h"
#include "glm/vec4.hpp"

CameraSpace::CameraSpace(mat4 view)
    : view(view)
{

}

glm::vec3 CameraSpace::getCoordinates(const vec3 &worldCoordinates)
{
    return glm::vec3(view * glm::vec4(worldCoordinates, 1.0f));
}
