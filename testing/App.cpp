#include "App.h"
#include "MyObject.h"
#include "lab4.h"
#include "lab5.h"
#include "Texture.h"

#include <stdlib.h>
#include <iostream>

App::App(): kb(), m(), cam(), DT(), _tick(0) {}

App::~App() {
    for(unsigned i = 0; i < DT.size(); ++i) delete DT[i];
}

void App::tick() {
    _tick++;

    for(unsigned i = 0; i < DT.size(); ++i) DT[i]->tick();

    cam.setFocus(kb.isPressed('p'));

    if(kb.isPressed('w')) cam.moveForward();

    if(kb.isPressed('a')) cam.moveLeft();

    if(kb.isPressed('s')) cam.moveBack();

    if(kb.isPressed('d')) cam.moveRight();

    if(kb.isPressed('u')) cam.moveUp();

    if(kb.isPressed('j')) cam.moveDown();

    cam.addAngleXZ((short int)(m.dx << 6));
    cam.addAngleH((short int)(m.dy << 6));

    m.tick();
}

void App::draw() {
    for(unsigned i = 0; i < DT.size(); ++i) DT[i] -> draw();
}

void App::init() {
    srand(100000007);

    for(int i = 0; i < 10 ; i++) {
        IDrawtickable *a = new MyObject(rand() % 20 + 10, rand() % 20 + 10, rand() % 20 + 10);
        DT.push_back(a);
    }

    DT.push_back(new lab4());
    DT.push_back(new lab5());

    std::cout << Texture::count << std::endl;
}
