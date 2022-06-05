#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int centerX, centerY, radius;

void putpixel(int x, int y){
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2d(centerX+x, centerY+y);
    glVertex2d(centerX+y, centerY+x);
    glVertex2d(centerX-x, centerY+y);
    glVertex2d(centerX-y, centerY+x);
    glVertex2d(centerX+x, centerY-y);
    glVertex2d(centerX+y, centerY-x);
    glVertex2d(centerX-x, centerY-y);
    glVertex2d(centerX-y, centerY-x);
    glEnd();
}

void circleDrawing(){
    int x=0, y=radius, d;
    d = 3-(2*radius);
    while(x <= y){
        putpixel(x,y);
        if (d >= 0){
            d = d+4*(x-y)+10;
            y--;
        }
        else{
            d = d+(4*x)+6;
        }
        x++;
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
    circleDrawing();
    glFlush();
    drawAxis();
}
int main(int argc, char **argv){

    cout<<"Enter the center of the Circle as X and Y"<<endl;
    cin>>centerX>>centerY;
    cout<<"Enter the Radius of the circle"<<endl;
    cin>>radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
