#ifndef _MOUSE_H
#define _MOUSE_H

class Mouse {
public:
    float dx,dy,x,y;

    Mouse();

    void press(int x, int y);
    void motion(int x, int y);
    void release();

    // const bool isPressed(unsigned char key);
};


#endif /* _MOUSE_H */
