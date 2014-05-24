#include "Mouse.h"

Mouse::Mouse(): x(0), y(0), dx(0), dy(0) {
	for(int i = 0; i < 10; ++i ) {
		buttons[i] = 0;
	}
}

void Mouse::press(int button, int _x, int _y) {
	buttons[button] = 1;
	if (button == 0) {
		x = _x;
		y = _y;
	}
}

void Mouse::release(int button, int _x, int _y) {
	buttons[button] = 0;
	if (button == 0) {
		x = _x;
		y = _y;
	}
}

void Mouse::motion(int _x, int _y) {
	if (buttons[0] == 1) {
		dx = x - _x;
		dy = y - _y;
	}
}

void Mouse::tick() {
    x -= dx;
    y -= dy;
    dx = 0;
    dy = 0;
}
