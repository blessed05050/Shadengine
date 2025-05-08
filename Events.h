#ifndef WINDOW_EVENTS_H_
#define WINDOW_EVENTS_H_

#include "Window.h"

typedef unsigned int uint;

class Events {
public:
	static bool* keys;
	static uint* frames;
	static uint current;
	static float delta_x;
	static float delta_y;
	static float x;
	static float y;
	static bool cursor_lock;
	static bool cursor_start;

	static int init();

	static void pull_events();

	static bool pressed(int keycode);
	static bool just_pressed(int keycode);

	static bool clicked(int button);
	static bool just_clicked(int button);
};

#endif // WINDOW_EVENTS_H_