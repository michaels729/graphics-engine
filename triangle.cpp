#include "triangle.h"
#include "projector.h"


Triangle::Triangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2,
    const glm::vec3 &c0, const glm::vec3 &c1, const glm::vec3 &c2)
    : v0(v0), v1(v1), v2(v2), c0(c0), c1(c1), c2(c2)
{
}


Triangle::~Triangle()
{
}

std::vector<glm::vec3> Triangle::getVertices() const
{
    std::vector<glm::vec3> vertices(3);
    vertices[0] = v0;
    vertices[1] = v1;
    vertices[2] = v2;
    return vertices;
}

std::vector<glm::vec3> Triangle::getColors() const
{
    std::vector<glm::vec3> colors(3);
    colors[0] = c0;
    colors[1] = c1;
    colors[2] = c2;
    return colors;
}
