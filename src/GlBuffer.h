#pragma once
#include <glad/glad.h>

class GlBuffer {
	public:
		unsigned int id;
		unsigned int target;
		unsigned int count;

		GlBuffer(const unsigned int target, const unsigned int size, const void* data,
				const unsigned int usage, const unsigned int count);
		~GlBuffer();
		void Bind() const;
		void UnBind() const;
};
