#include "Camera.h"
#include <cmath>
#include <climits>

#define FOCUSMOD 4

Camera::Camera() {
    angleXZ = 0;
    angleH = 0;

    camX = 0;
    camY = 0;
    camZ = 0;

    focus = false;

    camDirectUpdate();
}

inline float Camera::focusmod(float x) const {
    return focus ? x / FOCUSMOD : x;
}

void Camera::setFocus(bool _focus) {
    focus = _focus;
}

bool Camera::getFocus() const {
    return focus;
}

void Camera::moveForward() {
    camX += focusmod(viewVecX);
    camY += focusmod(viewVecY);
    camZ += focusmod(viewVecZ);
}

void Camera::moveBack() {
    camX -= focusmod(viewVecX);
    camY -= focusmod(viewVecY);
    camZ -= focusmod(viewVecZ);
}

void Camera::moveUp() {
    camY += focusmod(1);
}

void Camera::moveDown() {
    camY -= focusmod(1);
}

void Camera::moveLeft() {
    float X = viewVecZinXZ;
    float Z = -viewVecXinXZ;
    camX += focusmod(X);
    camZ += focusmod(Z);
}

void Camera::moveRight() {
    float X = -viewVecZinXZ;
    float Z = viewVecXinXZ;
    camX += focusmod(X);
    camZ += focusmod(Z);
}

void Camera::addAngleXZ(short add) {
    angleXZ += add;
    camDirectUpdate();
}

void Camera::addAngleH(short add) {
    add *= 2;
    if ( ((int)angleH + (int)add) < SHRT_MIN ) angleH = (short)SHRT_MIN;
    else if ( ((int)angleH + (int)add) > SHRT_MAX ) angleH = (short)SHRT_MAX;
    else angleH += add;
    camDirectUpdate();
}

float Camera::lookAtX() const {
    return camX + viewVecX;
}

float Camera::lookAtY() const {
    return camY + viewVecY;
}

float Camera::lookAtZ() const {
    return camZ + viewVecZ;
}

float Camera::getAngleXZ() const {
    return -((float)angleXZ) / (unsigned short)USHRT_MAX * 2 * M_PI;
}


float Camera::getAngleH() const {
    return ((float)angleH) / (unsigned short)USHRT_MAX * M_PI;
}

void Camera::camDirectUpdate() {
    viewVecX = cos(getAngleXZ()) * cos(getAngleH());
    viewVecZ = sin(getAngleXZ()) * cos(getAngleH());
    viewVecY = sin(getAngleH());

    viewVecXinXZ = cos(getAngleXZ());
    viewVecZinXZ = sin(getAngleXZ());

    float a[3];
    float b[3];

    a[0] = -viewVecZinXZ;
    a[1] = 0;
    a[2] = viewVecXinXZ;

    b[0] = viewVecX;
    b[1] = viewVecY;
    b[2] = viewVecZ;

    upDirectX = a[1] * b[2] - a[2] * b[1];
    upDirectY = a[2] * b[0] - a[0] * b[2];
    upDirectZ = a[0] * b[1] - a[1] * b[0];
}
