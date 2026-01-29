#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "../include/glfw_init.h"
#include "../include/gl_init.h"

int
main() {
	GLFWwindow* window = glfw::InitGLFWContext(800, 800, "Light Casters", true);
	gl::InitGLContext(glfw::resolution[0], glfw::resolution[1]);



	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	
	glfwTerminate();
	
	return 0;
}
