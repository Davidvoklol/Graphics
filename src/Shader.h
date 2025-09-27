#pragma once
#include <glad/glad.h>

class Shader {
	private:
		unsigned int ParseSource(const char* path) const;
		unsigned int CompileShader() const;
	public:
		unsigned int program_id;

		Shader();
		~Shader();

		void Bind() const;
		void UnBind() const
};
