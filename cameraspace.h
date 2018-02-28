#ifndef CAMERASPACE_H
#define CAMERASPACE_H

#include <glm/glm.hpp>

class CameraSpace
{
public:
    CameraSpace(const glm::mat4 view);

    vec3 getCoordinates(const glm::vec3 &worldCoordinates);

private:
    const glm::mat4 view;
};

#endif // CAMERASPACE_H
