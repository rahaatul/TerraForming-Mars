#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include<iostream>
#define PI 3.1416

using namespace std;

GLfloat position = 0.0f;
GLfloat speed = 0.3f;

GLfloat speed1 = 1.9f;

//rocket first console
GLfloat position3 = 0.0f;
GLfloat speed3 = 0.6f;


float _angle = 0.0f;

bool sign_visible = false;
bool building_visible = false;
bool house_visible = false;
bool tree_visible = false;
bool green_hill_visible = false;
bool cloud_one_visible = false;
bool cloud_two_visible = false;
bool cloud_three_visible = false;
bool green_ground_visible = false;



float _move = 0.0f;

void update(int value)
{

    if(position <-12.3f)
        position = 0.0f;


    position = speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}


void update1(int value)
{

    if(_angle >160.3f)
        _angle = -20.0f;


    _angle -= speed1;

    glutPostRedisplay();
    glutTimerFunc(100, update1, 0);
}

//rocket first console
void update3(int value)
{

    if(position3 <-4.5f)
        position3 = 0.0f;


    position3 -= speed3;

    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}

//rocket first console
void rocket_one()
{


    glPushMatrix();
    glTranslatef(-position3,-position3,0.0f);
    glBegin(GL_QUADS); //Main body (UP) //Complete
    glColor3ub( 205,183,181);
    glVertex2f(-3.2f,-2.3f);
    glVertex2f(-2.6f,-1.7f);
    glVertex2f(-2.3f,-1.9f);
    glVertex2f(-2.9f,-2.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //Upper triangle (UP)
    glColor3ub( 205,183,181);
    glVertex2f(-2.6f,-1.7f);
    glVertex2f(-2.2f,-1.6f);
    glVertex2f(-2.3f,-1.9f);
    glEnd();

    glBegin(GL_QUADS);// line 1 (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-2.6f,-1.7f);
    glVertex2f(-2.3f,-1.9f);
    glVertex2f(-2.35f,-1.95f);
    glVertex2f(-2.65f,-1.75f);
    glEnd();

    glBegin(GL_QUADS);//line 2 (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-2.9f, -2.0f);
    glVertex2f(-2.6f, -2.2f);
    glVertex2f(-2.65f, -2.25f);
    glVertex2f(-2.95f, -2.05f);

    glEnd();

    glBegin(GL_TRIANGLES); //R (UP)
     glColor3ub( 139,137,112);
    glVertex2f(-2.6f,-2.2f);
    glVertex2f(-2.4f,-2.6f);
    glVertex2f(-2.8f,-2.4f);
    glEnd();

     glBegin(GL_TRIANGLES); //l (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-3.1f,-2.2f);
    glVertex2f(-3.4f,-1.9f);
    glVertex2f(-2.9f,-2.0f);
    glEnd();

    glBegin(GL_TRIANGLES); //l (UP)
    glColor3ub( 255,193,37);
    glVertex2f(-3.15f,-2.4f);
    glVertex2f(-3.02f,-2.4f);
    glVertex2f(-3.0f,-2.5f);
    glEnd();
    glPopMatrix();

 glFlush();

}



void circle_one(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
    glFlush();
}

void house()
{

    glPushMatrix();
    glTranslated(8,-7.5,0);// X & Y axis
    glScaled(70,100,0);
    glColor3ub( 205,205,193);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();

    glBegin(GL_LINES);// HOUSE LINE 1
    glColor3ub( 131,139,131);
    glVertex2f(10.0f,-6.5f);
    glVertex2f(4.55f,-6.5f);
    glEnd();

    glBegin(GL_LINES);// HOUSE LINE 2
    glColor3ub( 131,139,131);
    glVertex2f(10.0f,-5.5f);
    glVertex2f(4.8f,-5.5f);
    glEnd();

    glBegin(GL_LINES);// HOUSE LINE 3
    glColor3ub( 131,139,131);
    glVertex2f(10.0f,-4.5f);
    glVertex2f(5.2f,-4.5f);
    glEnd();

    glBegin(GL_LINES);// HOUSE LINE 4
    glColor3ub( 131,139,131);
    glVertex2f(10.0f,-3.5f);
    glVertex2f(5.9f,-3.5f);
    glEnd();


    glBegin(GL_QUADS);// HOUSE DOOR
    glColor3ub( 139,136,120);
    glVertex2f(6.5f,-5.9f);
    glVertex2f(8.5f,-5.9f);
    glVertex2f(8.5f,-7.0f);
    glVertex2f(6.5f,-7.0f);
    glEnd();


    glBegin(GL_QUADS);// HOUSE WINDOW L1
    glColor3ub( 255,165,0);
    glVertex2f(5.5f,-6.0f);
    glVertex2f(5.3f,-6.0f);
    glVertex2f(5.3f,-6.3f);
    glVertex2f(5.5f,-6.3f);
    glEnd();

    glBegin(GL_QUADS);// HOUSE WINDOW L2
    glColor3ub( 255,165,0);
    glVertex2f(6.0f,-6.0f);
    glVertex2f(5.8f,-6.0f);
    glVertex2f(5.8f,-6.3f);
    glVertex2f(6.0f,-6.3f);
    glEnd();

    glBegin(GL_QUADS);// HOUSE WINDOW R1
    glColor3ub( 255,165,0);
    glVertex2f(9.0f,-6.0f);
    glVertex2f(9.2f,-6.0f);
    glVertex2f(9.2f,-6.3f);
    glVertex2f(9.0f,-6.3f);
    glEnd();

    glBegin(GL_QUADS);// HOUSE WINDOW R2
    glColor3ub( 255,165,0);
    glVertex2f(9.5f,-6.0f);
    glVertex2f(9.7f,-6.0f);
    glVertex2f(9.7f,-6.3f);
    glVertex2f(9.5f,-6.3f);
    glEnd();






    glFlush();
}




void sun()
{

    glPushMatrix();

    glRotatef(_angle, 0.0f, 0.0f,1.0f);
    glTranslated(-6,6,0);// X & Y axis
    glScaled(15,20,0);
    glColor3ub( 255, 13, 43 );
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();
    glFlush();
}
void cloud1()
{

    glPushMatrix();// cloud 1
    glTranslated(0.5,6,0);// X & Y & Z axis point select
    glScaled(6,11,0);// Axis size increase and dicrease
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);// CircleSize
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(0.4,6,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(0.6,6,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();

    glFlush();
}

void cloud2()
{
    glPushMatrix();// cloud 1
    glTranslated(3,5.5,0);// X & Y & Z axis point select
    glScaled(6,11,0);// Axis size increase and dicrease
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);// CircleSize
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(2.9,5.5,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(3.1,5.5,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();

    glFlush();
}
void cloud3()
{

    glPushMatrix();// cloud 1
    glTranslated(5,5,0);// X & Y & Z axis point select
    glScaled(6,11,0);// Axis size increase and dicrease
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);// CircleSize
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(4.9,5,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();



    glPushMatrix();
    glTranslated(5.1,5,0);
    glScaled(9,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();

    glFlush();
}


void hill1()
{


    glBegin(GL_TRIANGLES);// big hill 1
    glColor3ub( 139,35,35);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(7.0f,4.0f);
    glVertex2f(4.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// big hill 2
    glColor3ub( 139,35,35);
    glVertex2f(4.5f,-7.0f);
    glVertex2f(2.5f,2.0f);
    glVertex2f(0.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// big hill 3
    glColor3ub( 139,35,35);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-2.5f,3.0f);
    glVertex2f(-4.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// hill
    glColor3ub( 205,38,38);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(9.2f,0.0f);
    glVertex2f(8.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 1
    glColor3ub( 205,38,38);
    glVertex2f(8.5f,-7.0f);
    glVertex2f(7.5f,2.0f);
    glVertex2f(6.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 2
    glColor3ub( 205,38,38);
    glVertex2f(6.5f,-7.0f);
    glVertex2f(5.8f,1.5f);
    glVertex2f(4.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 3
    glColor3ub( 205,38,38);
    glVertex2f(4.0f,-7.0f);
    glVertex2f(3.5f,-3.0f);
    glVertex2f(2.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 4
    glColor3ub( 205,38,38);
    glVertex2f(2.5f,-7.0f);
    glVertex2f(1.5f,-4.5f);
    glVertex2f(0.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 5

    glColor3ub( 205,38,38);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-1.5f,2.0f);
    glVertex2f(-3.0f,-7.0f);
    glEnd();


}


void sign()
{

    glLineWidth(2);
    glBegin(GL_QUADS);// sign bord
    glColor3ub( 0,0,128);
    glVertex2f(-5.5f,-6.6f);
    glVertex2f(-5.5f,-5.5f);
    glVertex2f(-4.0f,-5.5f);
    glVertex2f(-4.0f,-6.6f);
    glEnd();

    glBegin(GL_LINES);// sign 1
    glColor3ub( 131,139,131);
    glVertex2f(-5.4f,-6.6f);
    glVertex2f(-5.4f,-7.0f);
    glEnd();

    glBegin(GL_LINES);// sign 2
    glColor3ub( 131,139,131);
    glVertex2f(-4.1f,-6.6f);
    glVertex2f(-4.1f,-7.0f);
    glEnd();


    glBegin(GL_LINES);// M
    glColor3ub( 255,250,250);
    glVertex2f(-5.4f,-6.1f);
    glVertex2f(-5.4f,-5.6f);
    glVertex2f(-5.4f,-5.6f);
    glVertex2f(-5.2f,-5.8f);
    glVertex2f(-5.2f,-5.8f);
    glVertex2f(-5.0f,-5.6f);
    glVertex2f(-5.0f,-5.6f);
    glVertex2f(-5.0f,-6.1f);
    glEnd();


    glBegin(GL_LINES);// A
    glColor3ub( 255,250,250);
    glVertex2f(-5.0f,-6.1f);
    glVertex2f(-4.8f,-5.6f);
    glVertex2f(-4.8f,-5.6f);
    glVertex2f(-4.6f,-6.1f);
    glVertex2f(-4.9f,-5.9f);
    glVertex2f(-4.7f,-5.9f);
    glEnd();


    glBegin(GL_LINES);// R
    glColor3ub( 255,250,250);
    glVertex2f(-4.6f,-6.1f);
    glVertex2f(-4.6f,-5.6f);
    glVertex2f(-4.6f,-5.6f);
    glVertex2f(-4.4f,-5.6f);
    glVertex2f(-4.4f,-5.6f);
    glVertex2f(-4.4f,-5.8f);
    glVertex2f(-4.4f,-5.8f);
    glVertex2f(-4.6f,-5.8f);
    glVertex2f(-4.6f,-5.8f);
    glVertex2f(-4.4f,-6.1f);
    glEnd();



    glBegin(GL_LINES);// S
    glColor3ub( 255,250,250);
    glVertex2f(-4.3f,-6.0f);
    glVertex2f(-4.1f,-6.0f);
    glVertex2f(-4.1f,-6.0f);
    glVertex2f(-4.1f,-5.8f);
    glVertex2f(-4.1f,-5.8f);
    glVertex2f(-4.3f,-5.8f);
    glVertex2f(-4.3f,-5.8f);
    glVertex2f(-4.3f,-5.6f);
    glVertex2f(-4.3f,-5.6f);
    glVertex2f(-4.1f,-5.6f);



    glEnd();

}
void rocket()
{

    glPushMatrix();
    glTranslatef(0.0,position,0.0f);
    glBegin(GL_QUADS); //Main body (UP) //Complete
    glColor3ub( 205,183,181);
    glVertex2f(-7.5f,7.0f);
    glVertex2f(-7.0f,7.0f);
    glVertex2f(-7.0f,5.65f);
    glVertex2f(-7.5f,5.65f);
    glEnd();

    glBegin(GL_TRIANGLES); //Upper triangle (UP)
    glColor3ub( 205,183,181);
    glVertex2f(-7.5f,7.0f);
    glVertex2f(-7.25f,7.6f);
    glVertex2f(-7.0f,7.0f);
    glEnd();

    glBegin(GL_QUADS);// line 1 (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-7.5f,7.0f);
    glVertex2f(-7.0f,7.0f);
    glVertex2f(-7.0f,6.95f);
    glVertex2f(-7.5f,6.95f);
    glEnd();

    glBegin(GL_QUADS);//line 2 (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-7.5f, 6.15f);
    glVertex2f(-7.0f, 6.15f);
    glVertex2f(-7.0f, 6.0f);
    glVertex2f(-7.5f, 6.0f);
    glEnd();

    glBegin(GL_QUADS);//  R (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-7.0f,6.15f);//6.15
    glVertex2f(-6.5f,5.85f);//5.85
    glVertex2f(-6.5f,5.75f);//5.75
    glVertex2f(-7.0f,5.75f);//5.75
    glEnd();

    glBegin(GL_QUADS);//L (UP)
    glColor3ub( 139,137,112);
    glVertex2f(-7.5f,6.15f);
    glVertex2f(-8.0f,5.85f);
    glVertex2f(-8.0f,5.75f);
    glVertex2f(-7.5f,5.75f);
    glEnd();


    glBegin(GL_QUADS);//under flame (UP)
    glColor3ub( 255,193,37);
    glVertex2f(-7.3f,5.65f);//5.65
    glVertex2f(-7.2f,5.65f);//5.65
    glVertex2f(-7.1f,5.5f);//5.5
    glVertex2f(-7.4f,5.5f);//5.5
    glEnd();
    glPopMatrix();

}


void building()
{



    glBegin(GL_QUADS);//main
    glColor3ub( 205,205,193);
    glVertex2f(-10.0f,-6.7f);
    glVertex2f(-10.0f,-3.0f);
    glVertex2f(-8.7f,-3.0f);
    glVertex2f(-8.7f,-6.7f);
    glEnd();


    glBegin(GL_QUADS);// window1
    glColor3ub( 255,165,0);
    glVertex2f(-9.6f,-3.4f);
    glVertex2f(-9.3f,-3.4f);
    glVertex2f(-9.3f,-3.7f);
    glVertex2f(-9.6f,-3.7f);
    glEnd();



    glBegin(GL_QUADS);// window2
    glColor3ub( 255,165,0);
    glVertex2f(-9.6f,-4.4f);
    glVertex2f(-9.3f,-4.4f);
    glVertex2f(-9.3f,-4.7f);
    glVertex2f(-9.6f,-4.7f);
    glEnd();


    glBegin(GL_QUADS);// window3
    glColor3ub( 255,165,0);
    glVertex2f(-9.6f,-5.4f);
    glVertex2f(-9.3f,-5.4f);
    glVertex2f(-9.3f,-5.7f);
    glVertex2f(-9.6f,-5.7f);
    glEnd();


    glBegin(GL_QUADS);// side rek 1
    glColor3ub( 131,139,131);
    glVertex2f(-8.7f,-6.7f);
    glVertex2f(-8.7f,-3.0f);
    glVertex2f(-8.75f,-3.0f);
    glVertex2f(-8.75f,-6.7f);
    glEnd();







    glBegin(GL_QUADS);// rek 1
    glColor3ub( 131,139,131);
    glVertex2f(-10.0f,-3.0f);
    glVertex2f(-10.0f,-3.2f);
    glVertex2f(-8.7f,-3.2f);
    glVertex2f(-8.7f,-3.0f);
    glEnd();



    glBegin(GL_QUADS);// rek 2
    glColor3ub( 131,139,131);
    glVertex2f(-10.0f,-4.1f);
    glVertex2f(-10.0f,-4.0f);
    glVertex2f(-8.7f,-4.0f);
    glVertex2f(-8.7f,-4.1f);
    glEnd();

    glBegin(GL_QUADS);// rek 3
    glColor3ub( 131,139,131);
    glVertex2f(-10.0f,-5.1f);
    glVertex2f(-10.0f,-5.0f);
    glVertex2f(-8.7f,-5.0f);
    glVertex2f(-8.7f,-5.1f);
    glEnd();

    glBegin(GL_QUADS);// rek 4
    glColor3ub( 131,139,131);
    glVertex2f(-10.0f,-6.1f);
    glVertex2f(-10.0f,-6.0f);
    glVertex2f(-8.7f,-6.0f);
    glVertex2f(-8.7f,-6.1f);
    glEnd();



    glBegin(GL_QUADS);// rek 5
    glColor3ub( 131,139,131);
    glVertex2f(-10.0f,-6.6f);
    glVertex2f(-8.7f,-6.6f);
    glVertex2f(-8.7f,-6.7f);
    glVertex2f(-10.0f,-6.7f);
    glEnd();


    glBegin(GL_QUADS);// siri 3
    glColor3ub( 131,139,131);
    glVertex2f(-8.7f,-7.0f);
    glVertex2f(-8.7f,-6.9f);
    glVertex2f(-8.4f,-6.9f);
    glVertex2f(-8.4f,-7.0f);
    glEnd();

    glBegin(GL_QUADS);// siri 2
    glColor3ub( 131,139,131);
    glVertex2f(-8.7f,-6.9f);
    glVertex2f(-8.7f,-6.8f);
    glVertex2f(-8.5f,-6.8f);
    glVertex2f(-8.5f,-6.9f);
    glEnd();

    glBegin(GL_QUADS);// siri 1
    glColor3ub( 131,139,131);
    glVertex2f(-8.7f,-6.8f);
    glVertex2f(-8.7f,-6.7f);
    glVertex2f(-8.6f,-6.7f);
    glVertex2f(-8.6f,-6.8f);
    glEnd();


    glBegin(GL_QUADS);// pil L
    glColor3ub( 131,139,131);
    glVertex2f(-9.8f,-6.7f);
    glVertex2f(-9.6f,-6.7f);
    glVertex2f(-9.6f,-7.0f);
    glVertex2f(-9.8f,-7.0f);
    glEnd();

    glBegin(GL_QUADS);// pil R
    glColor3ub( 131,139,131);
    glVertex2f(-9.2f,-6.7f);
    glVertex2f(-9.0f,-6.7f);
    glVertex2f(-9.0f,-7.0f);
    glVertex2f(-9.2f,-7.0f);
    glEnd();

}


void hill()
{


    glBegin(GL_TRIANGLES);// big hill 1
    glColor3ub( 106, 137, 112);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(7.0f,4.0f);
    glVertex2f(4.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// big hill 2
    glColor3ub(106, 137, 112);
    glVertex2f(4.5f,-7.0f);
    glVertex2f(2.5f,2.0f);
    glVertex2f(0.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// big hill 3
    glColor3ub( 106, 137, 112);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-2.5f,3.0f);
    glVertex2f(-4.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// hill
    glColor3ub( 106, 137, 112);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(9.2f,0.0f);
    glVertex2f(8.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 1
    glColor3ub( 106, 137, 112);
    glVertex2f(8.5f,-7.0f);
    glVertex2f(7.5f,2.0f);
    glVertex2f(6.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 2
    glColor3ub( 106, 137, 112);
    glVertex2f(6.5f,-7.0f);
    glVertex2f(5.8f,1.5f);
    glVertex2f(4.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 3
    glColor3ub( 106, 137, 112);
    glVertex2f(4.0f,-7.0f);
    glVertex2f(3.5f,-3.0f);
    glVertex2f(2.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 4
    glColor3ub( 106, 137, 112);
    glVertex2f(2.5f,-7.0f);
    glVertex2f(1.5f,-4.5f);
    glVertex2f(0.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 5

    glColor3ub( 106, 137, 112);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-1.5f,2.0f);
    glVertex2f(-3.0f,-7.0f);
    glEnd();


}



void hillR()
{


    glBegin(GL_TRIANGLES);// big hill 1
    glColor3ub( 139,35,35);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(7.0f,4.0f);
    glVertex2f(4.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// big hill 2
    glColor3ub( 139,35,35);
    glVertex2f(4.5f,-7.0f);
    glVertex2f(2.5f,2.0f);
    glVertex2f(0.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// big hill 3
    glColor3ub( 139,35,35);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-2.5f,3.0f);
    glVertex2f(-4.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// hill
    glColor3ub( 205,38,38);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(9.2f,0.0f);
    glVertex2f(8.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 1
    glColor3ub( 205,38,38);
    glVertex2f(8.5f,-7.0f);
    glVertex2f(7.5f,2.0f);
    glVertex2f(6.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 2
    glColor3ub( 205,38,38);
    glVertex2f(6.5f,-7.0f);
    glVertex2f(5.8f,1.5f);
    glVertex2f(4.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 3
    glColor3ub( 205,38,38);
    glVertex2f(4.0f,-7.0f);
    glVertex2f(3.5f,-3.0f);
    glVertex2f(2.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 4
    glColor3ub( 205,38,38);
    glVertex2f(2.5f,-7.0f);
    glVertex2f(1.5f,-4.5f);
    glVertex2f(0.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 5

    glColor3ub( 205,38,38);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-1.5f,2.0f);
    glVertex2f(-3.0f,-7.0f);
    glEnd();


}

void green_hill()
{


    glBegin(GL_TRIANGLES);// big hill 1
    glColor3ub(34,139,34);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(7.0f,4.0f);
    glVertex2f(4.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// big hill 2
    glColor3ub(34,139,34);
    glVertex2f(4.5f,-7.0f);
    glVertex2f(2.5f,2.0f);
    glVertex2f(0.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// big hill 3
    glColor3ub(34,139,34);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-2.5f,3.0f);
    glVertex2f(-4.0f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// hill
    glColor3ub(50,205,50);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(9.2f,0.0f);
    glVertex2f(8.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 1
    glColor3ub(50,205,50);
    glVertex2f(8.5f,-7.0f);
    glVertex2f(7.5f,2.0f);
    glVertex2f(6.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 2
    glColor3ub(50,205,50);
    glVertex2f(6.5f,-7.0f);
    glVertex2f(5.8f,1.5f);
    glVertex2f(4.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 3
    glColor3ub(50,205,50);
    glVertex2f(4.0f,-7.0f);
    glVertex2f(3.5f,-3.0f);
    glVertex2f(2.5f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 4
    glColor3ub(50,205,50);
    glVertex2f(2.5f,-7.0f);
    glVertex2f(1.5f,-4.5f);
    glVertex2f(0.0f,-7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// hill 5

    glColor3ub(50,205,50);
    glVertex2f(0.0f,-7.0f);
    glVertex2f(-1.5f,2.0f);
    glVertex2f(-3.0f,-7.0f);
    glEnd();


}


void tree()
{





    glBegin(GL_QUADS);// tr1
    glColor3ub( 139,69,19);
    glVertex2f(-3.4f,-7.0f);
    glVertex2f(-3.4f,-6.0f);
    glVertex2f(-3.2f,-6.0f);
    glVertex2f(-3.2f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// tr1
    glColor3ub( 0,100,0);
    glVertex2f(-4.0f,-6.1f);
    glVertex2f(-3.25f,-5.5f);
    glVertex2f(-2.5f,-6.1f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr1
    glColor3ub( 0,100,0);
    glVertex2f(-3.8f,-5.6f);
    glVertex2f(-3.25f,-5.1f);
    glVertex2f(-2.7f,-5.6f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr1
    glColor3ub( 0,100,0);
    glVertex2f(-3.6f,-5.2f);
    glVertex2f(-3.25f,-4.7f);
    glVertex2f(-2.9f,-5.2f);
    glEnd();




    glBegin(GL_QUADS);// tr2
    glColor3ub( 139,69,19);
    glVertex2f(-0.4f,-7.0f);
    glVertex2f(-0.4f,-6.0f);
    glVertex2f(-0.2f,-6.0f);
    glVertex2f(-0.2f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// tr2
    glColor3ub( 0,100,0);
    glVertex2f(-1.0f,-6.1f);
    glVertex2f(-0.25f,-5.5f);
    glVertex2f(0.5f,-6.1f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr2
    glColor3ub( 0,100,0);
    glVertex2f(-0.8f,-5.6f);
    glVertex2f(-0.25f,-5.1f);
    glVertex2f(0.3f,-5.6f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr2
    glColor3ub( 0,100,0);
    glVertex2f(-0.6f,-5.2f);
    glVertex2f(-0.25f,-4.7f);
    glVertex2f(0.1f,-5.2f);
    glEnd();



    glBegin(GL_QUADS);// tr3
    glColor3ub( 139,69,19);
    glVertex2f(2.2f,-7.0f);
    glVertex2f(2.2f,-6.0f);
    glVertex2f(2.4f,-6.0f);
    glVertex2f(2.4f,-7.0f);
    glEnd();



    glBegin(GL_TRIANGLES);// tr3
    glColor3ub( 0,100,0);
    glVertex2f(1.5f,-6.1f);
    glVertex2f(2.25f,-5.5f);
    glVertex2f(3.0f,-6.1f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr3
    glColor3ub( 0,100,0);
    glVertex2f(1.8f,-5.6f);
    glVertex2f(2.25f,-5.1f);
    glVertex2f(2.8f,-5.6f);
    glEnd();


    glBegin(GL_TRIANGLES);// tr3
    glColor3ub( 0,100,0);
    glVertex2f(1.9f,-5.2f);
    glVertex2f(2.25f,-4.7f);
    glVertex2f(2.6f,-5.2f);
    glEnd();



    glFlush();


}

void ground()
{

    glBegin(GL_QUADS);// GOURND
    glColor3ub( 205,79,57);
    glVertex2f(-10.0f,-7.0f);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(10.0f,-8.0f);
    glVertex2f(-10.0f,-8.0f);
    glEnd();
    glFlush();
}

void G_ground()
{

    glBegin(GL_QUADS);// GREEN GOURND
    glColor3ub( 0,139,69);
    glVertex2f(-10.0f,-7.0f);
    glVertex2f(10.0f,-7.0f);
    glVertex2f(10.0f,-8.0f);
    glVertex2f(-10.0f,-8.0f);
    glEnd();
    glFlush();
}
int screenWidth,screenHeight;
//void circle_one(float radius_x, float radius_y)
//{
//    int i = 0;
//    float angle1 = 0.0;
//
//    glBegin(GL_POLYGON);
//
//    for(i = 0; i < 100; i++)
//    {
//        angle1 = 2 * PI * i / 100;
//        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
//    }
//
//    glEnd();
//    glFlush();
//}


void sun_one() // sun
{

    glPushMatrix();
    glTranslated(-10,-8,0);
    glScaled(50,60,0);
    glColor3f( 1.0f, 1.0f,0.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();
    glFlush();
}
void earth_one() // earth
{

    glPushMatrix();
    glTranslated(-3.5,-3,0);
    glScaled(12,19,0);
    glColor3ub( 0, 100,0);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();
    glFlush();
}


void moon() // moon
{

    glPushMatrix();
    glTranslated(-2,-2.9,0);
    glScaled(5,7,0);
    glColor3f( 1.0f, 1.0f,1.0f);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();
    glFlush();
}


void mars_one() // mars
{

    glPushMatrix();
    glTranslated(3,2,0);
    glScaled(18,26,0);
    glColor3ub( 244,164,96);
    circle_one(.05,.05);
    glPopMatrix();
    glEnd();
    glFlush();
}

void satelite(){

glBegin(GL_QUADS);// satelite
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.5f, 2.0f);
      glVertex2f( -5.1f, 2.0f);
      glVertex2f( -5.1f,  1.5f);
      glVertex2f(-5.5f,  1.5f);
   glEnd();

   glBegin(GL_QUADS);// right 1
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.1f, 1.8f);
      glVertex2f( -4.9f, 1.8f);
      glVertex2f( -4.9f,  1.7f);
      glVertex2f(-5.1f,  1.7f);
   glEnd();

    glBegin(GL_QUADS);// right 1.1
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.0f, 1.9f);
      glVertex2f( -4.9f, 1.9f);
      glVertex2f( -4.9f,  1.6f);
      glVertex2f(-5.0f,  1.6f);
   glEnd();

     glBegin(GL_QUADS);// left 1
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.5f, 1.8f);
      glVertex2f( -5.7f, 1.8f);
      glVertex2f( -5.7f,  1.7f);
      glVertex2f(-5.5f,  1.7f);
   glEnd();

    glBegin(GL_QUADS);// left 1.1
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.6f, 1.9f);
      glVertex2f( -5.7f, 1.9f);
      glVertex2f( -5.7f,  1.6f);
      glVertex2f(-5.6f,  1.6f);
   glEnd();

      glBegin(GL_LINES);//1
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.4f, 2.0f);
      glVertex2f( -5.4f, 2.2f);
      glEnd();

        glBegin(GL_LINES);//2
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.2f, 2.0f);
      glVertex2f( -5.2f, 2.2f);
      glEnd();

      glBegin(GL_LINES);//3
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.4f, 1.5f);
      glVertex2f( -5.4f, 1.3f);
      glEnd();

       glBegin(GL_LINES);//4
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-5.2f, 1.5f);
      glVertex2f( -5.2f, 1.3f);
      glEnd();

      glFlush();

}


void display_first_console()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(2);
    sun_one();
    earth_one();
    moon();
    mars_one();
   satelite();
   rocket_one();
    glEnd();


    glFlush();


}

void displayNight()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(5);
    hill();
    hill1();

    if(cloud_one_visible == true)
    {
        cloud1();
    }
    if(cloud_two_visible == true)
    {
        cloud2();
    }
    if(cloud_three_visible == true)
    {
        cloud3();
    }

    if(green_hill_visible == true)
    {
        green_hill();
    }

    if (tree_visible == true)
    {
        tree();
    }

    rocket();


    if (building_visible == true)
    {
        building();
    }

    if (house_visible == true)
    {
        house();
    }


    if (sign_visible == true)
    {
        sign();
    }
    ground();
    if (green_ground_visible == true)
    {
        G_ground();
    }


    glEnd();
    glFlush();


}

void display()
{
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(5);
    hill();
    sun();
    hill();
    if(cloud_one_visible == true)
    {
        cloud1();
    }
    if(cloud_two_visible == true)
    {
        cloud2();
    }
    if(cloud_three_visible == true)
    {
        cloud3();
    }

    if(green_hill_visible == true)
    {
        green_hill();
    }

    if (tree_visible == true)
    {
        tree();
    }

    rocket();


    if (building_visible == true)
    {
        building();
    }

    if (house_visible == true)
    {
        house();
    }


    if (sign_visible == true)
    {
        sign();
    }
    ground();

    if (green_ground_visible == true)
    {
        G_ground();
    }
    glEnd();
    glFlush();


}






void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        speed = 0.0f;
        break;
    case 'f':
        speed = 0.3f;
        break;



    case 'n':
        glClearColor(0.0,0.0,0.0,1.0);
        glutPostRedisplay();
        glutDisplayFunc(displayNight);
        break;


    case 'd':
        glClearColor(0.0,0.0,0.0,1.0);
        glutPostRedisplay();
        glutDisplayFunc(display);
        break;


    //show sign
    case 's':
        sign_visible = true;
        break;
    case 'S':
        sign_visible = false;
        break;

    //show building
    case 'b':
        building_visible = true;
        break;
    case 'B':
        building_visible = false;
        break;

    //show house
    case 'h':
        house_visible = true;
        break;
    case 'H':
        house_visible = false;
        break;

    //show tree
    case 't':
        tree_visible = true;
        break;
    case 'T':
        tree_visible = false;
        break;

    //show green hill
    case 'm':
        green_hill_visible = true;
        break;
    case 'M':
        green_hill_visible = false;
        break;

    case 'z':
        cloud_one_visible = true;
        break;
    case 'x':
        cloud_two_visible = true;
        break;
    case 'c':
        cloud_three_visible = true;
        break;

    case 'g':
        green_ground_visible = true;
        break;


        glutPostRedisplay();
    }
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 0.1f;
    }
    glutPostRedisplay();
}



void init()
{
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-10,10,-8,8);//X axis from 10 to -10 and Y axis from 8 to -8
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display_first_console);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    //rocket first console
    glutTimerFunc(100, update3, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    init();

    glutMainLoop();
    return 0;
}
