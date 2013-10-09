/***********************************************************
 * A Template for building OpenGL applications using GLUT
 *
 * Author: Perspective @ cprogramming.com
 * Date  : Jan, 2005
 *
 * Description:
 *   This code initializes an OpenGL ready window
 * using GLUT.  Some of the most common callbacks
 * are registered to empty or minimal functions.
 *
 * This code is intended to be a quick starting point
 * when building GLUT applications.
 *
 ***********************************************************/

//#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include "App.h"

#define SMOOTH

void menu(int);
void keyboardDown(unsigned char, int, int);
void keyboardUp(unsigned char, int, int);
void reshape(int, int);
void mouseClick(int, int, int, int);
void mouseMotion(int, int);
void idle();
void initGL(int, int);
void draw();

App app;

/* process menu option 'op' */
void menu(int op) {
    switch(op) {
    case 'Q':
    case 'q':
        exit(0);
    }
}

/* executed when a regular key is pressed */
void keyboardDown(unsigned char key, int x, int y) {
    switch(key) {
    case 'Q':
    case 'q':
    case  27:   // ESC
        exit(0);
        break;

    default:
        app.kb.press(key);
    }
}

/* executed when a regular key is released */
void keyboardUp(unsigned char key, int x, int y) {
    app.kb.release(key);
}

/* executed when a special key is pressed */
/*void keyboardSpecialDown(int k, int x, int y) {

}*/

/* executed when a special key is released */
/*void keyboardSpecialUp(int k, int x, int y) {

}*/

/* reshaped window */
void reshape(int width, int height) {
    GLfloat fieldOfView = 72.0f;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fieldOfView, (GLfloat) width / (GLfloat) height, 0.1, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* executed when button 'button' is put into state 'state' at screen position ('x', 'y') */
void mouseClick(int button, int state, int x, int y) {
    //std::cout << "Mouse" << button << " " << state << " " << x << " " << y << std::endl;
    if(state == 0)
        app.m.press(x, y);
}

/* executed when the mouse moves to position ('x', 'y') */
void mouseMotion(int x, int y) {
    //std::cout << "Mouse motion " << x << " " << y << std::endl;
    app.m.motion(x, y);
}

/* render the scene */
void draw() {
    glEnable(GL_MULTISAMPLE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(app.cam.camX, app.cam.camY, app.cam.camZ, app.cam.lookAtX() , app.cam.lookAtY(), app.cam.lookAtZ(), app.cam.upDirectX, app.cam.upDirectY, app.cam.upDirectZ);

    float pos[4] = {3, 3, 3, 1};
    float dir[3] = { -1, -1, -1};
    glColor3f(1.0, 1.0, 1.0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glBegin(GL_LINES);
    {
        glColor3f(1.0, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glColor3f(0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glColor3f(0, 0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    int N = 25;
    int M = 25;
    float dx = 10;
    float dz = 10;
    float x0 = -N * dx / 2;
    float z0 = -M * dz / 2;
    glBegin(GL_LINES);
    {
        for(int i = 0; i <= N; ++i) {
            glVertex3f(i * dx + x0, -1.0f, z0);
            glVertex3f(i * dx + x0, -1.0f, z0 + M * dz);
        }

        for(int j = 0; j <= M; ++j) {
            glVertex3f(x0, -1.0f, z0 + j * dz);
            glVertex3f(N * dx + x0, -1.0f, z0 + j * dz);
        }
    }
    glEnd();
    /* render the scene here */

    app.draw();

    glFlush();
    glutSwapBuffers();

    glDisable(GL_MULTISAMPLE);
}

/* executed when program is idle */
void idle() {
    app.tick();
    //std::cout << "tick" << app._tick <<std::endl;
    draw();
}

/* initialize OpenGL settings */
void initGL(int width, int height) {

    reshape(width, height);

    glEnable(GL_CULL_FACE);
    // тест прозрачности, т.е. будет учитываться
    // четвертый параметр в glColor
    glEnable(GL_ALPHA_TEST);
    // тест глубины
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    // glColor будет устанавливать
    // свойства материала
    // вам не надо дополнительно
    // вызывать glMaterialfv
    glEnable(GL_COLOR_MATERIAL);
    // разрешаем освещение
    glEnable(GL_LIGHTING);
    // включаем нулевую лампу
    glEnable(GL_LIGHT0);
    // разрешаем смешение цветов
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // устанавливаем положение нулевой лампы
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

#ifdef SMOOTH
    glEnable(GL_DITHER);
//glEnable(GL_LINE_SMOOTH);
//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
#endif
}

/* initialize GLUT settings, register callbacks, enter main loop */
int main(int argc, char **argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Perspective's GLUT Template");

    // register glut call backs
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    //glutSpecialFunc(keyboardSpecialDown);
    //glutSpecialUpFunc(keyboardSpecialUp);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);
    //glutPassiveMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutIdleFunc(idle);
    glutIgnoreKeyRepeat(true); // ignore keys held down

    // create a sub menu
    int subMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Do nothing", 0);
    glutAddMenuEntry("Really Quit", 'q');

    // create main "right click" menu
    glutCreateMenu(menu);
    glutAddSubMenu("Sub Menu", subMenu);
    glutAddMenuEntry("Quit", 'q');
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    initGL(640, 480);

    app.init();

    glutMainLoop();
    return 0;
}
