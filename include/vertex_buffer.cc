#include "vertex_buffer.h"

gl::glVertexBuffer::glVertexBuffer(const void* data, GLuint size) {
	glGenBuffers(1, &m_Id);
	glBindBuffer(GL_ARRAY_BUFFER, m_Id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

gl::glVertexBuffer::~glVertexBuffer() {
	glDeleteBuffers(1, &m_Id);
}

void gl::glVertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void gl::glVertexBuffer::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0); // 0 tells OpenGL to not bind anything essentially.
}
