#include "./Shader.h"

Shader::Shader(const char* path) {
	program_id = ParseShader(path);
}

Shader::~Shader() {
	glDeleteProgram(program_id);
}

unsigned int Shader::ParseShader(const char* path) const {
	Source sources;

	std::ifstream shader_sources(path);
	if (!shader_sources.is_open()) {
		std::cerr << "Failed to open file\n";
		exit(1);
	}

	int TYPE = -1;

	std::string line;
	while (std::getline(shader_sources, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) TYPE = 0;
			else if(line.find("fragment") != std::string::npos) TYPE = 1;
		} else {
			if (TYPE == 0) sources.vertex += line + "\n";
			else if (TYPE == 1) sources.fragment += line + "\n";
		}
	}

	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

	char* vertex_src = &sources.vertex[0];
	char* fragment_src = &sources.fragment[0];

	glShaderSource(vs, 1, &vertex_src, nullptr);
	glShaderSource(fs, 1, &fragment_src, nullptr);

	glCompileShader(vs);
	glCompileShader(fs);

	unsigned int program = glCreateProgram();

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

void Shader::Bind() const {
	glUseProgram(program_id);
};

void Shader::UnBind() const {
	glUseProgram(0);
};
