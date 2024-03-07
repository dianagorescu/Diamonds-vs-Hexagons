#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length/2, length/2, 0), color),
        VertexFormat(corner + glm::vec3(-length/2, -length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length/2, -length/2, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length/2, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}
Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float height, float width,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-width /2, height/2, 0), color),
        VertexFormat(corner + glm::vec3(-width /2, -height/2, 0), color),
        VertexFormat(corner + glm::vec3(width /2, -height/2, 0), color),
        VertexFormat(corner + glm::vec3(width /2, height/2, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}
Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center + glm::vec3(0, length, 0), color),
        VertexFormat(center + glm::vec3(-length/2, 0, 0), color),
        VertexFormat(center + glm::vec3(0, -length, 0), color),
        VertexFormat(center + glm::vec3(length / 2, 0, 0), color),

        VertexFormat(center + glm::vec3(0, -length / 6, 0), color),
        VertexFormat(center + glm::vec3(length, -length / 6, 0), color),
        VertexFormat(center + glm::vec3(length, length / 6, 0), color),
        VertexFormat(center + glm::vec3(0, length / 6, 0), color)

    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 
        2, 3, 0, 
        4, 5, 6, 
        6, 7, 4};

    if (!fill) {
        romb->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    romb->InitFromData(vertices, indices);
    return romb;
}
Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, length, 0), color),
        VertexFormat(corner + glm::vec3(-length, length / 2, 0), color),
        VertexFormat(corner + glm::vec3(0, 0, 0), color),

        VertexFormat(corner + glm::vec3(-length, -length / 2, 0), color),
        VertexFormat(corner + glm::vec3(0, -length, 0), color),

        VertexFormat(corner + glm::vec3(length, -length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length, length / 2, 0), color),

    };

    Mesh* hexagon = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2,
        1, 3, 2,
        3, 4, 2,
        4, 5, 2,
        5, 6, 2,
        6, 0, 2
    };

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}
Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(length/2 -2, length *1.732050f/2, 0), color),
        VertexFormat(corner + glm::vec3(-length/2 +2, length * 1.732050f/2, 0), color),
        VertexFormat(corner + glm::vec3(0, 0, 0), color),
        VertexFormat(corner + glm::vec3(-length+10, 0, 0), color),

        VertexFormat(corner + glm::vec3(0, -length+20, 0), color),
        VertexFormat(corner + glm::vec3(length-10, 0, 0), color),

        VertexFormat(corner + glm::vec3(0, length * 1.732050f , 0), color),
        VertexFormat(corner + glm::vec3(-(length * 1.732050f / 4+length), length * 1.732050f / 2 -5, 0), color),
        VertexFormat(corner + glm::vec3((length * 1.732050f / 4 + length), length * 1.732050f / 2 -5, 0), color),
        VertexFormat(corner + glm::vec3(-(length+2), -length * 1.42f+15, 0), color),
        VertexFormat(corner + glm::vec3(length+2, -length * 1.42f+15, 0), color)

    };

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2,
        1,3,2,
        3,4,2,
        4,5,2,
        5,0,2,


        6,1,0,
        7,3,1,
        8,0,5,
        9,4,3,
        10,5,4
    };

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    star->InitFromData(vertices, indices);
    return star;
}
Mesh* object2D::CreateHeart(
    const std::string& name,
    glm::vec3 center,
    float size,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        // Left bottom curve
        VertexFormat(center + glm::vec3(0, 0, 0), color),
        VertexFormat(center + glm::vec3(-2 * size, 2 * size, 0), color),
        VertexFormat(center + glm::vec3(-4 * size, 1 * size, 0), color),
        VertexFormat(center + glm::vec3(-4 * size, -1 * size, 0), color),

        VertexFormat(center + glm::vec3(0, -5 * size, 0), color),

        VertexFormat(center + glm::vec3(4 * size, -1 * size, 0), color),
        VertexFormat(center + glm::vec3(4 * size, 1 * size, 0), color),
        VertexFormat(center + glm::vec3(2 * size, 2 * size, 0), color),

    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 
        0, 2, 3, 
        0, 3, 4, 
        0, 4, 5,
        0, 5, 6,
        0, 6, 7 };

    if (!fill) {
        heart->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 3 triangles. Add the remaining indices
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(4);
    }

    heart->InitFromData(vertices, indices);
    return heart;
}
