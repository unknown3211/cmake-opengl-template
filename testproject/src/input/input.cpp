#include <iostream>
#include<GLFW/glfw3.h>

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		std::cout << "J Key Pressed" << std::endl;
}