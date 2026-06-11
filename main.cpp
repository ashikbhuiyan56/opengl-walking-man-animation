complete project
#include <GL/glut.h>
#include <cmath>


float moveX = 0;
int step = 0;

//background
void background(){
glColor3f(0.53, 0.81, 0.92);//sky blue
glBegin(GL_POLYGON);
    glVertex2i(0,250);
     glVertex2i(500,250);
      glVertex2i(500,500);
       glVertex2i(0,500);
       glEnd();
       glColor3f(0.56, 0.93, 0.56);//green
glBegin(GL_POLYGON);
    glVertex2i(0,125);
     glVertex2i(500,125);
      glVertex2i(500,250);
       glVertex2i(0,250);
       glEnd();
       glColor3f(0.769, 0.643, 0.518);//brownish
glBegin(GL_POLYGON);
    glVertex2i(0,0);
     glVertex2i(500,0);
      glVertex2i(500,125);
       glVertex2i(0,125);
       glEnd();
        glColor3f(1, 1, 1);//white
glBegin(GL_POLYGON);
    glVertex2i(120,250);
     glVertex2i(380,250);
      glVertex2i(350,300);
       glVertex2i(150,300);
       glEnd();
     glColor3f(0, 0, 0);//black
glBegin(GL_LINES);//boder
    glVertex2i(120,250);
     glVertex2i(380,250);

    glVertex2i(130,266);
     glVertex2i(370,266);

      glVertex2i(140,282);
       glVertex2i(360,282);

       glVertex2i(150,300);
       glVertex2i(350,300);
       glEnd();

         glColor3f(0,0,1);//blue
        glBegin(GL_POLYGON);//D
    glVertex2i(180,300);
     glVertex2i(190,300);
      glVertex2i(190,400);
       glVertex2i(180, 400);
       glEnd();
        glBegin(GL_POLYGON);
    float i,x,y, theta;
     for(i=270; i<=450; i++){
        theta = i *(3.1416/180);
        x =185+55*cos(theta);
        y=350+ 50*sin(theta);
        glVertex2i(x,y);
     }
     glEnd();
      glBegin(GL_POLYGON);
     glColor3f(0.53, 0.81, 0.92);//sky blue
     for(i=270; i<=450; i++){
        theta = i *(3.1416/180);
        x =190+45*cos(theta);
        y=350+ 42*sin(theta);
        glVertex2i(x,y);
     }
     glEnd();
     glColor3f(0,0,1);
glBegin(GL_POLYGON);//I
     glVertex2i(245,300);
      glVertex2i(245,400);
       glVertex2i(255,400);
       glVertex2i(255,300);
       glEnd();

glBegin(GL_POLYGON);//U

     for(i=180; i<=360; i++){
        theta = i *(3.1416/180);
        x =305+45*cos(theta);
        y=400+ 100*sin(theta);
        glVertex2i(x,y);
     }
    glEnd();
    glColor3f(0.53, 0.81, 0.92);
    glBegin(GL_POLYGON);
     for(i=180; i<=360; i++){
        theta = i *(3.1416/180);
        x =305+35*cos(theta);
        y=400+ 90*sin(theta);
        glVertex2i(x,y);
     }
    glEnd();

        // Tree Leaves-Triangles
    glColor3f(0.0, 0.6, 0.0); // Green
    //left tree
    // Bottom triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(65, 300);
        glVertex2i(120, 200);
        glVertex2i(10, 200);
    glEnd();

    // Middle triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(65, 350);
        glVertex2i(104, 250);
        glVertex2i(26, 250);
    glEnd();

    // Top triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(65, 400);
        glVertex2i(92, 300);
        glVertex2i(38, 300);
    glEnd();

    // Tree Trunk (Quad)
    glColor3f(0.55, 0.27, 0.07); // Brown
    glBegin(GL_QUADS);
        glVertex2i(50, 150);
        glVertex2i(80, 150);
        glVertex2i(80, 200);
        glVertex2i(50, 200);
    glEnd();
    //right tree
     glColor3f(0.0, 0.6, 0.0);
    // Bottom triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(435, 300);
        glVertex2i(380, 200);
        glVertex2i(490, 200);
    glEnd();

    // Middle triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(435, 350);
        glVertex2i(396, 250);
        glVertex2i(474, 250);
    glEnd();

    // Top triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(435, 400);
        glVertex2i(408, 300);
        glVertex2i(462, 300);
    glEnd();

    // Tree Trunk (Quad)
    glColor3f(0.55, 0.27, 0.07); // Brown
    glBegin(GL_QUADS);
        glVertex2i(450, 150);
        glVertex2i(420, 150);
        glVertex2i(420, 200);
        glVertex2i(450, 200);
    glEnd();
}

// DDA road

void road(){
    float x1=0, y1=50, x2=500, y2=50, dx, dy, steps, x_inc, y_inc, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x1;
    y = y1;

    glColor3f(0.2,0.2,0.2); // Dark gray road
    glBegin(GL_POLYGON);
        glVertex2i(0, 20);
        glVertex2i(500, 20);
        glVertex2i(500, 80);
        glVertex2i(0, 80);
    glEnd();

    // Road stripes
    glColor3f(1,1,1); // White stripes
    for(int i=0; i<500; i+=40){ // spacing between stripes
        glBegin(GL_LINES);
            glVertex2i(i, 50);
            glVertex2i(i+20, 50);
        glEnd();
    }

}

// rain
void rain(){
    glLineWidth(2);
    glColor3f(1,1,1);//raindrops
    for(int i=0;i<80;i++){
        float x = rand()%500;
        float y = rand()%500;

        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x,y-10);
        glEnd();
    }

}
// umbrella
void umbrella(float m){

    glColor3f(0.27, 0.24, 0.47);
    glBegin(GL_LINES);
    glVertex2f(m+13,210);
    glVertex2f(m+83,255);
     glVertex2f(m+16,222);
    glVertex2f(m+73,260);
    glVertex2f(m+17,232);
    glVertex2f(m+60,260);
    glVertex2f(m+25,210);
    glVertex2f(m+93,250);
    glVertex2f(m+40,210);
    glVertex2f(m+100,244);
    glVertex2f(m+55,210);
    glVertex2f(m+103,236);
    glVertex2f(m+70,210);
    glVertex2f(m+111,230);
    glVertex2f(m+85,210);
    glVertex2f(m+112,220);
    glEnd();

    glColor3f(0.43,0.43,1);

    // stick
    glBegin(GL_LINES);
    glVertex2f(m+63,150);
    glVertex2f(m+63,210);
    glEnd();
    //main
    float theta,x,y;

    for(int i=2;i<=178;i++){
        theta=i*(3.1416/180);

        x=50*cos(theta);
        y=50*sin(theta);

        glBegin(GL_POINTS);
        glVertex2f(x+m+63,y+210);
        glEnd();
    }


    //lines
     glBegin(GL_LINES);
    glVertex2f(m+113,210);
    glVertex2f(m+13,210);
    glEnd();



     for(int i=190; i<=340; i++){
        theta = i *(3.1416/180);
        x = 8 * cos(theta);
        y = 8 * sin(theta);
     glBegin(GL_POINTS);
        glVertex2i(x+m+72,y+150);
    glEnd();
     }
}

// stickman
void man(float m){



    glLineWidth(5);
    glColor3f(1,1,0);
    //head using mid point
    int r=20,x=0,y=r,p=1-r;

    while(x<=y){

        glPointSize(5);
        glBegin(GL_POINTS);

        glVertex2i(x+m+30,y+180);
        glVertex2i(-x+m+30,y+180);
        glVertex2i(x+m+30,-y+180);
        glVertex2i(-x+m+30,-y+180);

        glVertex2i(y+m+30,x+180);
        glVertex2i(-y+m+30,x+180);
        glVertex2i(y+m+30,-x+180);
        glVertex2i(-y+m+30,-x+180);

        glEnd();

        if(p<0){
            x++;
            p+=2*x+1;
        }
        else{
            x++;
            y--;
            p+=2*x-2*y+1;
        }
    }
    // body
    glBegin(GL_LINES);
    glVertex2f(m+30,110);
    glVertex2f(m+30,160);
    glEnd();

    glBegin(GL_LINES);

    if(step%2==0){

        // open legs
        glVertex2f(m+30,110);
        glVertex2f(m+10,60);

        glVertex2f(m+30,110);
        glVertex2f(m+50,60);
    }
    else{

        // close legs
        glVertex2f(m+30,110);
        glVertex2f(m+30,60);

        glVertex2f(m+30,110);
        glVertex2f(m+30,60);
    }

    glEnd();

    // hands
    glBegin(GL_LINES);

    glVertex2f(m+30,150);
    glVertex2f(m+10,110);

    glVertex2f(m+30,150);
    glVertex2f(m+43,126);

    glVertex2f(m+43,126);
    glVertex2f(m+63,150);

    glEnd();

    umbrella(m);
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    background();
    road();
    rain();
    man(moveX);
    glFlush();
}

void update(int value){
    moveX +=2;
    step++;

    if(moveX>500)
        moveX=-100;

    glutPostRedisplay();
    glutTimerFunc(60,update,0);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(500,500);
    glutCreateWindow("Walking Man With Umbrella And Rain");

    glClearColor(1,1,1,1);

    gluOrtho2D(0,500,0,500);

    glutDisplayFunc(display);

    glutTimerFunc(0,update,0);

    glutMainLoop();

    return 0;
}
