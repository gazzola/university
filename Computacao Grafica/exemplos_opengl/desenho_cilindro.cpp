/** 
UNIPAMPA (Universidade Federal do Pampa)
CTA (Campus Tecnológico de Alegrete)
Ciência da Computação
Computaçao Gráfica
Prof. Alessandro Bof de Oliveira
Cilindro
**/
#include <stdio.h>
#include <glut.h>
#include <math.h>




void luz(void)
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 40.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glDepthFunc(GL_LEQUAL);
glEnable(GL_DEPTH_TEST);
}


void Inicializa (void)
{   
    
    


    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f,1.0f,1.0f);
    
 //   glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10.0,0.0,1000);  
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}




void Desenha(void)
{
     float t,r,passo;
     r=2.0;
     passo=0.1;
     
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
//	glClear(GL_COLOR_BUFFER_BIT );
//  glTranslatef(40.0,40.0,0.0);
    
//   glutWireTeapot(5.0);
//   glMatrixMode(GL_MODELVIEW);
//     glRotated(45,0,1,1);
//glPushMatrix();
//     glTranslatef(2.0,0.0,0.0);
//     glRotatef(30,1,1,0);
  //   gluCylinder(2.0,5.0,20,20);
//glPopMatrix();

//glPushMatrix();
//     glTranslatef(-4.0,2.0,0.0);
//     glRotatef(30,0,1,1);
 //    glutSolidCone(2.0,5,20,20);
//     auxWireBox(2.0,1.0,1.0);
//glPopMatrix();

//glPushMatrix();

glColor3f(1.0,0.0,0.0);

glPushMatrix();

  glTranslatef(0.0,0.0,0.0);
  glRotatef(30,1,1,1);

glBegin(GL_LINES);


//for (t=0;t<=0.0;t=t+0.1){
  for (t=0;t<=2*3.14;t=t+passo){
//      glVertex3f(0.0,0.0,0.0);
//      glVertex3f(4.0,0.0,0.0);
//      glVertex3f(0.0,0.0,4.0);  
//
//printf("%3.5f\n",t);
glVertex3f(2.0*cos(t),2.0*sin(t),0.0);
glVertex3f(2.0*cos(t),2.0*sin(t),5.0);

glVertex3f(2.0*cos(t),2.0*sin(t),5.0);
glVertex3f(2.0*cos(t+passo),2.0*sin(t+passo),5.0);

glVertex3f(2.0*cos(t+passo),2.0*sin(t+passo),5.0);
glVertex3f(2.0*cos(t+passo),2.0*sin(t+passo),0.0);

glVertex3f(2.0*cos(t+passo),2.0*sin(t+passo),0.0);
glVertex3f(2.0*cos(t),2.0*sin(t),0.0);


}
glEnd();


glPopMatrix();

//glPushMatrix();
//glutWireTeapot(5.0);
//glPopMatrix();



     

//   glutWireSphere(5.0,20,20);
	//Executa os comandos OpenGL 
	glFlush();
}




// Inicializa parâmetros de rendering


// Programa Principal 
int main(void)
{
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
	glutCreateWindow("Cilindro");
 //   luz();
//    Inicializa();
	glutDisplayFunc(Desenha);
    Inicializa();
  // luz();

	glutMainLoop();
}
