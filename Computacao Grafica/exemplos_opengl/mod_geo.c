/** 
UNIPAMPA (Universidade Federal do Pampa)
CTA (Campus Tecnológico de Alegrete)
Ciência da Computação
Computaçao Gráfica
Prof. Alessandro Bof de Oliveira
Modelagem Geométrica - Desenho de Primitivas
**/
#include <stdio.h>
#include <glut.h>


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
    glColor3f(0.0,0.0,1.0);
    
 //   glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0,10.0,0.1,1000);  
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}




void Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
//  glTranslatef(40.0,40.0,0.0);
    
//   glutWireTeapot(5.0);
//   glMatrixMode(GL_MODELVIEW);
//     glRotated(45,0,1,1);
glPushMatrix();
     glTranslatef(2.0,0.0,0.0);
     glRotatef(30,1,1,0);
     glutSolidCube(5.0);
glPopMatrix();

glPushMatrix();
     glTranslatef(-4.0,2.0,0.0);
     glRotatef(10,0,0,1);
     glutSolidSphere(2.0,20,20);
glPopMatrix();
     

//   glutWireSphere(5.0,20,20);
	//Executa os comandos OpenGL 
	glFlush();
}




// Inicializa parâmetros de rendering


// Programa Principal 
int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
	glutCreateWindow("Modelagem Geométrica Renderização");
    luz();
    Inicializa();
	glutDisplayFunc(Desenha);
//    Inicializa();
//    luz();

	glutMainLoop();
}
