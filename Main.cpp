#include <iostream>
using namespace std;

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Events.h"

int width = 1280;
int height = 720;

int main() {
	Window::init(width, height, "Shadengine");
	Events::init();

	glClearColor(0, 0, 0, 1);

	// Основной цикл
	while (!Window::should_close()) {
		Events::pull_events();
		if (Events::just_pressed(GLFW_KEY_ESCAPE)) {
			Window::set_should_close(true);
		}

		if (Events::just_clicked(GLFW_MOUSE_BUTTON_1)) {
			glClearColor(1, 0, 0, 1);
		}

		glClear(GL_COLOR_BUFFER_BIT);

		Window::swap_buffers();
	}

	Window::terminate();
	return 0;
}