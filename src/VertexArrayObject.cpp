#include "VertexArrayObject.hpp"
#include "VertexTypes.hpp"
#include <glad/glad.h>

VertexArrayObject::VertexArrayObject()
{
    m_VaoId = 0;
    m_VboId = 0;
    m_VibId = 0;
}
VertexArrayObject::~VertexArrayObject()
{
    if(m_VaoId)
    {
        glDeleteBuffers(1,&m_VboId);
    }
    if(m_VaoId)
    {
        glDeleteBuffers(1,&m_VibId);
    }
    if(m_VaoId)
    {
        glDeleteVertexArrays(1,&m_VaoId);
    }
}
void VertexArrayObject::build(const Vertex3TexList& vertices,const IndexList& indices)
{
    //vertex array object oluşturuluyor
    glGenVertexArrays(1, &m_VaoId); 
    //vertex array object aktif edildi.
    glBindVertexArray(m_VaoId);

    //vertex buffer object oluşuruluyor
    glGenBuffers(1,&m_VboId);
    //vertex buffer nesnesi aktif edildi.
    glBindBuffer(GL_ARRAY_BUFFER,m_VboId);
    //vertex buffer'a nokta bilgileri yollanıyor
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex3Tex)*vertices.size(),&vertices[0],GL_STATIC_DRAW);

    //index buffer object oluşturuluyor
    glGenBuffers(1,&m_VibId);
    //index buffer nesnesi aktif edildi.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_VibId);
    //index buffer'a nokta bilgileri yollanıyor
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*indices.size(),&indices[0],GL_STATIC_DRAW);
    
    //gönderilen vertex'e ait özellikler etiketleniyor
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    //özellik  etiket i aktif ediliyor.
    glEnableVertexAttribArray(0); 
     //texture'a ait özellikler etiketleniyor
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    //texture özellik  etiket i aktif ediliyor.
    glEnableVertexAttribArray(1); 

    m_AttribList.push_back(0);
    m_AttribList.push_back(1);


}
void VertexArrayObject::build(const Vertex3List& vertices,const IndexList& indices)
{
     //vertex array object oluşturuluyor
    glGenVertexArrays(1, &m_VaoId); 
    //vertex array object aktif edildi.
    glBindVertexArray(m_VaoId);

    //vertex buffer object oluşuruluyor
    glGenBuffers(1,&m_VboId);
    //vertex buffer nesnesi aktif edildi.
    glBindBuffer(GL_ARRAY_BUFFER,m_VboId);
    //vertex buffer'a nokta bilgileri yollanıyor
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex3)*vertices.size(),&vertices[0],GL_STATIC_DRAW);

    //index buffer object oluşturuluyor
    glGenBuffers(1,&m_VibId);
    //index buffer nesnesi aktif edildi.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_VibId);
    //index buffer'a nokta bilgileri yollanıyor
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*indices.size(),&indices[0],GL_STATIC_DRAW);
    
    //gönderilen vertex'e ait özellikler etiketleniyor
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //özellik  etiket i aktif ediliyor.
    glEnableVertexAttribArray(0); 

    m_AttribList.push_back(0);


}

void VertexArrayObject::activate()
{
    //çizimde kullanılacak olan Vertex array object aktif ediliyor
    glBindVertexArray(m_VaoId);

    for(auto next:m_AttribList)
    {
        glEnableVertexAttribArray(next);
    }
}

void VertexArrayObject::deactivate()
{
    for(auto next:m_AttribList)
    {
        glDisableVertexAttribArray(next);
    }
    glBindVertexArray(0);
    
}