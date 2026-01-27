#pragma once

#include <GL/glew.h>

namespace gl
{

class glElementBuffer
{
	private:
		GLuint ID;
	
	public:
		glElementBuffer(const GLuint* data, GLuint count);
		~glElementBuffer();

		void bind();
		void unbind();
};

}
