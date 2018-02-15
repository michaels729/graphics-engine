#include "screen.h"

Screen::Screen(Camera *camera, float near, float far)
    : camera(camera), near(near), far(far)
{

}

glm::vec2 Screen::getCoordinates(Camera &camera)
{
    vec2 cameraSpaceCoords = camera.getCoordinates();
    return vec2(
        near * cameraSpaceCoords.x / -cameraSpaceCoords.z,
        near * cameraSpaceCoords.y / -cameraSpaceCoords.z
    );
}
