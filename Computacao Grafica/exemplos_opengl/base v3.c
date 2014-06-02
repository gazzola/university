#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define n(forc) ( sprintf(forc, "forca: %d", f) )
#define p(pont) ( sprintf(pont, "pontos: %d", pontos) )
#define e(err) ( sprintf(err, "erros: %d", erros) )


char forc[11];
char pont[11];
char err[11];

static float i=14, j=26, k=16, l=28, m=16, n=33;
static int a=16, b=33, t=0, entrada=17, direcao = 0, cesta = 0, f=17, pontos = 0, erros = 0;

void quadra(void);
void boneco(void);
void keyboard (unsigned char key, int x, int y);
void Inicializa (void);
void Desenha(void);
void lancabola(void);
void forca(void);
void linha(GLfloat x, GLfloat y, char *string);
void reseta(void);



int main(void)
{
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(10,10);
glutCreateWindow("Trabalho final Comp grafica");

glutDisplayFunc(Desenha);
Inicializa();
glutKeyboardFunc(keyboard);
glutMainLoop();

}




void quadra(void){
// suporte da tabela
glVertex2f(88,15);
glVertex2f(83,55);

glVertex2f(90,15);
glVertex2f(85,57);

glVertex2f(85,57);
glVertex2f(79,57);

glVertex2f(83,55);
glVertex2f(79,55);
//tabela
glVertex2f(78,66);
glVertex2f(79,66);

glVertex2f(79,66);
glVertex2f(79,46);

glVertex2f(78,46);
glVertex2f(79,46);

glVertex2f(78,46);
glVertex2f(78,66);
// cesta

glVertex2f(78,55);
glVertex2f(74,55);
//solo
glVertex2f(100,15);
glVertex2f(0,15);
}


void boneco(void){
     
glVertex2f(15,15);
glVertex2f(13,20);

glVertex2f(13,20);
glVertex2f(11,15);

glVertex2f(13,20);
glVertex2f(13,30); 
//antebraço
glVertex2f(13,28);
glVertex2f(k,l);
//braço

glVertex2f(k,l);    
glVertex2f(m,n);
     
     }




void keyboard (unsigned char key, int x, int y)
{

   switch (key) {
      case 'l':
         glutPostRedisplay();
         glutTimerFunc(33, lancabola, 1);
         break;
      case 'f':
              f++;
              if(f == 74)
                 f = 17;
              entrada = f;
              glutPostRedisplay();
           
         break;           
      default:
         break;
   }
}


void Inicializa (void)
{
// Define a cor de fundo da janela de visualização como preta
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glColor3f(0.3,0.3,1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,100.0,0.0,100.0);
glMatrixMode(GL_MODELVIEW);
glShadeModel (GL_FLAT);
}


void Desenha(void)
{
//Limpa a janela de visualização com a cor de fundo especificada
glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);


glBegin(GL_LINES);
quadra();
boneco();
forca();

glEnd();

//cabeça
glPushMatrix();
glTranslatef(13.0,32.0,1.0);
glutSolidSphere(1.6, 10, 8);   /* draw sun */
glPopMatrix();

//bola
glPushMatrix();
glVertex2f(a,b);
glTranslatef((GLfloat) a,(GLfloat) b,1.0);
glutSolidSphere(2.0, 10, 8);    /* draw smaller planet */
glPopMatrix();
n(forc);
p(pont);
e(err);
linha(77, 80, forc);
linha(14, 10, pont);
linha(14, 5, err);
linha(30, 12, "comandos:");
linha(30, 7, "tecla ' f ': seleciona a forca");
linha(30, 2, "tecla ' l ': lanca a bola");
glutSwapBuffers();

//glVertex2f(16,28);
//Executa os comandos OpenGL
glFlush();

}






void lancabola(void){
         j=28.5;
         k=i;
         l=j;
         n=30;
         
         if(t==1){
           a++;
           b--;
         }else if(t==2){
                 b--;
                }  
                else if(t==0){
                  a++;
                  b++;
                }
                else if(t == 3){
                  a--;
                  b--;
                }
         if(a==entrada && direcao == 0){
           t=1;
           direcao = 1;
         }

         if(a == 76 && b >=46 && b<=66 && cesta == 0){
           t=3;
           
         }
         //glVertex2f(78,55);
         //glVertex2f(74,55);
         if((b == 55) && (a >= 74) && (a <= 78)){
              t=2;
              cesta = 1;
              pontos++;
              }
         
         if (b>=17){
         printf("\na = %d b = %d t= %d", a, b, t);
         glutPostRedisplay();
         glutTimerFunc(23, lancabola, 1);
         }
         else {
              if(t!=2)
                 erros++;
                 reseta();
                 glutPostRedisplay();
              }
     }


void forca(void){
     glVertex2f(17,80);
     glVertex2f(74,80);
     
     glVertex2f(f,83);
     glVertex2f(f,80);
     
     }



void linha(GLfloat x, GLfloat y, char *string)
{
  int len, i;	
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.02, 0.02, 0.02);  
  len = (int) strlen(string);
  for (i=0; i<len; i++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);  
  glPopMatrix();
}

void reseta(void){
     
i=14;
j=26; 
k=16;
l=28;
m=16; 
n=33;
a=16;
b=33;
t=0;
entrada=17;
direcao = 0;
cesta = 0;
f=17;
}
