#include "./GlBuffer.h"

GlBuffer::GlBuffer(const unsigned int target, const unsigned int size, const void* data,
				const unsigned int usage, const unsigned int count) {
	glGenBuffers(1, &id);

	this->target = target;
	this->count = count;
	Bind();

	glBufferData(target, size, data, usage);
}

GlBuffer::~GlBuffer() {
	glDeleteBuffers(1, &id);
}

void GlBuffer::Bind() const {
	glBindBuffer(target, id);
}

void GlBuffer::UnBind() const {
	glBindBuffer(0, 0);
}
