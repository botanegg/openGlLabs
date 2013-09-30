#ifndef _IDRAWTICKABLE_H
#define _IDRAWTICKABLE_H

class IDrawtickable {
public:
    IDrawtickable();
    virtual ~IDrawtickable();

    virtual void draw();
    virtual void tick();
};

#endif /* _IDRAWTICKABLE_H */
