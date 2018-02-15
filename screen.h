#ifndef SCREEN_H
#define SCREEN_H

#include <glm/glm.hpp>
#include <camera.h>

using glm::vec2;

class Screen
{
public:
    Screen(float near, float far);
    ~Screen();

    vec2 getCoordinates(Camera &camera);

private:
    float near, far;
};

#endif // SCREEN_H
