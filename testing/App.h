#ifndef _APP_H
#define _APP_H
#include <vector>

#include "inc/inc.h"

#include "IDrawtickable.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Camera.h"

class App {
public:
    Keyboard kb;
    Mouse m;
    Camera cam;

    std::vector <IDrawtickable *> DT;

    unsigned _tick;

    App();
    ~App();

    void tick();
    void draw();
    void init();
};

#endif /* _APP_H */
