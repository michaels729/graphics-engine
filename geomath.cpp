#include "geomath.h"

/**
    Returns the area of the parallelogram formed by the input vertices. Area
    will be determined by the magnitudes of v1 - v0 and v2 - v0 and the
    counterclockwise angle (v1 - v0 to v2 - v0) between those two difference
    vectors.

    @param v0 first vertex
    @param v1 second vertex
    @param v2 third vertex

    @return the area of the parallelogram formed by the given vertices
*/
float areaParallelogram2D(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2)
{
    // z-position unused here, since triangles are in 2D raster space and depth
    // is irrelevant
    return (v2.y - v0.y) * (v1.x - v0.x) - (v2.x - v0.x) * (v1.y - v0.y);
}

/**
    Returns the area of the triangle formed by the input vertices. Area
    will be determined by the magnitudes of v1 - v0 and v2 - v0 and the
    counterclockwise angle (v1 - v0 to v2 - v0) between those two difference
    vectors.

    @param v0 first vertex
    @param v1 second vertex
    @param v2 third vertex

    @return the area of the triangle formed by the given vertices
*/
float areaTriangle2D(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2)
{
    return areaParallelogram2D(v0, v1, v2) / 2.0;
}

/**
    Determines whether a target point p is on the line or to the left of the
    line in which the vector v1 - v0 exists.

    @param v0 first vertex
    @param v1 second vertex
    @param p the target point

    @return true if the target point p is to the left of the vector v1 - v0,
            else false
*/
bool edgeFunction(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &p)
{
    return areaParallelogram2D(v0, v1, p) >= 0.0f;
}
