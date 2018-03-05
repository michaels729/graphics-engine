#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "primitive.h"
#include <glm/glm.hpp>

class Triangle :
    public Primitive
{
public:
    Triangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2,
        const glm::vec3 &c0, const glm::vec3 &c1, const glm::vec3 &c2);
    ~Triangle();

    std::vector<glm::vec3> getVertices() const override;
    std::vector<glm::vec3> getColors() const override;

private:
    glm::vec3 const &v0, const &v1, const &v2;
    glm::vec3 const &c0, const &c1, const &c2;
};

#endif // TRIANGLE_H
