#ifndef _APP_H
#define _APP_H
#include "Keyboard.h"
#include "Mouse.h"
#include "Camera.h"

class App {
public:
    Keyboard kb;
    Mouse m;
    Camera cam;

    unsigned _tick;

    App();

    void tick();
};


#endif /* _APP_H */
