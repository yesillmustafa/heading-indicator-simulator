#ifndef VertexArrayObject_hpp
#define VertexArrayObject_hpp

#include "VertexTypes.hpp"

class VertexArrayObject
{
    private:

    unsigned int m_VaoId;
    unsigned int m_VboId;
    unsigned int m_VibId;
    std::vector<unsigned int> m_AttribList;

    public:

    VertexArrayObject();
    ~VertexArrayObject();
    
    void build(const Vertex3TexList& vertices,const IndexList& indices);
    void build(const Vertex3List& vertices, const IndexList& indices);
    void activate();
    void deactivate();

   

};


#endif