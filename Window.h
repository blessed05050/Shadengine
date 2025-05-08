#ifndef WINDOW_WINDOW_H_
#define WINDOW_WINDOW_H_

class GLFWwindow;

class Window {
public:
	static GLFWwindow* window;
	static int init(int width, int height, const char* title);
	static void terminate();

	static bool should_close();
	static void set_should_close(bool flag);

	static void swap_buffers();
};

#endif // WINDOW_WINDOW_H_