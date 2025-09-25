#include "./GlVertexArray.h"

GlVertexArray::GlVertexArray() {
	glGenVertexArrays(1, &id);
	Bind();
}

GlVertexArray::~GlVertexArray() {
	glDeleteVertexArrays(1, &id);
}

void GlVertexArray::Bind() const {
	glBindVertexArray(id);
}

void GlVertexArray::UnBind() const {
	glBindVertexArray(0);
}

void GlVertexArray::SetLayout(const unsigned int index, const unsigned int size, const unsigned int type,
		unsigned char normalized, const unsigned int stride, const void* pointer) const {
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}
