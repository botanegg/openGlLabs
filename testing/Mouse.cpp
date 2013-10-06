#include "Mouse.h"

Mouse::Mouse(): x(0), y(0), dx(0), dy(0) {}

void Mouse::press(int _x, int _y) {
    x = _x;
    y = _y;
}

void Mouse::motion(int _x, int _y) {
    dx = x - _x;
    dy = y - _y;
}

void Mouse::tick() {
    x -= dx;
    y -= dy;
    dx = 0;
    dy = 0;
}
