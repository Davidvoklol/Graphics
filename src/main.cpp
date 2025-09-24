#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
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

	unsigned int vb, ib, va;
	glad_glGenBuffers(1, &vb);
	glad_glGenBuffers(1, &ib);
	glad_glGenVertexArrays(1, &va);

	glad_glBindVertexArray(va);
	glad_glBindBuffer(GL_ARRAY_BUFFER, vb);
	glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);

	glad_glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW);
	glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glad_glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glad_glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
