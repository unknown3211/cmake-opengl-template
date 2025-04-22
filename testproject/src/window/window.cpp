#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "input/input.h"

void LoadWindow(int width, int height)
{
	glfwInit();

	// Specifying Major & Minor Versions + Profiles //
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Template", NULL, NULL); // Creating Window
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, width, height);

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window); // Handles Inputs

		// Render Shit //
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Color Of Screen Background
		glClear(GL_COLOR_BUFFER_BIT); // Makes It Show Color

		glfwPollEvents(); // Checks If Any Events Are Triggered
		glfwSwapBuffers(window); // Swaps Color Buffer
	}
	glfwDestroyWindow(window); // Destroys Window
	glfwTerminate(); // Terminates Application
}