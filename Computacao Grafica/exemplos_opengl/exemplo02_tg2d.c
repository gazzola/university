/** 
UNIPAMPA (Universidade Federal do Pampa)
CTA (Campus Tecnol�gico de Alegrete)
Ci�ncia da Computa��o
Computa�ao Gr�fica
Prof. Alessandro Bof de Oliveira
08/08/2010
Programa de exemplo de transla��o utilizando openGL
**/
#include <windows.h>
#include <glut.h>


void Inicializa (void)
{   
    
    
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.3,0.3,1.0);
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,100.0,0.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}




void Desenha(void)
{
	//Limpa a janela de visualiza��o com a cor de fundo especificada 
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
                       glVertex2f(10,10);
                       glVertex2f(10,20);
                       glVertex2f(20,20);
                       glVertex2f(20,10);
 

    glEnd();
    // desenha outra figura transladada
    glColor3f(1.0,0.3,0.3);
    glTranslatef(40.0,40.0,0.0);
    glBegin(GL_POLYGON);
                       glVertex2f(10,10);
                       glVertex2f(10,20);
                       glVertex2f(20,20);
                       glVertex2f(20,10);
 

    glEnd();

	//Executa os comandos OpenGL 
	glFlush();
}




// Inicializa par�metros de rendering


// Programa Principal 
int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
	glutCreateWindow("Transforma��es Geom�tricas em 2D");

	glutDisplayFunc(Desenha);
    Inicializa();

	glutMainLoop();
}
