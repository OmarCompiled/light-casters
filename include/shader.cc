#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "shader.h"

gl::glShader::glShader(const char* vertexShaderPath, const char* fragmentShaderPath) {
	std::string vertexShaderSource;
	std::string fragmentShaderSource;
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;
			
	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{	
		std::stringstream vertexShaderStream;
		std::stringstream fragmentShaderStream;

		// I thought about checking file-path being NULL
		// but vertex shaders are not optional in modern 
		// OpenGL
				
		vertexShaderFile.open(vertexShaderPath);
		fragmentShaderFile.open(fragmentShaderPath);

		vertexShaderStream   << vertexShaderFile.rdbuf();
		fragmentShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertexShaderSource   = vertexShaderStream.str();
		fragmentShaderSource = fragmentShaderStream.str();
	}
	catch(std::ifstream::failure error)
	{
		std::fprintf(stderr, "[ERROR] Failed to read shader files\n");
		std::fprintf(stderr, "%s\n", error.what());
	}

	const char* vertexShaderSource_GL   = vertexShaderSource.c_str();
	const char* fragmentShaderSource_GL = fragmentShaderSource.c_str();

	GLuint vertexShader_GL;
	GLuint fragmentShader_GL;
	GLint  success;
	GLchar infoLog[512];

	vertexShader_GL   = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader_GL = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader_GL, 1, &vertexShaderSource_GL, NULL);
	glShaderSource(fragmentShader_GL, 1, &fragmentShaderSource_GL, NULL);

	glCompileShader(vertexShader_GL);
	glGetShaderiv(vertexShader_GL, GL_COMPILE_STATUS, &success);
	if(!success) {
		glGetShaderInfoLog(vertexShader_GL, 512, NULL, infoLog);
		std::fprintf(stderr, "[ERROR] vertex shader: compilation failed\n %s\n", infoLog);
	}

	glCompileShader(fragmentShader_GL);
	glGetShaderiv(fragmentShader_GL, GL_COMPILE_STATUS, &success);
	if(!success) {
		glGetShaderInfoLog(fragmentShader_GL, 512, NULL, infoLog);
		std::fprintf(stderr, "[ERROR] fragment shader: compilation failed\n %s\n", infoLog);
	}

	m_Id = glCreateProgram();

	glAttachShader(m_Id, vertexShader_GL);
	glAttachShader(m_Id, fragmentShader_GL);
	glLinkProgram(m_Id);
	glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(m_Id, 512, NULL, infoLog);
		std::fprintf(stderr, "[ERROR] shader program: linking failed\n %s\n", infoLog);
	}

	glDeleteShader(vertexShader_GL);
	glDeleteShader(fragmentShader_GL);
}

gl::glShader::~glShader() {
	glDeleteProgram(m_Id);
	std::fprintf(stderr, "[LOG] shader program: deletion successful [%s]\n", m_Id);
}

	
void
gl::glShader::use(bool use) {
	use ? glUseProgram(m_Id) : glUseProgram(0);
}


void
gl::glShader::setFloat(const char* uniform, const float value) {
	glUniform1f(glGetUniformLocation(m_Id, uniform), value);
}

void
gl::glShader::setVec2(const char* uniform, const float* values) {
	glUniform2fv(glGetUniformLocation(m_Id, uniform), 1, values);
}

void
gl::glShader::setVec3(const char* uniform, const float* values) {
	glUniform3fv(glGetUniformLocation(m_Id, uniform), 1, values);
}
		
void
gl::glShader::setInt(const char* uniform, int value) {
	glUniform1i(glGetUniformLocation(m_Id, uniform), value);
}

void
gl::glShader::setVec2i(const char* uniform, int* values) {
	glUniform2iv(glGetUniformLocation(m_Id, uniform), 1, values);
}

		
void
gl::glShader::setMat4(const char* uniform, float* values) {
	glUniformMatrix4fv(glGetUniformLocation(m_Id, uniform), 1, GL_FALSE, values);
}

