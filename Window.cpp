#include <iostream>
using namespace std;

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"

GLFWwindow* Window::window;

int Window::init(int width, int height, const char* title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (window == nullptr) {
	cout:cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
		return -1;
	}

	glViewport(0, 0, width, height);
	return 0;
}

void Window::terminate() {
	glfwTerminate();
}

bool Window::should_close() {
	return glfwWindowShouldClose(window);
}

void Window::set_should_close(bool flag) {
	glfwSetWindowShouldClose(window, flag);
}


void Window::swap_buffers() {
	glfwSwapBuffers(window);
}