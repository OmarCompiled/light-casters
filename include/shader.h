#pragma once

#include <GL/glew.h>

namespace gl
{

class glShader
{
public:
	GLuint m_Id;
public:
	glShader(const char* vertexShaderPath, const char* fragmentShaderPath, std::string name = nullptr);
	~glShader();

	void use(bool use = true);

	void setFloat(const char* uniform, const float value);
	void setVec2(const char* uniform, const float* values);
	void setVec3(const char* uniform, const float* values);

	void setInt(const char* uniform, int value);
	void setVec2i(const char* uniform, int* values);

	void setMat4(const char* uniform, float* values);
};

}
