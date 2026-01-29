#pragma once

#include <GL/glew.h>
#include <vector>

namespace gl
{

struct glVertexBufferLayoutElement
{
	GLuint 	  type;
	GLuint 	  count;
	GLboolean normalized;

	static unsigned int GetTypeSize(GLuint type) {
		switch(type) {
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT: return sizeof(GLuint);
		case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
		};
	}
};

class glVertexBufferLayout
{
private:
	std::vector<glVertexBufferLayoutElement> m_Elements;
	GLuint m_Stride;
public:
	VertexBufferLayout() : m_Stride(0) {}

	template<typename T>
	void Push(unsigned int count) {}

	template<>
	void Push<float>(GLuint count) {
		m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
		m_Stride += count * sizeof(GLfloat);
	}

	template<>
	void Push<GLuint>(GLuint count) {
		m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
		m_Stride += count * sizeof(GLuint);
	}

	inline const std::vector<glVertexBufferLayoutElement>& GetElements() const {return m_Elements;}
	inline const GLuint GetStride() const {return m_Stride;} 	
};

}
