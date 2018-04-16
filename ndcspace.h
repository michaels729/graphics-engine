#ifndef NDCSPACE_H
#define NDCSPACE_H

#include <glm/glm.hpp>

class NDCSpace
{
public:
    NDCSpace(float l, float r, float t, float b);

    glm::vec2 getCoordinates(const glm::vec2 &screenSpaceCoordinates) const;

private:
    float l, r, t, b;
};

#endif // NDCSPACE_H
