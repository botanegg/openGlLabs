#include <iostream>
#include <conio.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glaux.h"

using namespace std;
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib, "glaux.lib")

int N, M;

void CALLBACK resize(int width,int height)
{
    // Здесь вы указываете ту часть окна,
    // куда осуществляется вывод OpenGL.
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    // Устанавливаем тип проекции.
    // glOrtho - параллельная
    // glFrustum - перспективная
    // Параметры у этих функций одинаковые.
    // Они определяют объем, который вы видите.
    // левая стенка - пять единиц влево
    // правая - пять единиц вправо
    // далее, нижняя стенка и верхняя
    // и наконец, передняя и задняя
    // см. ниже картинку
    glOrtho(-5,5, -5,5, 2,12);
    // Устанавливаем точку, в которой
    // находится наш глаз ---(0,0,5)
    // направление, куда смотрим --- (0,0,0)
    // вектор, принимаемый за направление вверх --- (0,1,0)
    // этим вектором является ось Y
    gluLookAt( 0,0,5, 0,0,0, 0,1,0 );
    glMatrixMode( GL_MODELVIEW );
}
void CALLBACK display(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // remove next tree lines
    // and enter your code here

    int i, j;
    float dx = 0.1, dy = 0.1;
    float x0 = -N*dx/2, y0 = -M*dy/2;
    glBegin(GL_LINES);
    for (i = 0; i<=N; i++)
    {
        glVertex3f(i*dx+x0, y0, -1.0f);
        glVertex3f(i*dx+x0, y0+M*dy, -1.0f);
    }
    for (j = 0; j<=M; j++)
    {
        glVertex3f(x0, y0+j*dy, -1.0f);
        glVertex3f(N*dx+x0, y0+j*dy, -1.0f);
    }

    glEnd();

    auxSwapBuffers();
}
void RunOpenGL()
{
    float pos[4] = {3,3,3,1};
    float dir[3] = {-1,-1,-1};
    // указываем координаты окна на экране
    // верхний левый угол (50,10)
    // ширина и высота - 400
    auxInitPosition( 0, 0, 800, 600);
    // устанавливаем параметры контекста OpenGL
    //
    auxInitDisplayMode( AUX_RGB | AUX_DEPTH | AUX_DOUBLE );
    // создаем окно на экране
    auxInitWindow( "Glaux Template" );
    // наше окно будет получать сообщения
    // от клавиатуры, мыши, таймера или любые другие
    // когда никаких сообщений нет
    // будет вызываться функция display
    // так мы получаем анимацию
    // если вам нужна статическая картинка,
    // то закомментируйте следующую строку
    auxIdleFunc(display);
    // при изменении размеров окна
    // придет соответствующее сообщение
    // в Windows - это WM_SIZE
    // мы устанавливаем функцию resize,
    // которая будет вызвана
    // при изменении размеров окна
    auxReshapeFunc(resize);
    // тест прозрачности, т.е. будет учитываться
    // четвертый параметр в glColor
    glEnable(GL_ALPHA_TEST);
    // тест глубины
    glEnable(GL_DEPTH_TEST);
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
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    // и последнее, устанавливаем
    // функцию display отрисовки окна
    // эта функция будет вызываться всякий раз,
    // когда потребуется перерисовать окно
    // например, когда вы развернете окно на весь экран
    // в windows - это обработчик сообщения WM_PAINT
    auxMainLoop(display);
}

void main()
{
    cout <<"Enter N, M"<<endl;

    cin>>N>>M;

    RunOpenGL();
    getch();
}