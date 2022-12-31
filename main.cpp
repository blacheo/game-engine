#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "mainConfig.h"

// Error Callback for GLFW 
void error_callback(int, const char *);
// Key Input Callback for GLFW Windows
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main(void) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		error_callback(1, "Error: Initialization Failed");
		glfwTerminate();
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(1360, 768, "Wow, it's window", NULL, NULL);
	if (!window)
	{
		error_callback(1, "Error: Window or Context Creation Failed");
		glfwTerminate();
		exit(2);
	}
	// Set Current OpenGL context to use OpenGL API
	glfwMakeContextCurrent(window);

	// Set Key Callback per window
	glfwSetKeyCallback(window, key_callback);

	// While window is open
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);

		glfwPollEvents();
		
	}

	// Terminate GLFW before application exits
	glfwTerminate();
	return 0;
}

void error_callback(int error, const char * description)
{
	std::cerr << description << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}