#include "./vertex_array.h"

glVertexArray::VertexArray() {
	glGenVertexArrays(1, &m_Id);
}

glVertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_Id);
}

void glVertexArray::Bind() const {
	glBindVertexArray(m_Id);
}

void glVertexArray::Unbind() const {
	glBindVertexArray(0);
}

void glVertexArray::AddBuffer(const glVertexBuffer& VBO, const glVertexBufferLayout& layout) {
	const auto& elements = layout.GetElements();

	Bind();
	VBO.bind();

	unsigned int offset = 0;
	for(int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
		offset += element.count * glVertexBufferLayoutElement::GetTypeSize(element.type);
	}
}
