
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Declaração de variáveis globais
GLfloat tx = 0; //posição inicial do boneco 
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 25;



//-----------------------------------------------------------------------------------
// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando caracteres bitmap
void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor para os textos: preto
	glColor3f(1,1,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-60,0,0);
	glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(4); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"THE SOWING GAME");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,1);
	
	glScalef(1, 1.4, 1);
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-70,-20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"\nGabriel Dias \n Ualace\n Edeilton\n Gabriel Cosmo\n");
	glRasterPos2f(-70,-50);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"\nAperte com o botao direito do mouse para o menu\n");
	// Exibe o desenha na janela
	glutSwapBuffers();
}




//--------------------------------------------------------------------------

//Função para desenhar circulo
void drawCircleFill(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);// calcula fator tangencial
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float radial_factor = cosf(theta);//calcula fator radial 
    float x = r;//iniciando angulo em 0 
    float y = 0;

    glBegin(GL_POLYGON);
    
    if (num_segments = 180) num_segments = num_segments/2; 
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//vertex de saída

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
//--------------------------------------------------------------------------


jogo(){
}
sobre(){
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);
	// Define a cor de fundo de tela como verde
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Define a cor para os textos: amerelo
	glColor3f(1,1,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-80,50,0);
	glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(4); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"O JOGO:");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,1,1);
	
	glScalef(1, 1.4, 1);
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-90,20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Criado com o objetivo de entender o processo de semeadura, ");
	glRasterPos2f(-90,16); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"preciso seguir os passos em ordem para completar a fase. ");
	glRasterPos2f(-90,10);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Ao final poderá ver a recompensa quando se pensa na natureza");
	glRasterPos2f(-90,0);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Pensar no meio ambiente,   garantir um futuro melhor!");
	glRasterPos2f(-90,-10);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Espero que divirta-se!!!!");
	glRasterPos2f(-90,-20);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Aperte ESC para sair ou H para os comandos");
	// Exibe o desenha na janela
	glutSwapBuffers();
}
comandos(){
}

void menu(int key1)
{	
	switch(key1)
	{
		case 1: //Iniciar
			jogo();				
			break;
		
		case 2: //Sobre o Jogo
		    sobre();
			break;
		    
		case 3: //Comandos    
			comandos();
			break;
		case 4: exit(0);
		    break;	
	}	
}           


// Criacao do Menu
void menuSystem() 
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Iniciar",1);
    glutAddMenuEntry("Sobre o Jogo",2);
    glutAddMenuEntry("Comandos",3);
    glutAddMenuEntry("Sair",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            menuSystem();
         
    glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}
           
// Função responsável por inicializar parâmetros e variáveis
// Inicializa projeção
void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
	
	// Define a cor de fundo de tela como verde
	glClearColor(0.1f, 0.7f, 0.0f, 1.0f);
}

// Programa Principal 
int main(void)
{
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );  
	glutInitWindowPosition(5,5);  //Define a posição inicial na tela, do canto superior esquerdo a janela   
	glutInitWindowSize(600,500);  //Define o tamanho inicial da janela GLUT que será criada
	glutCreateWindow("The Sowing Game"); 
 
	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);  
	
	
	

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a função responsável por fazer as inicializações 
	Inicializa(); 
 	
 	menuSystem();
	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
	


	return 0;
}
