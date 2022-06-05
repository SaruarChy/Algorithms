#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//int centerX, centerY, radius;
int X_1, Y_1, X_2, Y_2, midX, midY;
int visited[10000][10000];
int xx[] = {0,0,1,-1};
int yy[] = {1,-1,0,0};

void putpixel(int x, int y)
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

void DDAAlgorithm()
{
    int dx, dy, steps;
    float xinc, yinc, X, Y;
    dx = X_2 - X_1;
    dy = Y_2 - Y_1;
    steps = max(abs(dx), abs(dy));
    xinc = dx/steps;
    yinc = dy/steps;
    X = X_1;
    Y = Y_1;
    for(int i=0; i<=steps; i++)
    {
        putpixel(floor(X), floor(Y));
        X+= xinc;
        Y+= yinc;
    }
}
void drawAxis()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i=-500; i<=500; i++)
    {
        glVertex2d(i,0);
        glVertex2d(0,i);
    }
    glEnd();
    glFlush();
}

void display(){
    glBegin(GL_POINTS);
    glPointSize(1.0);
    glColor3f(1.0, 0.0, 0.0);
    drawAxis();
    DDAAlgorithm();
    glFlush();
    glEnd();
}
int main(int argc, char **argv)
{
    cout<<"Enter the value of X1, Y1, X2 and Y2:"<<endl;
    cin>>X_1>>Y_1>>X_2>>Y_2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(450,100);
    glutCreateWindow("DDA Line Drawing Algorithm");

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,500,-100,500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

