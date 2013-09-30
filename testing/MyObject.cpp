#include "MyObject.h"

#include <GL/glut.h>

MyObject::MyObject(): x(0), y(0), z(0), angle(0) { }

MyObject::MyObject(float _x, float _y, float _z): x(_x), y(_y), z(_z), angle(0) { }

MyObject::~MyObject() { }

void MyObject::draw() {
    glPushMatrix();
    {
        glTranslatef(x, y, z);
        glRotatef(angle, 0, 1, 0);
        glutSolidIcosahedron();
    }
    glPopMatrix();
}

void MyObject::tick() {
    angle += 0.1;
}
