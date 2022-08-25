
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Declaração de variáveis globais
GLfloat tx = 0 , ty = 0; //posição inicial do boneco 
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 25;

void TeclasEspeciais(int key, int x, int y)
{
	
	// Rotaciona tronco
	if(key == GLUT_KEY_PAGE_UP && ang1 >= -20)
		ang1-=5;
	if(key == GLUT_KEY_PAGE_DOWN && ang1 <= 20)
		ang1+=5;
              
	// Rotaciona item interno 
	if(key == GLUT_KEY_UP && ty< 8 )
		ty+=2;
		//ang3-=5;
		
	if(key == GLUT_KEY_DOWN && ty > -2)
		ty-=2;
		//ang3+=5;              
                                                
	glutPostRedisplay();
}
// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;
                   
	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;
                                              
	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) 
	{ 
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
		win = 25.0f;
	}              
	else 
	{ 
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
		win = 25.0f*largura/altura;           
	}             
}
void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
	
	
}


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
	// Define a cor de fundo de tela como verde
	glClearColor(0.1f, 0.7f, 0.0f, 1.0f);
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
    float theta = 3.1415926 * 2 /                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    float(num_segments);
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

// Função para desenhar um "braço" do objeto
void Folhas()
{
	glBegin(GL_POLYGON);
		glVertex2f(1.0,2.6);
		glVertex2f(1.0,-2.8);
		glVertex2f(-3.0,-2.8);
		glVertex2f(-3.0,2.6);
	glEnd();
}

// Função para desenhar a base do objeto {tronco          
void Tronco()
{
	glLineWidth(2);
	glBegin(GL_POLYGON);
		glVertex2f(1.8,2);
		glVertex2f(1.8,-8);
		glVertex2f(-1.8,-8);
		glVertex2f(-1.8,2);
	glEnd();
}
jogo(){
	// Define a cor de fundo de tela como preto
	glClearColor(0.0f, 0.6f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor para os textos: preto
	glColor3f(0,0,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-30,50,0);
	glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(4); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"ANDOS:");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0.6,1,0.75);
	
	glScalef(1, 1.4, 1);
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-90,20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 1 para selecionar a Semente ");
	glRasterPos2f(-90,14); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 2 para selecionar o Sol ");
	glRasterPos2f(-90,8);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 3 para selecionar a Agua");
	glRasterPos2f(-90,2);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> End para os comandos");
	glRasterPos2f(-90,-4);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Home para começar/reiniciar o jogo");
	glRasterPos2f(-90,-10);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> ESC para sair do jogo");
	glRasterPos2f(-90,-16);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"JOGO ARVORE:");
	glRasterPos2f(-90,-22);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> PGUP/ PGDN para rotacionar arvore");
	glRasterPos2f(-90,-28);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Setas para cima e para baixo para crescer");
	// Exibe o desenha na janela
	glutSwapBuffers();
}
sobre(){
	
	// Define a cor de fundo de tela como preto
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Aperte ESC para sair ou tecla End para os comandos");
	// Exibe o desenha na janela
	glutSwapBuffers();
}
comandos(){
	
	// Define a cor de fundo de tela como preto
	glClearColor(0.0f, 0.675f, 0.432f, 0.6f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Define a cor para os textos: amerelo
	glColor3f(1,0,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-30,50,0);
	glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(4); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"COMANDOS:");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,0);  // 0.6,1,0.75 azul bebe
	
	glScalef(1, 1.4, 1);
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-90,20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 1 para selecionar a Semente ");
	glRasterPos2f(-90,14); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 2 para selecionar o Sol ");
	glRasterPos2f(-90,8);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 3 para selecionar a Agua");
	glRasterPos2f(-90,2);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> End para os comandos");
	glRasterPos2f(-90,-4);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Home para começar/reiniciar o jogo");
	glRasterPos2f(-90,-10);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> ESC para sair do jogo");
	glRasterPos2f(-90,-16);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"JOGO ARVORE:");
	glRasterPos2f(-90,-22);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> PGUP/ PGDN para rotacionar arvore");
	glRasterPos2f(-90,-28);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Setas para cima e para baixo para crescer");
	// Exibe o desenha na janela
	glutSwapBuffers();
}

void arvore(void){
	
	
	glClearColor(0.0f, 0.0f, 0.4, 0.6f);
	glClear(GL_COLOR_BUFFER_BIT);
	//desenha o sol
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 0.2f);
	drawCircleFill(-20,20,3,90);
		// Desenha o "chão"
	glColor3f(0.004f,0.364f,0.031f);
	glLineWidth(6);
	glBegin(GL_POLYGON);
		glVertex2f(-win,-7.9);
		glVertex2f(win,-7.9);
		glVertex2f(win,-50);
		glVertex2f(-win,-50);
		glEnd(); 
	
    DesenhaTexto(GLUT_BITMAP_9_BY_15,"### Consulte comandos ");
	                           
	// Desenha um objeto modelado com transformações hierárquicas
	glPushMatrix();                   
	                
	glTranslatef(tx,0.0f,0.0f); // poe no meio
    
	glPushMatrix();
	glScalef(2.5f,2.0f,1.0f);
	glColor3f(0.36f,0.21f,0.14f);       //tronco marrom
	Tronco();                     //tronco
	glScalef(1.4f,1.4f,1.0f);
    
	glPopMatrix();
                    
	glTranslatef(0.0f,ty,0.0f);
	glRotatef(ang1,0.0f,0.0f,1.0f);    
	glScalef(6.0f,1.4f,1.0f);
	glColor3f(0.0f,0.854f,0.2f);
	Folhas();                 //folhas
     

    glScalef(0.3f,0.8f,1.0f);
	drawCircleFill(0, 4, 3, 90);   //cabeça
	
	glColor3f(0.8f,0.1f,0.0f);        // vemrelho
	drawCircleFill(0,6.4,1.0,90);     //maças 
	drawCircleFill(-1,4.4,0.5,90);   
	drawCircleFill(1,4.4,0.5,90);   
	drawCircleFill(-8,-0.5,0.55,90);  
	drawCircleFill(1,2.2,0.6,90);    
	drawCircleFill(-4,0,1.0,90); 
	
	
	
	glScalef(1.0f,0.7f,1.0f);
	glColor3f(0.0f,0.854f,0.2f);                        
	glTranslatef(-5.5f,3.0f,0.0f);
	glRotatef(ang2,0.0f,0.0f,1.0f);
    Folhas();               //braço esquerdo 
		
	glTranslatef(0.0f,11.0f,0.0f);
	Folhas();              
	  
	glPopMatrix();    
   
	  

	// Exibe o desenha na janela
	glutSwapBuffers();
	
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
		case 5: //arvore
		
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );  
		glutInitWindowPosition(40,5);  //Define a posição inicial na tela, do canto superior esquerdo a janela   
		glutInitWindowSize(700,500);  //Define o tamanho inicial da janela GLUT que será criada
		glutCreateWindow("Árvore");
		glutDisplayFunc(arvore);
			// Registra a função callback de redimensionamento da janela de visualização
		glutReshapeFunc(AlteraTamanhoJanela); 
		
		// Registra a função callback para tratamento das teclas especiais
		glutSpecialFunc(TeclasEspeciais);   
		// Chama a função responsável por fazer as inicializações 
		Inicializa(); 
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
    glutAddMenuEntry("Arvore",5);
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
