#ifndef SCREENSPACE_H
#define SCREENSPACE_H

#include <glm/glm.hpp>

class ScreenSpace
{
public:
    ScreenSpace(float near, float far);
    ~ScreenSpace();

    glm::vec2 getCoordinates(const glm::vec3 &cameraSpaceCoordinates) const;

private:
    float near, far;
};

#endif // SCREENSPACE_H
