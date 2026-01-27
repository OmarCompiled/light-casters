#include "element_buffer.h"

glElementBuffer::glElementBuffer(const GLuint* data, GLuint count) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

glElementBuffer::~glElementBuffer() {
	glDeleteBuffers(1, &ID);
}

void glElementBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void glElementBuffer::unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
