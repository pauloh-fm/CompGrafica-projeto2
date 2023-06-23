#include <stdio.h>
#include <GL/glut.h>
// Martelo do chapolim articulado -- Paulo Henrique de Farias Martins
// comando para compilar: gcc -o objetoArticulado  objetoArticulado.c -lGL -lglut -lGLU -lm
// Variáveis globais para controle do objeto
// inicialmente alinhadas em suas posições iniciais.
float anguloArticulacao1 = 90.0f; 
float anguloArticulacao2 = -90.0f;
float anguloArticulacao3 = 90.0f;

// Função para desenhar o objeto do arco e flecha
void desenharObjeto()
{
    // Desenhar o fundo colorido
    glColor3f(0.4f, 0.6f, 0.8f); // Cor azul claro
    glBegin(GL_QUADS);
    glVertex2f(-5.0f, -5.0f);
    glVertex2f(-5.0f, 5.0f);
    glVertex2f(5.0f, 5.0f);
    glVertex2f(5.0f, -5.0f);
    glEnd();
    
// Desenhar a primeira articulação
    glPushMatrix();
    glTranslatef(-2.5f, 0.0f, 0.0f);
    glRotatef(anguloArticulacao1, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); // Cor amarela
    glBegin(GL_QUADS);
    glVertex2f(-2.0f, -0.1f);
    glVertex2f(-2.0f, 0.1f);
    glVertex2f(2.0f, 0.1f);
    glVertex2f(2.0f, -0.1f);
    glEnd();

    // Desenhar a segunda articulação
    glTranslatef(2.0f, 0.0f, 0.0f);
    glRotatef(anguloArticulacao2, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // vermelha
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.5f, -0.1f);
    glEnd();

    // Desenhar a terceira articulação
    glTranslatef(0.5f, 0.0f, 0.0f);
    glRotatef(anguloArticulacao3, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // vermelha
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.5f, -0.1f);
    glEnd();

    glPopMatrix();
}

// Função de desenho
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Posicionar a câmera
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    // Desenhar o objeto 
    desenharObjeto();

    glutSwapBuffers();
}

// Função de redimensionamento da janela
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

// Função de atualização do objeto
void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Função para lidar com eventos de teclado
void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla) {
        case 'q':
            anguloArticulacao1 += 5.0f;
            break;
        case 'a':
            anguloArticulacao1 -= 5.0f;
            break;
        case 'w':
            anguloArticulacao2 += 5.0f;
            break;
        case 's':
            anguloArticulacao2 -= 5.0f;
            break;
        case 'e':
            anguloArticulacao3 += 3.0f;
            break;
        case 'd':
            anguloArticulacao3 -= 3.0f;
            break;
    }
}

// Função principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Martelo do Chapolim Articulado");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);
    glutKeyboardFunc(teclado);
    
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    
    glutMainLoop();

    return 0;
}
