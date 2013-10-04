#ifndef _MOUSE_H
#define _MOUSE_H

class Mouse {
public:
    float dx;
    float dy;
    float x;
    float y;

    Mouse();

    void press(int x, int y);
    void motion(int x, int y);
    void release();

    // const bool isPressed (unsigned char key);
};

#endif /* _MOUSE_H */
