#ifndef _CAMERA_H
#define _CAMERA_H

class Camera {
public:
    float camX;
    float camY;
    float camZ;

    float viewVecX;
    float viewVecY;
    float viewVecZ;

    float viewVecXinXZ;
    float viewVecZinXZ;

    float upDirectX;
    float upDirectY;
    float upDirectZ;

    unsigned short angleXZ;
    short angleH;

    bool focus;

    Camera();

    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void addAngleXZ(short add);
    void addAngleH(short add);

    float lookAtX() const;
    float lookAtY() const;
    float lookAtZ() const;

    float getAngleXZ() const;
    float getAngleH() const;

    void setFocus(bool _focus);
    bool getFocus() const;
    inline float focusmod(float x) const;

    void camDirectUpdate();

    void tick();
};

#endif /* _CAMERA_H */
