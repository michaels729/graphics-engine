#ifndef NDCSPACE_H
#define NDCSPACE_H

#include <glm/glm.hpp>

class NDCSpace
{
public:
    NDCSpace(int l, int r, int t, int b);

    glm::vec2 getCoordinates(const glm::vec2 &screenSpaceCoordinates) const;

private:
    int l, r, t, b;
};

#endif // NDCSPACE_H
