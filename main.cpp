
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <windows.h>
#include <math.h>

//global variables
static double PI = acos(-1.0);
static int slices = 16;
static int stacks = 16;

//this is the code for the spinning action
static bool spinning = true;

//This is the number of frames per second to render.
static const int FPS = 60;
//the angle of rotation must be known
static GLfloat angleOfRotation=0.0;

static GLfloat vertical_angle=0.0;
static GLfloat horiz_angle=0.0;

// Clears the window and draws the tetrahedron.  The tetrahedron is  easily
// specified with a triangle strip, though the specification really isn't very
// easy to read.


//instantiate



//another function to be included in the reshapeFunction as a parameter
GLUquadricObj *obj = NULL;

static void idle(void)
{
    glutPostRedisplay();
}




void display() {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
glClearDepth(1.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  // Draw a white grid "floor" for the boulevard hall  to sit on.
  glColor3f(1.0, 0, 0);
  glBegin(GL_LINES);
    glColor3f(1.0, 0, 0);
  for (GLfloat i = -3.5; i <= 2.5; i += 0.25) {
    glColor3f(0, 1.0, 1.0); glVertex3f(i, 0, 2.5);
    glColor3f(1.0, 0, 1.0);glVertex3f(i, 0, -3.5);
    glColor3f(1.0, 1.0, 0);glVertex3f(2.5, 0, i);
    glColor3f(0, 1.0, 1.0);glVertex3f(-3.5, 0, i);
  }
  glEnd();
glBegin(GL_QUADS);
        glColor3f(0, 1, 1);glVertex3f(-0.95,0,0.12);
        glColor3f(0, 0, 0);glVertex3f(-0.65,0,0.21);
        glColor3f(1, 0, 0);glVertex3f(-0.65,2.1,0.21);
        glColor3f(1, 0, 1);glVertex3f(-0.95,2.1,0.12);
glEnd();

// THE FRONT
//THE STAIRS
//the curb to the entrance

glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(-1.95, 0.1,0.5);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(1.95, 0.1,0.5);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(1.95, 0.1,0.21);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(-1.95, 0.1,0.21);
  glEnd();

glBegin(GL_QUADS);
    glColor3f(1, 0, 1); glVertex3f(-1.95, 0,0.6);
    glColor3f(1, 1, 1); glVertex3f(-1.95, 0,1);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0,01);
    glColor3f(0, 0, 1); glVertex3f(1.95,0,0.6);
  glEnd();
//the fist stair
glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(-1.95, 0.08,0.6);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(1.95, 0.08,0.6);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(1.95, 0.1,0.6);
    glColor3f(0.8, 0.8, 0.8); glVertex3f(-1.95, 0.1,0.6);
  glEnd();
//the second stair
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-1.95, 0.08,0.7);
    glColor3f(1, 1, 1); glVertex3f(1.95, 0.08,0.7);
    glColor3f(1, 1, 1); glVertex3f(1.95, 0.08,0.6);
    glColor3f(1, 1, 1); glVertex3f(-1.95, 0.08,0.6);
  glEnd();
//the second stair
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-1.95, 0.06,0.7);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0.06,0.7);
    glColor3f(0, 1, 0); glVertex3f(1.95, 0.08,0.7);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.08,0.7);
  glEnd();
//the third stair downward
glBegin(GL_QUADS);
    glColor3f(0, 0, 0); glVertex3f(-1.95, 0.04,0.8);
    glColor3f(0, 0, 0); glVertex3f(1.95, 0.04,0.8);
    glColor3f(0, 0, 0); glVertex3f(1.95, 0.06,0.7);
    glColor3f(0, 0, 0); glVertex3f(-1.95, 0.06,0.7);
  glEnd();
//the third stair frontwards
glBegin(GL_QUADS);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.8);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0.04,0.8);
    glColor3f(0, 1, 0); glVertex3f(1.95, 0.04,0.8);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.8);
  glEnd();
//
glBegin(GL_QUADS);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.9);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0.04,0.9);
    glColor3f(0, 1, 0); glVertex3f(1.95, 0.04,0.8);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.8);
  glEnd();
//the fourth stair downwards
//
glBegin(GL_QUADS);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.9);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0.04,0.9);
    glColor3f(0, 1, 0); glVertex3f(1.95, 0.04,0.9);
    glColor3f(0, 0, 1); glVertex3f(-1.95, 0.04,0.9);
  glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 1, 1); glVertex3f(-1.95, 0.02,1.0);
    glColor3f(1, 0, 1); glVertex3f(1.95, 0.02,1.0);
    glColor3f(0, 1, 0); glVertex3f(1.95, 0.04,0.9);
    glColor3f(1, 0, 0); glVertex3f(-1.95, 0.04,0.9);
  glEnd();
//the fifth stair downwards
glBegin(GL_QUADS);
    glColor3f(1, 1, 0); glVertex3f(-1.95, 0.0,1.0);
    glColor3f(1, 1, 0); glVertex3f(1.95, 0.0,1.0);
    glColor3f(1, 1, 0); glVertex3f(1.95, 0.02,1.0);
    glColor3f(1, 1, 0); glVertex3f(-1.95, 0.02,1.0);
  glEnd();
//the fifth stair frontwards
glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0); glVertex3f(-1.95, 0.0,1.0);
    glColor3f(1, 0.5, 0); glVertex3f(1.95, 0.0,1.0);
    glColor3f(1, 0.5, 0); glVertex3f(1.95, 0.0,0.9);
    glColor3f(1, 0.5, 0); glVertex3f(-1.95, 0.0,0.9);
  glEnd();


//THE FLOORS
//the FIRST FLOOR
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 0.6,0);
    glColor3f(1, 0, 1); glVertex3f(0.5, 0.6,0);
    glColor3f(0, 1, 0); glVertex3f(0.5, 0.65,0);
    glColor3f(0, 0, 1); glVertex3f(-0.5, 0.65,0);
  glEnd();

//the SECOND floor
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 0.3,0);
    glColor3f(1, 0, 1); glVertex3f(0.5, 0.3,0);
    glColor3f(0, 1, 0); glVertex3f(0.5, 0.35,0);
    glColor3f(0, 0, 1); glVertex3f(-0.5, 0.35,0);
  glEnd();
//the SECOND floor
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 1.2,0);
    glColor3f(1, 0, 1); glVertex3f(0.5, 1.2,0);
    glColor3f(0, 1, 0); glVertex3f(0.5, 1.25,0);
    glColor3f(0, 0, 1); glVertex3f(-0.5, 1.25,0);
  glEnd();
//the THIRD floor
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 1.5,0);
    glColor3f(1, 0, 1); glVertex3f(0.5, 1.5,0);
    glColor3f(0, 1, 0); glVertex3f(0.5, 1.55,0);
    glColor3f(0, 0, 1); glVertex3f(-0.5, 1.55,0);
  glEnd();
//the THIRD floor
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 1.95,0);
    glColor3f(1, 0, 1); glVertex3f(0.5, 1.95,0);
    glColor3f(0, 1, 0); glVertex3f(0.5, 2.0,0);
    glColor3f(0, 0, 1); glVertex3f(-0.5, 2.0,0);
  glEnd();
//drawing the top part that extends the backward plane to extend to the front where the elevators are located
glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(0.60, 0.8, -2.8);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.60, 0.8, -2.8);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.95, 2.15, -1.2);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(0.95, 2.15, -1.2);
  glEnd();
//the top front part that extends from the back
glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.95, 2.0, 0);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(0.95, 2.0, 0);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(0.95, 2.0, -1.2);
    glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.95, 2.0, -1.2);
  glEnd();
//the plane covering the top front ,
glBegin(GL_QUADS);
        glColor3f(0.0, 0.5, 0.5); glVertex3f(-0.5,1.95,0);
        glColor3f(0.0, 0.5, 0.5);glVertex3f(0.5,1.95,0);
        glColor3f(0.0, 0.5, 0.5);glVertex3f(0.5,1.95,0);
        glColor3f(0.0, 0.5, 0.5);glVertex3f(-0.5,1.95,0);
glEnd();
//the top plane part after the back side near the front
glBegin(GL_QUADS);
        glColor3f(0,1,0.7); glVertex3f(-0.95,1.95,0);
        glColor3f(0,1,0.2);glVertex3f(0.95,1.95,0);
        glColor3f(0.8,0.9,0.7);glVertex3f(0.6,1.95,0);
        glColor3f(0.11,0.45,1);glVertex3f(-0.6,1.95,0);
glEnd();
//THE LEFT SIDE
//the top part where y is extended, top of the pillar on top of the elevator at the left side
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.80,2.1,-0.1);
        glColor3f(1, 1, 1);glVertex3f(-0.95,2.1,0.12);
        glColor3f(1, 0, 1);glVertex3f(-0.65,2.1,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.5,2.1,-0.057);
glEnd();
//the part after the roof of the elevator
glBegin(GL_QUADS);
        glColor3f(0,1,0.7); glVertex3f(-1.2,1.95,0);
        glColor3f(0,1,0.2);glVertex3f(-0.80,1.95,0);
        glColor3f(0.8,0.9,0.7);glVertex3f(-0.80,1.95,0);
        glColor3f(0.11,0.45,1);glVertex3f(-1.2,1.95,0);
glEnd();
//the back left side after the roof
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(-1.2,1.95,-0.5);
        glColor3f(0,1,0);glVertex3f(-1.2,1.95,0);
        glColor3f(0,0,1);glVertex3f(-1.2,1.95,0);
        glColor3f(1,0,1);glVertex3f(-1.2,1.95,-0.5);
    glEnd();
//THE FRONT LEFT
//THE LEFT ELEVATOR
//the lower base where the y should be extrapolated from- the left plane covering the pillar from the base to the top
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.80,0,-0.1);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0,0.12);
        glColor3f(1, 0, 1);glVertex3f(-0.65,0,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.5,0,-0.057);
glEnd();
//the other side of the left pillar of the left elevator from the lower to the top
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.80,0,-0.1);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.95,0,0.12);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.95,2.1,0.12);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.80,2.1,-0.1);
glEnd();
// the front part of the left elevator
glBegin(GL_QUADS);
        glColor3f(0, 1, 1);glVertex3f(-0.95,0,0.12);
        glColor3f(0, 0, 0);glVertex3f(-0.65,0,0.21);
        glColor3f(1, 0, 0);glVertex3f(-0.65,2.1,0.21);
        glColor3f(1, 0, 1);glVertex3f(-0.95,2.1,0.12);
glEnd();
//the lines upwards and downwards
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.95,0.12);

        glColor3f(1, 1, 1);glVertex3f(-0.85,0.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.85,1.95,0.12);

        glColor3f(1, 1, 1);glVertex3f(-0.75,0.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.75,1.95,0.12);

        glColor3f(1, 1, 1);glVertex3f(-0.65,0.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.95,0.12);
glEnd();
//the lines of the front sideways
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.15,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.15,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.15,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.25,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.25,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.25,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.25,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.35,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.35,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.35,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.35,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.45,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.45,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.45,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.45,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.55,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.55,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.55,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.55,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.65,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.65,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.65,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.65,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.75,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.75,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.75,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.75,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.85,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.85,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.85,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.85,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.95,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.95,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,0.95,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,0.95,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.05,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.05,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.05,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.05,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.15,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.15,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.15,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.15,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.25,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.25,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.25,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.25,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.35,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.35,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.35,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.35,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.45,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.45,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.45,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.45,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.55,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.55,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.55,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.55,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.65,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.65,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.65,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.65,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.75,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.75,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.75,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.75,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.85,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.85,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.85,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.85,0.12);
glEnd();
glBegin(GL_LINES);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.95,0.12);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.95,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.65,1.95,0.21);
        glColor3f(1, 1, 1);glVertex3f(-0.95,1.95,0.12);
glEnd();
//THE MIDDLE FLOWERR HOLDER
//the front flower holder
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.20,0,1.0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.15,0,1.0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.15,0.15,1.0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.20,0.15,1.0);
glEnd();
//the back part of the middle flower holder that is near the entrance
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0,0.5);
        glColor3f(1, 0, 1);glVertex3f(0.15,0,0.5);
        glColor3f(1, 0, 1);glVertex3f(0.15,0.15,0.5);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0,0.5);
        glColor3f(0, 1, 1);glVertex3f(-0.20,0,1);
        glColor3f(0, 1, 1);glVertex3f(0.15,0,1);
        glColor3f(0, 0, 1);glVertex3f(0.15,0,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0.15,0.5);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0.15,1);
        glColor3f(1, 0, 1);glVertex3f(0.15,0.15,1);
        glColor3f(1, 0, 1);glVertex3f(0.15,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0,0.5);
        glColor3f(0, 1, 1);glVertex3f(-0.20,0,1);
        glColor3f(0, 1, 1);glVertex3f(-0.20,0.15,1);
        glColor3f(1, 0, 1);glVertex3f(-0.20,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(0, 1, 1);glVertex3f(0.15,0.15,1);
        glColor3f(0, 0, 1);glVertex3f(0.15,0,1);
        glColor3f(0, 1, 1);glVertex3f(0.15,0,0.5);
        glColor3f(0, 0, 1);glVertex3f(0.15,0.15,0.5);
glEnd();
//the new front  LEFT
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-1.45,0,0.5);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-1.15,0,0.5);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-1.15,0.15,0.5);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-1.45,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.75,0,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.75,0.15,1.0);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(-1.75,0,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0.15,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.75,0.15,1.0);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-1.75,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(-1.45,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(-1.15,0.15,0.5);
        glColor3f(1, 0, 1);glVertex3f(-1.45,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0.15,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.45,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.15,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.15,0.150,0.5);
glEnd();
//the back of the flower holder LEFT
glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);glVertex3f(-2.05,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.8,0.15,1.0);
        glColor3f(1, 1, 1);glVertex3f(-1.7,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(-2.05,0.0,0.5);
        glColor3f(1, 0, 1);glVertex3f(-1.8,0.0,1.0);
        glColor3f(1, 0, 1);glVertex3f(-1.8,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(-2.05,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 0);glVertex3f(-1.7,0.15,1.0);
        glColor3f(1, 1, 0);glVertex3f(-2.05,0.15,0.5);
        glColor3f(1, 1, 0);glVertex3f(-2.05,0.0,0.5);
        glColor3f(1, 1, 0);glVertex3f(-1.7,0.0,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(-1.8,0.15,1);
        glColor3f(1, 1, 1);glVertex3f(-1.8,0.0,1);
        glColor3f(1, 1, 1);glVertex3f(-1.7,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(-1.7,0.15,0.5);
glEnd();
//the right of the left pillar the left pillar side carrying the elevator
glBegin(GL_QUADS);
        glColor3f(0, 1, 0.7);glVertex3f(-0.65,0,0.21);
        glColor3f(0, 1, 0.2);glVertex3f(-0.5,0,-0.1);
        glColor3f(0.8, 0.9, 0.7);glVertex3f(-0.5,2.1,-0.1);
        glColor3f(0.11, 0.45, 1);glVertex3f(-0.65,2.1,0.21);
glEnd();
// the part beyond the left elevator
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8); glVertex3f(-1.2,0,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.88,0,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-0.88,2.0,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(-1.2,2.0,0);
    glEnd();
//the left side extending from the left elevator towards the back
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(-1.2,0,-0.6);
        glColor3f(0,1,0);glVertex3f(-1.2,0,0);
        glColor3f(0,0,1);glVertex3f(-1.2,2.0,0);
        glColor3f(1,0,1);glVertex3f(-1.2,2.0,-0.6);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,0.5,0); glVertex3f(-1.35,0,-0.6);
        glColor3f(1,0.5,0);glVertex3f(-1.35,0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(-1.35,2.0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(-1.35,2.0,-0.6);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(-1.2,2.0,-0.6);
        glColor3f(0,1,1);glVertex3f(-1.35,2.0,-0.6);
        glColor3f(0,1,1);glVertex3f(-1.35,2.0,-0.3);
        glColor3f(0,1,1);glVertex3f(-1.2,2.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,0.5,0); glVertex3f(-1.35,0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(-1.2,0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(-1.2,2.0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(-1.35,2.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(-1.20,0,-0.5);
        glColor3f(0,1,1);glVertex3f(-1.35,0,-0.5);
        glColor3f(0,1,1);glVertex3f(-1.35,2.0,-0.5);
        glColor3f(0,1,1);glVertex3f(-1.20,2.0,-0.5);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,01,0); glVertex3f(-1.45,1.5,-0.58);
        glColor3f(1,01,0);glVertex3f(-1.45,1.5,-0.32);
        glColor3f(1,01,0);glVertex3f(-1.45,2.0,-0.32);
        glColor3f(1,01,0);glVertex3f(-1.45,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,01,0);glVertex3f(-1.35,1.5,-0.58);
        glColor3f(1,01,0); glVertex3f(-1.45,1.5,-0.58);
        glColor3f(1,01,0);glVertex3f(-1.45,2.0,-0.58);
        glColor3f(1,01,0);glVertex3f(-1.35,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,01,0);glVertex3f(-1.35,2.0,-0.58);
        glColor3f(1,01,0); glVertex3f(-1.45,2.0,-0.58);
        glColor3f(1,01,0);glVertex3f(-1.45,2.0,-0.32);
        glColor3f(1,01,0);glVertex3f(-1.35,2.0,-0.32);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,01,0); glVertex3f(-1.45,1.5,-0.58);
        glColor3f(1,01,0);glVertex3f(-1.35,1.5,-0.32);
        glColor3f(1,01,0);glVertex3f(-1.35,2.0,-0.32);
        glColor3f(1,01,0);glVertex3f(-1.45,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,01,0); glVertex3f(-1.45,1.5,-0.32);
        glColor3f(0,01,0);glVertex3f(-1.35,1.5,-0.32);
        glColor3f(0,01,0);glVertex3f(-1.35,2.0,-0.32);
        glColor3f(0,01,0);glVertex3f(-1.45,2.0,-0.32);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,0.5,0);glVertex3f(-0.6,0,-2.9);
        glColor3f(1,0.5,0); glVertex3f(-1.20,0,-0.6);
        glColor3f(1,0.5,0); glVertex3f(-1.20,2.0,-0.6);
        glColor3f(1,0.5,0);glVertex3f(-0.6,0.8,-2.9);
    glEnd();
//the sideways extension from front
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(-1.03,0,-0.35);
        glColor3f(0,1,0);glVertex3f(-1.03,0,-0.30);
        glColor3f(0,0,1);glVertex3f(-1.0,0,-0.30);
        glColor3f(1,0,1);glVertex3f(-1.0,2.0,-0.30);
        glColor3f(1,0,1);glVertex3f(-1.03,2.0,-0.30);
        glColor3f(1,0,1);glVertex3f(-1.03,2.0,-0.35);
    glEnd();
//THEs RIGHT SIDE
//the right pillar carrying the elevators from the base
glBegin(GL_QUADS);
        glColor3f(0.3,1,0.7); glVertex3f(0.5,0,-0.057);
        glColor3f(0.8,0.3,0.2);glVertex3f(0.65,0,0.21);
        glColor3f(0.8,0.9,0.7);glVertex3f(0.95,0,0.12);
        glColor3f(0.66,0.45,0.7);glVertex3f(0.8,0,-0.1);
    glEnd();
//the lines running from the side to side
glBegin(GL_LINES);

        glColor3f(1,1,1);glVertex3f(0.65,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.15,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.25,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.25,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.35,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.35,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.45,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.45,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.55,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.55,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.65,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.65,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.75,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.75,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.85,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.85,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,0.95,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,0.95,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.05,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.05,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.15,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.25,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.25,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.35,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.35,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.45,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.45,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.55,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.55,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.65,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.65,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.75,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.75,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.85,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.85,0.12);

        glColor3f(1,1,1);glVertex3f(0.65,1.95,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.95,0.12);
    glEnd();
//the right elevator pillar on the top
glBegin(GL_QUADS);
        glColor3f(0.3,0.8,0.7); glVertex3f(0.5,2.1,-0.057);
        glColor3f(0.6,0.5,0.2);glVertex3f(0.65,2.1,0.21);
        glColor3f(0.3,0.9,0.7);glVertex3f(0.95,2.1,0.12);
        glColor3f(0.4,0.8,0.1);glVertex3f(0.80,2.1,-0.1);
    glEnd();
//the left wall of the right pillar carrying the elevator
glBegin(GL_QUADS);
        glColor3f(0,1,0.7); glVertex3f(0.5,0,-0.057);
        glColor3f(0,1,0.2);glVertex3f(0.65,0,0.21);
        glColor3f(0.8,0.9,0.7);glVertex3f(0.65,2.1,0.21);
        glColor3f(0.11,0.45,1);glVertex3f(0.5,2.1,-0.057);
    glEnd();

// the front side of the pillar carrying the right elevator
glBegin(GL_QUADS);
        glColor3f(0,1,0.7); glVertex3f(0.65,0,0.21);
        glColor3f(1,1,0.2);glVertex3f(0.95,0,0.12);
        glColor3f(1,0.9,0.7);glVertex3f(0.95,2.1,0.12);
        glColor3f(1,0.1,1);glVertex3f(0.65,2.1,0.21);
    glEnd();
//the lines running from the top to down
glBegin(GL_LINES);
        glColor3f(1,1,1); glVertex3f(0.65,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.65,1.95,0.21);

        glColor3f(1,1,1); glVertex3f(0.75,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.75,1.95,0.21);

        glColor3f(1,1,1); glVertex3f(0.85,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.85,1.95,0.21);

        glColor3f(1,1,1); glVertex3f(0.95,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.95,1.95,0.21);

        glColor3f(1,1,1); glVertex3f(0.65,0.15,0.21);
        glColor3f(1,1,1);glVertex3f(0.65,1.95,0.21);
    glEnd();
//the right side of the right elevator
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8); glVertex3f(0.95,0,0.12);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.80,0,-0.1);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.80,2.1,-0.1);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.95,2.1,0.12);
    glEnd();
//the part after the elevator
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8); glVertex3f(0.88,0,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(1.2,0,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(1.2,1.95,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.88,1.95,0);
    glEnd();
//the frieze of the part after the elevator
glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8); glVertex3f(0.88,1.45,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(1.2,1.45,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(1.2,1.95,0);
        glColor3f(0.8, 0.8, 0.8);glVertex3f(0.88,1.95,0);
    glEnd();
//the part backwards from the  right part of the elevator that extends from the front beyond
glBegin(GL_QUADS);
        glColor3f(0,0.1,1); glVertex3f(1.2,0,0);
        glColor3f(0,0.1,1);glVertex3f(1.2,0,-0.6);
        glColor3f(1,0.1,1);glVertex3f(1.2,2.0,-0.6);
        glColor3f(1,0.1,1);glVertex3f(1.2,2.0,0);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,0.1,1); glVertex3f(1.35,0,-0.6);
        glColor3f(0,0.1,1);glVertex3f(1.2,0,-0.6);
        glColor3f(1,0.1,1);glVertex3f(1.2,2.0,-0.6);
        glColor3f(1,0.1,1);glVertex3f(1.35,2.0,-0.6);
    glEnd();
//the frieze that extends backwards
glBegin(GL_QUADS);
        glColor3f(0.9,1,1); glVertex3f(1.2,0.0,0.0);
        glColor3f(0.6,1,1);glVertex3f(1.2,0.0,-0.6);
        glColor3f(0.2,0.1,1);glVertex3f(1.2,2.0,-0.6);
        glColor3f(0.6,1,0.7);glVertex3f(1.2,2.0,0);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0.9,1,1); glVertex3f(1.2,0.0,-0.3);
        glColor3f(0.6,1,1);glVertex3f(1.35,0.0,-0.3);
        glColor3f(0.6,1,1);glVertex3f(1.35,2.0,-0.3);
        glColor3f(0.6,1,0.7);glVertex3f(1.2,2.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,0.5,0); glVertex3f(1.2,2.0,-0.3);
        glColor3f(0,0.5,0);glVertex3f(1.35,2.0,-0.3);
        glColor3f(0,0.5,0);glVertex3f(1.35,2.0,-0.6);
        glColor3f(0,0.5,0);glVertex3f(1.2,2.0,-0.6);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,0.5,0); glVertex3f(1.35,0.0,-0.3);
        glColor3f(1,0.5,0);glVertex3f(1.35,0.0,-0.6);
        glColor3f(1,0.5,0); glVertex3f(1.35,2.0,-0.6);
        glColor3f(1,0.5,0);glVertex3f(1.35,2.0,-0.3);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0,1,1); glVertex3f(1.45,1.50,-0.32);
        glColor3f(0,1,1);glVertex3f(1.45,1.50,-0.58);
        glColor3f(0,1,1);glVertex3f(1.45,2.0,-0.58);
        glColor3f(0,1,1);glVertex3f(1.45,2.0,-0.32);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(1,0.5,0); glVertex3f(1.45,1.5,-0.58);
        glColor3f(1,0.5,0);glVertex3f(1.35,1.5,-0.58);
        glColor3f(1,0.5,0);glVertex3f(1.35,2.0,-0.58);
        glColor3f(1,0.5,0);glVertex3f(1.45,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0.6,1,1);glVertex3f(1.35,1.5,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.45,1.5,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.45,2.0,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.35,2.0,-0.32);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0.6,1,1);glVertex3f(1.35,2.0,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.45,2.0,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.45,2.0,-0.58);
        glColor3f(0.6,1,1);glVertex3f(1.35,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
        glColor3f(0.6,1,1);glVertex3f(1.45,1.5,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.35,1.5,-0.32);
        glColor3f(0.6,1,1);glVertex3f(1.35,2.0,-0.58);
        glColor3f(0.6,1,1);glVertex3f(1.45,2.0,-0.58);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1,0.5,0); glVertex3f(1.2,0,-0.6);
    glColor3f(1,0.5,0); glVertex3f(0.6,0,-2.8);
    glColor3f(1,0.5,0); glVertex3f(0.6,0.8,-2.8);
    glColor3f(1,0.5,0); glVertex3f(1.2,2.0,-0.6);
glBegin(GL_QUADS);
    glColor3f(1,0.5,0); glVertex3f(1.0,0,-1.5);
    glColor3f(1,0.5,0); glVertex3f(1.,0,-2.0);
    glColor3f(1,0.5,0); glVertex3f(0.6,0,-2.0);
glEnd();

//the flower garden holding the trees to the far right
glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 1);glVertex3f(1.45,0.15,0.5);
        glColor3f(1, 0, 1);glVertex3f(1.65,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(1.75,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(1.75,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.45,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.45,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.75,0.0,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(1.45,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.65,0.15,1.0);
        glColor3f(1, 1, 1);glVertex3f(1.65,0.0,1.0);
        glColor3f(1, 1, 1);glVertex3f(1.45,0.0,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1,1,1);glVertex3f(1.65,0.0,1.0);
        glColor3f(1,1,1);glVertex3f(1.75,0.0,0.5);
        glColor3f(1,1,1);glVertex3f(1.65,0.0,1.0);
        glColor3f(1,1,1);glVertex3f(1.45,0.0,0.5);
glEnd();
//the front of the flower holders
glBegin(GL_QUADS);
        glColor3f(5,5,5);glVertex3f(1.25,0.0,1.0);
        glColor3f(5,5,5);glVertex3f(1.55,0.0,1.0);
        glColor3f(5,5,5);glVertex3f(1.55,0.15,1.0);
        glColor3f(5,5,5);glVertex3f(1.25,0.15,1.0);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0, 1);glVertex3f(1.25,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(1.55,0.15,1.0);
        glColor3f(1, 0, 1);glVertex3f(1.25,0.15,0.5);
        glColor3f(1, 0, 1);glVertex3f(0.9,0.15,0.5);
glEnd();

//the back of the flower holder of the right side
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(1.15,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(0.9,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(0.9,0.15,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.15,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 1, 1);glVertex3f(0.9,0.0,0.5);
        glColor3f(1, 1, 1);glVertex3f(1.25,0.0,1.0);
        glColor3f(1, 1, 1);glVertex3f(1.25,0.15,1.0);
        glColor3f(1, 1, 1);glVertex3f(0.9,0.15,0.5);
glEnd();
glBegin(GL_QUADS);
        glColor3f(1, 0.5, 0);glVertex3f(1.55,0.0,1.0);
        glColor3f(1, 0.5, 0);glVertex3f(1.15,0.0,0.5);
        glColor3f(1, 0.5, 0);glVertex3f(1.15,0.15,0.5);
        glColor3f(1, 0.5, 0);glVertex3f(1.55,0.15,1.0);
glEnd();


//THE BACK SIDE
//the bigger surface area
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0, -2.8);
    glColor3f(1, 0, 1); glVertex3f(-0.6, 0, -2.8);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.8);
    glColor3f(1, 0, 1); glVertex3f(0.6, 0.8, -2.8);
  glEnd();

  //the right joint
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0, -2.8);
    glColor3f(1, 0, 1); glVertex3f(0.6, 0, -2.9);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0.8, -2.9);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0.8, -2.8);
  glEnd();

//the top
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0.8, -2.8);
    glColor3f(1, 0, 1); glVertex3f(0.6, 0.8, -2.9);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.9);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.8);
  glEnd();

  //the left joint
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0, -2.9);
    glColor3f(1, 0, 1); glVertex3f(-0.6, 0, -2.8);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.8);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.9);
  glEnd();

//the first extension
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0, -2.9);
    glColor3f(1, 0, 1); glVertex3f(-0.6, 0, -2.9);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.9);
    glColor3f(1, 0, 1); glVertex3f(0.6, 0.8, -2.9);
  glEnd();

  //
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.6, 0, -2.9);
    glColor3f(1, 0, 1); glVertex3f(-0.6, 0, -2.9);
    glColor3f(1, 1, 1); glVertex3f(-0.6, 0.8, -2.9);
    glColor3f(1, 0, 1); glVertex3f(0.6, 0.8, -2.9);
  glEnd();

  //the back extension bottom from the wider area
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0, -3);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0, -3.1);
    glColor3f(1, 1, 0); glVertex3f(0.5, 0.8, -3.1);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0.8, -3);
  glEnd();

  //the right extension wall
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 0, -3);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 0, -3.1);
    glColor3f(1, 1, 0); glVertex3f(-0.5, 0.8, -3.1);
    glColor3f(1, 1, 1); glVertex3f(-0.5, 0.8, -3);
  glEnd();

  //the right side of the back of the second extension
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0.0, -3.0);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0.0, -3.0);
    glColor3f(1, 1, 0); glVertex3f(0.5, 0.0, -3.1);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0.0, -3.1);
  glEnd();

  //the left side of the second extension bottom
  glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-0.5, 0.0, -3.1);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-0.5, 0.0, -2.9);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(0.5, 0.0, -2.9);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(0.5, 0.0, -3.1);
  glEnd();


  //the top
  glBegin(GL_QUADS);
    glColor3f(227, 227, 227); glVertex3f(-0.5, 0.8, -3.1);
    glColor3f(227, 227, 227); glVertex3f(-0.5, 0.8, -2.9);
    glColor3f(227, 227, 227); glVertex3f(0.5, 0.8, -2.9);
    glColor3f(227, 227, 227); glVertex3f(0.5, 0.8, -3.1);
  glEnd();

  //the wall of the back
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0, -3.1);
    glColor3f(1, 0, 1); glVertex3f(-0.5, 0, -3.1);
    glColor3f(0, 1, 0); glVertex3f(-0.5, 0.8, -3.1);
    glColor3f(0, 1, 1); glVertex3f(0.5, 0.8, -3.1);
  glEnd();

//the right wall of the first extension
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.5, 0, -2.9);
    glColor3f(1, 0, 1); glVertex3f(0.5, 0, -3.1);
    glColor3f(0, 1, 0); glVertex3f(0.5, 0.8, -3.1);
    glColor3f(0, 1, 1); glVertex3f(0.5, 0.8, -2.9);
  glEnd();


//the second extension from the first one, the bottom
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.3, 0, -3.1);
    glColor3f(1, 0, 1); glVertex3f(0.3, 0, -3.2);
    glColor3f(1, 1, 0); glVertex3f(-0.3, 0, -3.2);
    glColor3f(1, 0, 1); glVertex3f(-0.3, 0, -3.1);
  glEnd();

  //the right side third extension wall
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.3, 0, -3.1);
    glColor3f(1, 0, 1); glVertex3f(0.3, 0, -3.2);
    glColor3f(0, 1, 0); glVertex3f(0.3, 0.8, -3.2);
    glColor3f(0, 0, 1); glVertex3f(0.3, 0.8, -3.1);
  glEnd();

  //the left side of the third extension
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.3, 0, -3.2);
    glColor3f(1, 0, 1); glVertex3f(-0.3, 0, -3.1);
    glColor3f(0, 1, 0); glVertex3f(-0.3, 0.8, -3.1);
    glColor3f(1, 1, 1); glVertex3f(-0.3, 0.8, -3.2);
  glEnd();
  //the second extension joining the roof of the back; the top
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.3, 0.8, -3.1);
    glColor3f(1, 0, 1); glVertex3f(0.3, 0.8, -3.2);
    glColor3f(1, 1, 0); glVertex3f(-0.3, 0.8, -3.2);
    glColor3f(1, 1, 1); glVertex3f(-0.3, 0.8, -3.1);
  glEnd();
  //the roof to the bottom
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.3, 0, -3.2);
    glColor3f(1, 1, 1); glVertex3f(-0.3, 0, -3.2);
    glColor3f(0, 1, 0); glVertex3f(-0.3, 0.8, -3.2);
    glColor3f(1, 0, 1); glVertex3f(0.3, 0.8, -3.2);
  glEnd();
//the frieze from the right side bigger than the second extension top
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(0.3, 0.8, -3.1);
    glColor3f(1, 0, 1); glVertex3f(0.3, 0, -3.1);
    glColor3f(0, 1, 0); glVertex3f(0.3, 0, -3.2);
    glColor3f(0, 0, 1); glVertex3f(0.3, 0.8, -3.2);
  glEnd();

//the freeze of the left side joining the roof top
//the frieze from the right side bigger than the second extension top
glBegin(GL_QUADS);
    glColor3f(1, 1, 1); glVertex3f(-0.4, 0, -3.2);
    glColor3f(1, 0, 1); glVertex3f(-0.4, 0, -3.1);
    glColor3f(0, 1, 0); glVertex3f(-0.4, 0.8, -3.1);
    glColor3f(0, 0, 1); glVertex3f(-0.4, 0.8, -3.2);
  glEnd();
 //the frieze to hold the plane perpendicular to the first extension from left side back
  glBegin(GL_QUADS);
    glColor3f(188, 205, 207); glVertex3f(-0.5, 0, -3.1);
    glColor3f(188, 205, 207); glVertex3f(-0.5, 0, -2.9);
    glColor3f(188, 205, 207); glVertex3f(-0.5, 0.8, -2.9);
    glColor3f(188, 205, 207); glVertex3f(-0.5, 0.8, -3.1);
  glEnd();
  glFlush();
  glutSwapBuffers();
}


// Sets up global attributes like clear color and drawing color, enables and
// initializes any needed modes (in this case we want backfaces culled), and
// sets up the desired projection and modelview matrices. It is cleaner to
// define these operations in a function separate from main().
void init() {


  // Set the current clear color to sky blue and the current drawing color to
  // white.

//glClearColor(0.1, 0.39, 0.88, 1.0);
  glColor3f(1.0, 1.0, 1.0);
  glShadeModel(GL_FLAT);
  //RenderState* rsp= new RenderState();
  //rs=*rsp;
  glCullFace(GL_BACK);
   glEnable(GL_DEPTH_TEST);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(vertical_angle, 1, 0, 0);
glRotatef(horiz_angle, 0, 1, 0);

  // Tell the rendering engine not to draw backfaces.  Without this code,rs
  // all four faces of the tetrahedron would be drawn and it is possible
  // that faces farther away could be drawn after nearer to the viewer.
  // Since there is only one closed polyhedron in the whole scene,
  // eliminating the drawing of backfaces gives us the realism we need.
  // THIS DOES NOT WORK IN GENERAL.
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  // Set the camera lens so that we have a perspective viewing volume whose
  // horizontal bounds at the near clipping plane are -2..2 and vertical
  // bounds are -1.5..1.5.  The near clipping plane is 1 unit from the camera
  // and the far clipping plane is 40 units away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(0, 0.5, 0, 1.5, 1, 30);

    //glScalef (2.0, 4.0, 6.0);
//this helps us to watch from the right side of the camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, 4.0/3.0, 1, 40);//the first parameter specifies the camera view and distance of the object
  //Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  //<0, 1, 0> pointing upward.

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, -1,1, 0, 3, 0, 0, 1, 0);

}

//instantiating the function fir the motion callback

//the resize function to adjust the shape of the object when the screen size is adjusted
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}


// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Boulevard Hall");
    glutDisplayFunc(display);
    glDepthFunc(GL_LESS);

    init();
    //glutTimerFunc(100, timer, 0);
    glutIdleFunc(idle);
    //glutMouseFunc();
    //glutMotionFunc();
    //glDepthFunc();
    //glClearColor(1,1,1,1);



    glutMainLoop();
}

