#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "primitive.h"
#include <glm/glm.hpp>

class Triangle :
    public Primitive
{
public:
    Triangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2);
    ~Triangle();

    std::vector<glm::vec3> getVertices() const override;

private:
    glm::vec3 const &v0, const &v1, const &v2;
};

#endif // TRIANGLE_H
