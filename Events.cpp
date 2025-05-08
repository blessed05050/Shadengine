#include <string.h>
#include <GLFW/glfw3.h>
#include "Events.h"

bool* Events::keys;
uint* Events::frames;
uint Events::current = 0;
float Events::delta_x = 0.0f;
float Events::delta_y = 0.0f;
float Events::x = 0.0f;
float Events::y = 0.0f;
bool Events::cursor_lock = false;
bool Events::cursor_start = false;

#define MOUSE_BUTTONS 1024

void cursor_position_callback(GLFWwindow* window, double posX, double posY) {
	if (Events::cursor_lock) {
		Events::delta_x += posX - Events::x;
		Events::delta_y += posY - Events::y;
	}
	else {
		Events::cursor_start = true;
	}
	Events::x = posX;
	Events::y = posY;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::keys[MOUSE_BUTTONS + button] = true;
		Events::frames[MOUSE_BUTTONS + button] = Events::current;
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::keys[key] = true;
		Events::frames[key] = Events::current;
	}
	else if (action == GLFW_RELEASE) {
		Events::keys[key] = false;
		Events::frames[key] = Events::current;
	}
}

int Events::init() {
	GLFWwindow* window = Window::window;
	keys = new bool[1032];
	frames = new uint[1032];

	memset(keys, false, 1032 * sizeof(bool));
	memset(frames, false, 1032 * sizeof(uint));

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	return 0;
}

void Events::pull_events() {
	current++;
	delta_x = 0.0f;
	delta_y = 0.0f;
	glfwPollEvents();
}

bool Events::pressed(int keycode) {
	if (keycode < 0 || keycode >= MOUSE_BUTTONS) {
		return false;
	}
	return keys[keycode];
}

bool Events::just_pressed(int keycode) {
	if (keycode < 0 || keycode >= MOUSE_BUTTONS) {
		return false;
	}
	return keys[keycode] && frames[keycode] == current;
}

bool Events::clicked(int button) {
	return keys[MOUSE_BUTTONS+button];
}

bool Events::just_clicked(int button) {
	return keys[MOUSE_BUTTONS + button] && frames[MOUSE_BUTTONS+button] == current;
}