#ifndef _MYOBJECT_H
#define _MYOBJECT_H

#include "IDrawtickable.h"
#include "Texture.h"

class MyObject: public IDrawtickable {
private:
    Texture tex;
    float x;
    float y;
    float z;
    float angle;
public:
    MyObject();
    MyObject(float _x, float _y, float _z);

    virtual ~MyObject();

    virtual void draw();
    virtual void tick();
};

#endif /* _MYOBJECT */
