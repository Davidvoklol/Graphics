#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GlBuffer.h"
#include "GlVertexArray.h"

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, ib.count, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
