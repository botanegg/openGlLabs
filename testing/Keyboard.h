#ifndef _KEYBOARD_H
#define _KEYBOARD_H

class Keyboard {
public:
    bool keyPress[255];

    Keyboard();

    void press(unsigned char key);
    void release(unsigned char key);

    const bool isPressed(unsigned char key);
};


#endif /* _KEYBOARD_H */
