#ifndef NDC_H
#define NDC_H

#include "screen.h"

class NDC
{
public:
    NDC(int l, int r, int t, int b);

    vec2 getCoordinates(Camera &camera, Screen &screen);

private:
    int l, r, t, b;
};

#endif // NDC_H
