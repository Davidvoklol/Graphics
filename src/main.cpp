#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GlBuffer.h"
#include "GlVertexArray.h"
#include <fstream>
#include <string>

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 720, "Opengl Prject", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	int version = gladLoadGL();
    if (version == 0) {
		std::cout << "Failed to initialize OpenGL context\n";
        return -1;
    }

	std::cout << glGetString(GL_VERSION) << std::endl;


	float positions[] = {
		-0.5f, -0.5f,
		-0.5f,  0.5f,
		 0.5f,  0.5f,
		 0.5f, -0.5f
	};
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GlVertexArray va{};
	GlBuffer vb(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW, 8);
	GlBuffer ib(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW, 6);
	va.SetLayout(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertex_buffer;
	std::string fragment_buffer;

	const char* shader_path = "res/shaders/Basic.glsl";
	std::ifstream shader_sources(shader_path);
	if (!shader_sources.is_open()) {
		std::cerr << "Failed to open file\n";
		return 1;
	}

	int TYPE = -1;

	std::string line;
    while (std::getline(shader_sources, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) TYPE = 0;
			else if(line.find("fragment") != std::string::npos) TYPE = 1;
		} else {
			if (TYPE == 0) vertex_buffer += line + "\n";
			if (TYPE == 1) fragment_buffer += line + "\n";
		}
    }

	shader_sources.close();

	char* vs_source = &vertex_buffer[0];
	char* fs_source = &fragment_buffer[0];
	
	glad_glShaderSource(vs, 1, &vs_source, nullptr);
	glad_glShaderSource(fs, 1, &fs_source, nullptr);

	glCompileShader(vs);
	glCompileShader(fs);

	unsigned int program = glCreateProgram();

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);

	glUseProgram(program);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, ib.count, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
