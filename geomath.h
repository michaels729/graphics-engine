#ifndef GEOMATH_H
#define GEOMATH_H

#include <glm/glm.hpp>

float areaParallelogram2D(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2);
float areaTriangle2D(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2);
float edgeFunction(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2);

#endif // GEOMATH_H
