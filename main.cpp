/*
z -> Shoot rocket
y -> Early Morning
m -> Morning
a -> Afternoon
e -> Evening
n -> Night
d -> Mid Night
Num 6 -> Moving Ship Fwd
Num 4 -> Moving Ship bckwd
Esc -> Exit
*/

#include<GL/glut.h>
#include<windows.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>

float pos=0,x=0,col=0,i,p,c,cf=0,pr,pl=0;
int screen=0;

//Introduction Page
char name[35]="The Curse of Black Pearl";
char college[100]="K.L.E. Institute of Technology, Hubli-580030";
char dept[100]="Department of Computer Science & Engineering";
char heading[100]="Made by                                                                 Guides";
char row1[100]="Sridhar Kulkarni (2KE12CS052)                                 Prof.Kiran M.";
char row2[100]="Noah Pinto (2KE12CS028)                            Prof.Vijaymahantesh K.";
char emsg[100]="Press ENTER to start";
char title[50]="Sailing of Ship Day And NighT...!";
char dash[100]="--------------------------------------------------------------------------------------";

void frontscreen(void)
{
     glPushMatrix();
     glTranslatef(50,100,0);
     glClearColor(0.8,0.8,1.0,1.0);
     int s;
     glClear(GL_COLOR_BUFFER_BIT);

     glRasterPos2i(184,480);                                                    //displays college name
     for(s=0;college[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,1.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,college[s]);
     }
    
     glRasterPos2i(180,450);                                                     //displays dept.                 
     for(s=0;dept[s]!='\0';s++)        
     {
     glColor3f(1.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,dept[s]);
     } 
     
     glRasterPos2i(210,380);                                                    //displays project name                          
     for(s=0;title[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title[s]);
     }
     
     glRasterPos2i(155,370);                                                    //displays dashes                                    
     for(s=0;dash[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }
     
     glRasterPos2i(170,340);                                                    //displays heading of table                   
     for(s=0;heading[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,heading[s]);
     }
     
     glRasterPos2i(155,330);                                                    //displays dashes            
     for(s=0;dash[s]!='\0';s++)                       
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }
     
     glRasterPos2i(170,310);                                                    //displays 1st row in table                
     for(s=0;row1[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,row1[s]);
     }
     
     glRasterPos2i(170,290);                                                    //displays 2nd row in table                        
     for(s=0;row2[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,row2[s]);
     }
     
     glRasterPos2i(155,270);                                                    //displays dashes    
     for(s=0;dash[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);            
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }
     
     glRasterPos2i(200,100);                                                    //displays "enter msg"     
     for(s=0;emsg[s]!='\0';s++)
     {
     glColor3f(1.0,0.0,0.5);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,emsg[s]);
     }     
  
     glPopMatrix();
     glFlush();
}

//sun/moon
void Drawarc(float sa,float ea,float cx,float cy,float rd)
{
     float PI = 3.14;
     float step=1.0;
     float angle,x=0,y=0,centerX=cx,centerY=cy,radius=rd;
    
     glBegin(GL_POLYGON);
     for(angle=sa;angle<ea; angle+=step)
     {
     float rad ;
     rad = PI*angle/180;
     x  = centerX+radius*cos(rad);
     y  = centerY+radius*sin(rad);
     glVertex2f(x,y);
     }
     glEnd();
     glFlush();
}

//smoke
void cloud(int m, int n)
{
     for(c=p=0;c<31;c+=10,p-=1)
     {
     glColor3f(0.5,0.5,0.5);
     Drawarc(0,360,m+c,n,10+p);
     } 
}

void ship(float x)
{
    glPushMatrix();
    glTranslatef(x,0,0);
//base
    glColor3f(0.2+col,0.2+col,0.2+col);	
    glBegin(GL_POLYGON);
    glVertex2f(10,119);		
    glVertex2f(10,110);	
    glVertex2f(41,70);
    glColor3f(0.3+col,0.3+col,0.8+col);
    glVertex2f(219,42);						
    glVertex2f(292,98);	
    glVertex2f(300,110);
    glEnd();
		
//p1
	glColor3f(1.0+col,1.0+col,1.0+col);
	glBegin(GL_POLYGON);	
	glVertex2f(35,118);
	glVertex2f(35,128);
	glColor3f(0.5+col,0.5+col,0.5+col);
	glVertex2f(239,131);
	glVertex2f(239,111);
	glVertex2f(35,119);
	glEnd();
	//side
    glBegin(GL_POLYGON);
	glColor3f(0.8+col,0.8+col,0.8+col);
	glVertex2f(239,131);
	glVertex2f(239,111);
	glVertex2f(257,110);
	glVertex2f(257,127);
	glEnd();
	
//p2
    glColor3f(0.0+col,0.0+col,0.5+col);
	glBegin(GL_POLYGON);
	glVertex2f(45,129);
	glVertex2f(45,140);
	glVertex2f(233,149);
	glVertex2f(233,131);		
	glEnd();
    //side
    glBegin(GL_POLYGON);
	glColor3f(0.1+col,0.1+col,0.8+col);
	glVertex2f(233,149);
	glVertex2f(233,131);
	glVertex2f(254,128);
	glVertex2f(254,145);
	glEnd();
	
//p3
    glColor3f(0.2+col,0.5+col,0.2+col);
	glBegin(GL_POLYGON);
	glVertex2f(51,151);
	glVertex2f(51,140);
	glVertex2f(221,149);
	glColor3f(0.9+col,0.6+col,0.3+col);
	glVertex2f(221,165);
	glVertex2f(51,151);
	glEnd();
	//side
    glBegin(GL_POLYGON);
	glColor3f(0.1+col,0.4+col,0.1+col);
	glVertex2f(221,164);
	glVertex2f(221,149);
	glVertex2f(247,147);
	glVertex2f(247,162);
	glEnd();

//p4
    //pipe1
	glColor3f(0.48+col,0.27+col,0.44+col);
	glBegin(GL_POLYGON);
	glVertex2f(79,152);
	glVertex2f(79,194);
	glVertex2f(94,194);
	glColor3f(0.0+col,0.0+col,0.0+col);
	glVertex2f(94,155);
	glEnd();
	cloud(59,194);

    //pipe2 
    glColor3f(0.44+col,0.48+col,0.27+col);
	glBegin(GL_POLYGON);
	glVertex2f(112,156);
	glVertex2f(112,198);
	glVertex2f(127,198);
	glColor3f(0.0+col,0.0+col,0.0+col);
	glVertex2f(127,158);
	glEnd();
	cloud(92,198);
	
	//pipe3
    glColor3f(0.27+col,0.48+col,0.44+col);
	glBegin(GL_POLYGON);
    glVertex2f(159,161);
	glVertex2f(159,203);
	glVertex2f(179,203);
	glColor3f(0.0+col,0.0+col,0.0+col);
    glVertex2f(179,160);	
	glEnd();
	cloud(144,203);
	glPopMatrix();
}

void water()
{
    glBegin(GL_POLYGON);
    glColor3f(0.2+col,0.2+col,0.6+col);
    glVertex2f(00,00);
    glVertex2f(00,300);
    glVertex2f(1024,300);
    glVertex2f(1024,00);
	glEnd();
}

void mountain2()
{
    float a,b;
    glColor3f(0.6+col,0.4+col,0.2+col);
    for(a=0,b=300;a<1025;a=a+80)
    {
    glBegin(GL_POLYGON);
    glVertex2f(-40+a,b);
    glVertex2f(10+a,b+140);
    glVertex2f(60+a,b);
    glEnd();
    }
}

void mountain()
{
    float a,b;
    glColor3f(0.8+col,0.6+col,0.4+col);
    for(a=0,b=300;a<1025;a=a+80)
    {
    glBegin(GL_POLYGON);
    glVertex2f(0+a,b);
    glVertex2f(50+a,b+100);
    glVertex2f(100+a,b);
    glEnd();
    }
}

void mountain3()
{
    float a,b;
    glColor3f(0.4+col,0.2+col,0.0+col);
    for(a=0,b=350;a<1025;a=a+80)
    {
    glBegin(GL_POLYGON);
    glVertex2f(0+a,b);
    glVertex2f(50+a,b+180);
    glVertex2f(100+a,b);
    glEnd();
    }
}

void flag(float x)
{
     int s;
     glPushMatrix();
     glTranslatef(x,0,0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     glVertex2f(245,160);
     glVertex2f(245,250);
     glVertex2f(242,250);
     glVertex2f(242,160);
     glEnd();
     glColor3f(0.8,0.1,0.1);
     glBegin(GL_POLYGON);
     glVertex2f(245,250);
     glVertex2f(275,215);
     glVertex2f(245,180);
     glEnd();
     glRasterPos2i(50,80);                                                    //displays college name
     for(s=0;college[s]!='\0';s++)
     {
     glColor3f(1.0,1.0,1.0);            
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[s]);
     }
     glPopMatrix();
}
void crackers()
{
    // if(cf==1)
     {
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     glVertex2f(100+pos,100+pr);
     glVertex2f(100+pos,110+pr);
     glVertex2f(101+pos,110+pr);
     glVertex2f(101+pos,100+pr);
     glEnd();
     glFlush();
     }
     glutPostRedisplay();
}
     
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glLoadIdentity();
	gluOrtho2D(0,1024,0,768);
}


void plane()
{
glPushMatrix();
glTranslatef(0+pl,700,0);     
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);//rectangular body
glVertex2f(0.0,30.0/3);
glVertex2f(0.0,55.0/3);
glVertex2f(135.0/3,55.0/3);
glColor3f(1.0,0.0,0.0);
glVertex2f(135.0/3,30.0/3);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(135.0/3,55.0/3);
glVertex2f(150.0/3,50.0/3);
glVertex2f(155.0/3,45.0/3);
glVertex2f(160.0/3,40.0/3);
glVertex2f(135.0/3,40.0/3);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(135.0/3,55.0/3);
glVertex2f(150.0/3,50.0/3);
glVertex2f(155.0/3,45.0/3);
glVertex2f(160.0/3,40.0/3);
glVertex2f(135.0/3,40.0/3);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(135.0/3,40.0/3);
glVertex2f(160.0/3,40.0/3);
glVertex2f(160.0/3,37.0/3);
glVertex2f(145.0/3,30.0/3);
glVertex2f(135.0/3,30.0/3);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(0.0,55.0/3);
glVertex2f(0.0,80.0/3);
glVertex2f(10.0/3,80.0/3);
glVertex2f(40.0/3,55.0/3);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(65.0/3,55.0/3);
glVertex2f(50.0/3,70.0/3);
glVertex2f(75.0/3,70.0/3);
glVertex2f(90.0/3,55.0/3);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(70.0/3,40.0/3);
glVertex2f(100.0/3,40.0/3);
glVertex2f(80.0/3,15.0/3);
glVertex2f(50.0/3,15.0/3);
glEnd();
glPopMatrix();     
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    if(screen==0)
    {
    frontscreen();
    glFlush();
    }
    else if(screen==1)
	{
    mountain3();
	mountain2();
	mountain();
	water();
	 if(cf==1)
    {
    crackers();
	pr+=2;
     }
	ship(pos);
	flag(pos);

	plane();
	pl+=2;
	if(pl==1200)
	pl=0;
	
    if(i==1)
    {        
    glColor3f(0.9,0.9,0.5);
    Drawarc(0,360,200,700,10);
    }
     if(i==2)
    {        
    glColor3f(0.8,0.7,0.4);
    Drawarc(0,360,400,700,10);
    }
     if(i==3)
    {        
    glColor3f(1.0,1.0,1.0);
    Drawarc(0,360,600,700,10);
    }
     if(i==4)
    {        
    glColor3f(1.0,1.0,1.0);
    Drawarc(0,360,800,700,10);
    }
    glFlush();
    }
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{ 
   switch (key)
   {
    case 13:if(screen==0)
                 {
                 screen=1;
                 glutPostRedisplay();
                 }
                 break;
    case 27:exit (0);
	        break;
    case 'y':glClearColor(0.8,0.5,0.4,1.0);
             col=-0.1;
             i=0;
             glutPostRedisplay();
	         break;
    case 'm':glClearColor(0.5,0.5,1.0,1.0);
             i=1;
             col=0.2;
             glutPostRedisplay();
	         break;
    case 'a':glClearColor(0.9,0.9,0.3,1.0);
             i=2;
             col=0.3;
             glutPostRedisplay();
	         break;
    case 'e':glClearColor(0.8,0.5,0.4,1.0);
             col=-0.1;
             i=0;
             glutPostRedisplay();
	         break;
    case 'n':glClearColor(0.5,0.5,0.5,1.0);
             i=3;
             glutPostRedisplay();
             col=-0.2;
   	         break;
    case 'd':glClearColor(0.0,0.0,0.0,0.0);
             i=4;
             col=-0.3;
             glutPostRedisplay();
	         break;
    case '6':pos+=2;
             break;
    case '4':pos-=2;
             break;
    case 'z':cf=1;
             pr=0;
             glutPostRedisplay();
             break;
   } 
}
 
int main()
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Moving Ship");
	glutSwapBuffers();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
