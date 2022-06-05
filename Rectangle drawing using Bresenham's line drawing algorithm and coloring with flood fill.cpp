#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

void floodFill(int x, int y)
{
    visited[x+100][y+100]=true;

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();

    for(int i=0; i<=3; i++)
    {
        int vx = x + xx[i];
        int vy = y + yy[i];
        if(vx>X_1&&vx<X_2&& vy>Y_1&&vy<Y_2 && !visited[vx+100][vy+100])
        {
            floodFill(vx,vy);
        }
    }
}

void bresenhamLineDrawing(int x1, int y1, int x2, int y2)
{
    int dx, dy, x, y, decision;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    putpixel(x1, y1);

    if (dx>dy)
    {
        x = x1;
        y = y1;
        decision = (2*dy) - dx;
        for(int i=0; i<dx; i++)
        {
            putpixel(x,y);
            if (decision<0)
            {
                decision = decision + (2*dy);
            }
            else
            {
                decision = decision + 2* (dy-dx);
                if (y1>y2)
                {
                    y--;
                }
                else
                {
                    y++;
                }

            }
            x++;
        }
        glFlush();
        glutSwapBuffers();
    }
    else
    {
        x = x1;
        y = y1;
        decision = (2*dx) - dy;
        for(int i=0; i<dy; i++)
        {
            putpixel(x,y);
            if (decision<0)
            {
                decision = decision + (2*dx);
            }
            else
            {
                decision = decision + 2* (dx-dy);
                x++;
            }
            if (y1>y2)
            {
                y--;
            }
            else
            {
                y++;
            }

        }
        glFlush();
        glutSwapBuffers();
    }


}
void drawAxis(){
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
    glPointSize(1.0);
    glColor3f(1.0, 0.0, 0.0);
    bresenhamLineDrawing(-500, 0, 500, 0);
    bresenhamLineDrawing(0, -500, 0, 500);

    glColor3f(1.0, 1.0, 1.0);
    bresenhamLineDrawing(X_1, Y_1, X_1, Y_2);
    bresenhamLineDrawing(X_1, Y_1, X_2, Y_1);
    bresenhamLineDrawing(X_2, Y_1, X_2, Y_2);
    bresenhamLineDrawing(X_1, Y_2, X_2, Y_2);

    glFlush();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(midX, midY);
    glEnd();
    glFlush();

    floodFill(midX, midY);
    glFlush();

    drawAxis();
    glFlush();
}
int main(int argc, char **argv){
    cout<< "INPUT X_1, Y_1, X_2, Y_2 (within 0 to 500)" << endl;
    cin>>X_1>>Y_1>>X_2>>Y_2;
    if(X_1 > X_2){
        swap(X_1, X_2);
    }
    if (Y_1>Y_2){
        swap(Y_1, Y_2);
    }
    midX = (X_1+X_2)/2;
    midY = (Y_1+Y_2)/2;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(450,100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,500,-100,500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

