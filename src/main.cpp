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
		-0.5, -0.5,
		 0.5, -0.5,
		-0.5,  0.5,
		 0.5,  0.5
	};

	unsigned int vb;
	glad_glGenBuffers(1, &vb);
	glad_glBindBuffer(GL_ARRAY_BUFFER, vb);
	glad_glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW);

	glad_glEnableVertexAttribArray(0);
	glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	
	// unsigned int indices[] = {
	// 	0, 1, 2,
	// 	2, 3, 0
	// };
	//
	// unsigned int ib;
	// glad_glGenBuffers(1, &ib);
	// glad_glBindBuffer(GL_ARRAY_BUFFER, ib);
	// glad_glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glad_glBindBuffer(GL_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glad_glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
