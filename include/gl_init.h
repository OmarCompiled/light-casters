#pragma once

#include <GL/glew.h>
#include <cstdio>
#include <cstdlib>

namespace gl
{

void
InitGLContext(int width, int height) {
	if(glewInit() != GLEW_OK) {
		std::fprintf(stderr, "ERROR: Failed to initialize glew\n");
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}

}
