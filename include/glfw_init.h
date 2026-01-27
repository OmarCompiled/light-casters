#pragma once

#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib>

namespace glfw
{

int resolution[2] = {0, 0};

GLFWwindow*
InitGLFWContext(int width = 800, int height = 800, const char* title = NULL, bool fullscreen = false, GLFWwindow* share = NULL) {
	GLFWwindow* window = NULL;
	GLFWmonitor* primary_monitor = NULL;
	resolution[0] = width;
	resolution[1] = height;

	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if(!glfwInit()) {
		std::fprintf(stderr, "ERROR: Failed to create GLFW window: glfwInit()\n");
		std::exit(EXIT_FAILURE);
	}

	if(fullscreen) {
		primary_monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(primary_monitor);
		resolution[0] = mode->width;
		resolution[1] = mode->height;
	}
	
	window = glfwCreateWindow(resolution[0], resolution[1], title, primary_monitor, share);

	if(!window) {
		std::fprintf(stderr, "ERROR: Failed to create GLFW window\n");
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	return window;
}

}
