#ifndef _lab5_H
#define _lab5_H

#include "IDrawtickable.h"

class lab5: public IDrawtickable {
public:
    lab5();

    virtual ~lab5();

    virtual void draw();
    virtual void tick();
};

#endif /* _lab5 */
