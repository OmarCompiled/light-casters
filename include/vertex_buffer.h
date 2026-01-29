#pragma once

#include <GL/glew.h>

namespace gl
{

class glVertexBuffer
{
private:
	GLuint m_Id;

public:
	glVertexBuffer(const void* data, GLuint size);
	~glVertexBuffer();

	void Bind() const;
	void Unbind() const;
};

}
