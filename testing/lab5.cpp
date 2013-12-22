#include "lab5.h"

#include <GL/glut.h>

#include <cmath>


lab5::lab5() {}

lab5::~lab5() {
}

void line(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    {
        glColor3f(1.f,1.f,1.f);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void rec(int n, float x1, float y1, float x2, float y2) {
    if(n <= 1) {
        line(x1, y1, x2, y2);

    } else {
        float x3 = x1 + (x2 - x1) / 3;
        float y3 = y1 + (y2 - y1) / 3;
        float x4 = x1 + (x2 - x1) / 2 - (y2 - y1) / 4;
        float y4 = (y1 + y2) / 2 + (x2 - x1) / 4;
        float x5 = x1 + 2 * (x2 - x1) / 3;
        float y5 = y1 + 2 * (y2 - y1) / 3;

        rec(n - 1, x1, y1, x3, y3);
        rec(n - 1, x3, y3, x4, y4);
        rec(n - 1, x4, y4, x5, y5);
        rec(n - 1, x5, y5, x2, y2);
    }
}

void lab5::draw() {
    glPushMatrix();
    {
        glTranslatef(20.f, 0.f, -10.f);
         glScalef(10.f, 10.f, 10.f);
    rec(6, 1, 0, 0, 0);
    rec(6, 0, 0, 0.5, sqrtf(3)/2);
    rec(6, 0.5, sqrtf(3)/2, 1, 0);
    }
    glPopMatrix();
}

void lab5::tick() {
}
