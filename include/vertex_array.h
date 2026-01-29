#pragma once

#include "./vertex_buffer.h"
#include "./vertex_buffer_layout.h"

namespace gl
{

class glVertexArray
{
private:
	GLuint m_Id;
public:
	VertexArray();
	~VertexArray();	

	void Bind() const;
	void Unbind() const;
	void AddBuffer(const glVertexBuffer& VBO, const glVertexBufferLayout& layout);
};

}
