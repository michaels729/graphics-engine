#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

using glm::vec3;

class Camera
{
public:
    Camera(float x, float y, float z);

    vec3 getCoordinates();

private:
    float x, y, z;
};

#endif // CAMERA_H
