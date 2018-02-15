#include "ndc.h"

NDC::NDC(int l, int r, int t, int b)
    : l(l), r(r), t(t), b(b)
{

}

glm::vec2 NDC::getCoordinates(Camera &camera, Screen &screen)
{
    vec2 screenSpaceCoords = screen.getCoordinates(camera);
    return vec2(
       2 * screenSpaceCoords.x - r - l / (r - l),
       2 * screenSpaceCoords.y - t - b / (t - b)
    );
}
