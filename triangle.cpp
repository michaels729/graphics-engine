#include "triangle.h"
#include "projector.h"


Triangle::Triangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2)
    : v0(v0), v1(v1), v2(v2)
{
}


Triangle::~Triangle()
{
}

std::vector<glm::vec3> Triangle::getVertices() const
{
    std::vector<glm::vec3> vertices(3);
    vertices.push_back(v0);
    vertices.push_back(v1);
    vertices.push_back(v2);
    return vertices;
}
