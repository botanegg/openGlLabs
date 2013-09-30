#include "App.h"
#include "MyObject.h"

App::App() {
    _tick = 0;
    MyObject *a = new MyObject(0, 5, 0);
    DT.push_back(a);
}

App::~App() {
    for(unsigned i = 0; i < DT.size(); ++i) delete DT[i];
}

void App::tick() {
    _tick++;

    for(unsigned i = 0; i < DT.size(); ++i) DT[i]->tick();

    cam.setFocus(kb.isPressed('p'));

    if (kb.isPressed('w')) cam.moveForward();
    if (kb.isPressed('a')) cam.moveLeft();
    if (kb.isPressed('s')) cam.moveBack();
    if (kb.isPressed('d')) cam.moveRight();
    if (kb.isPressed('u')) cam.moveUp();
    if (kb.isPressed('j')) cam.moveDown();

    cam.addAngleXZ(m.dx * 64);
    cam.addAngleH(m.dy * 64);

    m.release();
}

void App::draw() {
    for(unsigned i = 0; i < DT.size(); ++i) DT[i] -> draw();
}
