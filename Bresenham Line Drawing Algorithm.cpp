#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int X_1, X_2, Y_1, Y_2;

void putpixel(int x, int y){
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
}

void drawAxis(){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i=-500; i<=500; i++){
        glVertex2d(i,0);
        glVertex2d(0,i);
    }
    glEnd();
    glFlush();
}

void bresenhamLineDrawing(){
    int dx, dy, x, y, decision;
    dx = abs(X_2 - X_1);
    dy = abs(Y_2 - Y_1);
    x = X_1;
    y = Y_1;
    decision = (2*dy) - dx;
    while(x<=X_2){
        putpixel(x,y);
        if (decision<0){
            decision = decision + (2*dy);
        }
        else{
            decision = decision + 2* (dy-dx);
            y++;
        }
        x++;
    }
}

void display(){
    bresenhamLineDrawing();
    drawAxis();
    glFlush();
}

int main(int argc, char **argv){
    cout<< "INPUT X_1, Y_1, X_2, Y_2" << endl;
    cin>>X_1>>Y_1>>X_2>>Y_2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


