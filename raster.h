#ifndef RASTER_H
#define RASTER_H

#include <glm/glm.hpp>
#include "screen.h"

using glm::vec3;

class Raster
{
public:
    Raster(int imageWidth, int imageHeight);

    vec3 getCoordinates(Screen &screen);

private:
    int imageWidth, imageHeight;
};

#endif // RASTER_H
