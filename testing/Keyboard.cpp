#include "Keyboard.h"
#include <memory.h>

Keyboard::Keyboard() {
    memset(keyPress,0,sizeof(keyPress));
}

void Keyboard::press(unsigned char key) {
    keyPress[key] = true;
}

void Keyboard::release(unsigned char key) {
    keyPress[key] = false;
}

bool Keyboard::isPressed(unsigned char key) {
    return keyPress[key];
}
