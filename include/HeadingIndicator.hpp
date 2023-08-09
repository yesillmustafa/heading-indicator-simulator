#ifndef HEADINGINDICATOR_HPP
#define HEADINGINDICATOR_HPP

#include "shaderProgram.hpp"
#include <glm/glm.hpp>

class VertexArrayObject;
class HIManager;

class HeadingIndicator
{
    
public:

    glm::vec3 m_Color;

    void draw();
    void drawLine();

private:
    VertexArrayObject* m_Vao;
    unsigned int m_IndexCount;
    unsigned int m_VertexCount;

    friend HIManager;
};

#endif

