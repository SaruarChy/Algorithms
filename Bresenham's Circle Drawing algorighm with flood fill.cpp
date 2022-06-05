#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int centerX, centerY, radius, x, y, d;

struct Color{
    float r,g,b;
};


struct Color getPixelColor(int X, int Y){
    struct Color color;
    glReadPixels(X, Y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(int x, int y, struct Color color){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


void Flood_Fill_Algorithm(int X, int Y, struct Color Old_Color, struct Color New_color){
    struct Color color;
    color = getPixelColor(X, Y);

    if (color.r==New_color.r && color.g==New_color.g && color.b==New_color.b)
        return;
    if (color.r == Old_Color.r && color.g == Old_Color.g && color.b == Old_Color.b){
        glBegin(GL_POINTS);

        glColor3f(1, 1, 0);

        glVertex2i(X, Y);

        glEnd();
        glFlush();

        Flood_Fill_Algorithm(X+1, Y, Old_Color, New_color);
        Flood_Fill_Algorithm(X-1, Y, Old_Color, New_color);
        Flood_Fill_Algorithm(X, Y+1, Old_Color, New_color);
        Flood_Fill_Algorithm(X, Y-1, Old_Color, New_color);

        return;
    }

    return;
}

void putpixel(int x, int y){
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
    glClear(GL_COLOR_BUFFER_BIT);
    x = 0, y = radius;
    d = 3 -(2 * radius);
    while(x <= y){
        putpixel(x, y);
        glFlush();
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
void display(){
    glPointSize(1.0);
    circleDrawing();
    struct Color Old_Color = {0.0, 0.0, 0.0};
    struct Color New_color = {1.0, 1.0, 1.0};
    int X, Y;
    X = centerX;
    Y = centerY;
    Flood_Fill_Algorithm(X, Y, Old_Color, New_color);
    glFlush();
    glEnd();
}
int main(int argc, char **argv){
    cout<<"Enter the center of the circle: ";
    cin>>centerX>>centerY;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham Circle Drawing Algorithm with flood fill");

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
