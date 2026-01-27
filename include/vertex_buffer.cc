#include "vertex_buffer.h"

gl::glVertexBuffer::glVertexBuffer(const void* data, GLuint size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

gl::glVertexBuffer::~glVertexBuffer() {
	glDeleteBuffers(1, &ID);
}

void gl::glVertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void gl::glVertexBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0); // 0 tells OpenGL to not bind anything essentially.
}
