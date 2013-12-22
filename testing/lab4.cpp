#include "lab4.h"

#include <GL/glut.h>

#include <cmath>


lab4::lab4() {}

lab4::~lab4() {
}

float lab4::func(float x) {
    return sqrtf(sinf(x) * 10 + 10);
}

void drawface(float x, float y) {
    glPushMatrix();
    {
        glTranslatef(x - 0.1f, y, 0.f);
        glScalef(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINE_LOOP);
        {
            glVertex3f(-1, -1, 0);
            glVertex3f(1, -1, 0);
            glVertex3f(1, 1, 0);
            glVertex3f(-1, 1, 0);
        }
        glEnd();

    }
    glPopMatrix();

}

void lab4::draw() {
    glPushMatrix();
    {
        glBegin(GL_LINES);
        {
            glVertex2f(10, -10);
            glVertex2f(10, 10);
            glVertex2f(-10, 10);
            glVertex2f(-10, -10);
        }
        glEnd();

        float l_x = -10;
        float l_y = func(l_x);

        float t = 0.05f;

        float next_x = l_x + t;
        float next_y = func(next_x);

        bool prev_hi = false;

        while(l_x <= 10) {
            bool is_hi = false;

            if(next_y - l_y > 0) is_hi = true;

            if(is_hi) glColor3f(1.0, 0, 0);

            else glColor3f(0, 1.0, 0);

            glBegin(GL_LINES);
            {
                glVertex2f(l_x, l_y);
                glVertex2f(next_x, next_y);
            }
            glEnd();

            if(prev_hi != is_hi) {
                glPointSize(5);
                glBegin(GL_POINT);
                {
                    glColor3f(0, 1.0, 1.0);
                    drawface(next_x, next_y);
                }
                glEnd();
                glPointSize(1);
            }

            prev_hi = is_hi;

            l_x = next_x;
            l_y = next_y;

            next_x = l_x + t;
            next_y = func(next_x);
        }


    }
    glPopMatrix();
}

void lab4::tick() {
}
