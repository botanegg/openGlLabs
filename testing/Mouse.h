#ifndef _MOUSE_H
#define _MOUSE_H

class Mouse {
public:
    int x;
    int y;
    int dx;
    int dy;
    bool buttons[10];

    Mouse();

    void press(int button, int x, int y);
    void release(int button, int x, int y);
    void motion(int x, int y);
    void tick();

    // const bool isPressed (unsigned char key);
};

#endif /* _MOUSE_H */
