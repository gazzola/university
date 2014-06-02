/** 
UNIPAMPA (Universidade Federal do Pampa)
CTA (Campus Tecnol�gico de Alegrete)
Ci�ncia da Computa��o
Computa�ao Gr�fica
Prof. Alessandro Bof de Oliveira
Modelagem Geom�trica - Desenho de Primitivas
**/
#include <stdio.h>
#include <glut.h>





void Inicializa (void)
{   
    
    


    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0,0.0,1.0);
    
 
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
	//Limpa a janela de visualiza��o com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT);
//  glTranslatef(40.0,40.0,0.0);
    
//   glutWireTeapot(5.0);
//   glMatrixMode(GL_MODELVIEW);
//     glRotated(45,0,1,1);
glPushMatrix();
     glTranslatef(2.0,0.0,0.0);
     glRotatef(30,1,1,0);
     glutWireCube(5.0);
glPopMatrix();

glPushMatrix();
     glTranslatef(-4.0,2.0,0.0);
     glRotatef(30,0,1,1);
     gluWireCylinder(2.0,20,20,20);
glPopMatrix();
     

//   glutWireSphere(5.0,20,20);
	//Executa os comandos OpenGL 
	glFlush();
}




// Inicializa par�metros de rendering


// Programa Principal 
int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
	glutCreateWindow("Modelagem Geom�trica Renderiza��o 2");
 
    Inicializa();
	glutDisplayFunc(Desenha);
//    Inicializa();
//    luz();

	glutMainLoop();
}
