#include "HeadingIndicator.hpp"
#include "VertexArrayObject.hpp"
#include <glad/glad.h>

void HeadingIndicator::draw()
{
    m_Vao->activate();

    glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);

    m_Vao->deactivate();
}
void HeadingIndicator::drawLine()
{
    m_Vao->activate();

    glDrawElements(GL_LINE_LOOP, m_IndexCount, GL_UNSIGNED_INT, 0);

    m_Vao->deactivate();
}

