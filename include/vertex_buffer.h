#pragma once

#include <GL/glew.h>

namespace gl
{

class glVertexBuffer
{
	private:
		GLuint ID;

	public:
		glVertexBuffer(const void* data, GLuint size);
		~glVertexBuffer();

		void bind();
		void unbind();
};

}
