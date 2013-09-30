#include "Mouse.h"

Mouse::Mouse() {
    x = y = dx = dy = 0;
}

void Mouse::press(int _x, int _y) {
    x = _x;
    y = _y;
}

void Mouse::release() {
    dx = 0;
    dy = 0;
}

void Mouse::motion(int _x, int _y) {
    dx = x - _x;
    dy = y - _y;
    x = _x;
    y = _y;
}
