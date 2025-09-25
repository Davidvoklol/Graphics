#pragma once
#include <glad/glad.h>

class GlVertexArray {
	public:
		unsigned int id;

		GlVertexArray();
		~GlVertexArray();

		void Bind() const;
		void UnBind() const;

		void SetLayout(const unsigned int index, const unsigned int size, const unsigned int type,
				unsigned char normalized, const unsigned int stride, const void* pointer) const;
};
