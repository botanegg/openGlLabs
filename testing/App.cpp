#include "App.h"
#include <cmath>

#include <iostream>

App::App() {
    _tick = 0;
}

void App::tick() {
    _tick++;

    if (kb.isPressed('w')) cam.moveForward();
    if (kb.isPressed('a')) cam.moveLeft();
    if (kb.isPressed('s')) cam.moveBack();
    if (kb.isPressed('d')) cam.moveRight();
    if (kb.isPressed('u')) cam.moveUp();
    if (kb.isPressed('j')) cam.moveDown();

    cam.addAngleXZ(m.dx*64);
    cam.addAngleH(m.dy*64);

    std::cout << cam.angleXZ << "   " << cam.getAngleXZ() << std::endl;
    std::cout << cam.angleH <<   "   " << cam.getAngleH() << std::endl;

    m.release();
}

