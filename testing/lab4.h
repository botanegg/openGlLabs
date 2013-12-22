#ifndef _lab4_H
#define _lab4_H

#include "IDrawtickable.h"

class lab4: public IDrawtickable {
public:
    lab4();

    float func(float x);

    virtual ~lab4();

    virtual void draw();
    virtual void tick();
};

#endif /* _lab4 */
