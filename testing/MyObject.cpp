#include "MyObject.h"

#include <GL/glut.h>


MyObject::MyObject(): tex(), x(0), y(0), z(0), angle(0) {}

MyObject::MyObject(float _x, float _y, float _z): tex(), x(_x), y(_y), z(_z), angle(0) {}

MyObject::~MyObject() {
}

void MyObject::draw() {
    glPushMatrix();
    {
        glTranslatef(x, y, z);
        glRotatef(angle, 0, 1, 0);
        glEnable(GL_TEXTURE_2D);

        //glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        //glEnable(GL_TEXTURE_GEN_T);

        glBindTexture(GL_TEXTURE_2D, tex.textureId);
        // glutSolidTeapot(2);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glTexCoord2d(0, 1);
        glVertex3d(0, 1, 0);
        glTexCoord2d(1, 1);
        glVertex3d(1, 1, 0);
        glTexCoord2d(1, 0);
        glVertex3d(1, 0, 0);
        glTexCoord2d(0, 0);
        glVertex3d(0, 0, 0);
        glEnd();
        // glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
        // glDisable(GL_TEXTURE_GEN_T);

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void MyObject::tick() {
    angle += 0.1f;
}
