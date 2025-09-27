#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

struct Source {
	std::string vertex;
	std::string fragment;
};

class Shader {
	private:
		unsigned int ParseShader(const char* path) const;
	public:
		unsigned int program_id;

		Shader(const char* path);
		~Shader();

		void Bind() const;
		void UnBind() const;
};
