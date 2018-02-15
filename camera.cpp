#include "camera.h"

Camera::Camera(float x, float y, float z)
    : x(x), y(y), z(z)
{

}

glm::vec3 Camera::getCoordinates()
{
    return vec3(x, y, z);
}
