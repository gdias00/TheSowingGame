
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Declaração de variáveis globais
GLfloat tx = 0 , ty = 0; //posição inicial do boneco 
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 25;
int entrada[3] = {0}, verif[] = {2,3,1};		//	o primeiro vetor armazena as entradas do usuario e o segundo é responsavel por verificar se está nas posições corretas
int atual = 0;									//	variavel auxiliar de controle

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
// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
		
	if( key == 49)
	{
		entrada[atual] = 1;
		atual = (atual + 1) % 3;
	}
	if( key == 50)
	{
		entrada[atual] = 2;
		atual = (atual + 1) % 3;
	}
	if( key == 51)
	{
		entrada[atual] = 3;
		atual = (atual + 1) % 3;
	}
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
void Inicializa2 (void)
{	
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-37.5,37.5,-25,25);		
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
//-

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}

void flor(void){
	//base
	// Define a cor de fundo da janela de visualização como ceu
	glClearColor(0.11, 0.63, 0.93, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.08, 0.86, 0.12);
	
	glBegin(GL_QUADS);
		glVertex2f(-37.5,0);
		glVertex2f(-37.5,-25);
		glVertex2f(37.5,-25);
		glVertex2f(37.5,0);
	glEnd();
	
	
	glTranslatef(0,-10,0);
	//caule
	glColor3f(0.06, 0.49, 0.05);
	
	glBegin(GL_QUADS);
		glVertex2f(-0.75,5);
		glVertex2f(0.75,5);
		glVertex2f(0.75,25);
		glVertex2f(-0.75,25);
	glEnd();
			
	glPushMatrix();	
	
		glColor3f(1,1,1);
		glTranslatef(-15,0,0);
		glScalef(0.015, 0.015, 0.015); // diminui o tamanho do fonte
		glLineWidth(3); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"VOCE CONSEGUIU !!");
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"  Teste o jogo 2 =D");
		
	glPopMatrix();
	
	glColor3f(0.93, 0.93, 0.06);
	drawCircleFill(-37,23,5,90);
	
	//petalas
	glPushMatrix();
	
		glColor3f(1,1,1);
		drawCircleFill(3,23,2,90);
		drawCircleFill(-3,23,2,90);
		drawCircleFill(-1.5,20,2,90);
		drawCircleFill(1.5,20,2,90);
		drawCircleFill(-1.5,26,2,90);
		drawCircleFill(1.5,26,2,90);
		
		
	
	glPopMatrix();
	
	
	//centro
	glColor3f(0.98, 0.95, 0.05);
	
	drawCircleFill(0,23,3,90);
	
	
	glFlush();
	// Exibe o desenha na janela
	glutSwapBuffers();
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
	glTranslatef(-60,25,0);
	glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(4); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"THE SOWING GAME");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,1);
	
	glScalef(1, 1.4, 1);
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-90,-20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"\n Gabriel Dias  || Ualace  || Edeilton  || Gabriel Cosmo \n");
	glColor3f(1,1,1);
	glRasterPos2f(-70,-50);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"||Aperte com o botao direito do mouse para o menu||");
	// Exibe o desenha na janela
	glutSwapBuffers();
}


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

//representação da semente
void Semente()
{
			
	glColor3f(0.28f, 0.48f, 0.0f);
	drawCircleFill(0,17,1,90);
	glBegin(GL_TRIANGLES);
		glColor3f(0.34f, 0.4f, 0.0f);
		glVertex2f(0,20);
		glColor3f(0.1f, 0.5f, 0.0f);
		glVertex2f(-1.0,17);
		glColor3f(0.34f, 0.16f, 0.0f);
		glVertex2f(1,17);
	glEnd();
	
}

//representação da agua
void Gota()
{
			
	glColor3f(0.0f, 0.6f, 1.0f);
	drawCircleFill(0,17,1,90);
	glBegin(GL_TRIANGLES);
		glVertex2f(0,20);
		glVertex2f(-1.0,17);
		glVertex2f(1,17);
	glEnd();
	
}

//representação do sol
void Sol()
{
	glColor3f(1.0f, 1.0f, 0.0f);
	drawCircleFill(-0,0,1.5,90);
	
	//gota de agua

}

//desenha as linhas verdes divisorias	
void Retas(float x1, float y1, float x2, float y2)
{
	//glColor3f(0,1,0);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	
} 
int pausa = 1;  //int para executar apenas uma vez apos acertar
void enigma(void){
	int i  ;
	// Define a cor de fundo da janela de visualização como marrom
	glClearColor(0.5, 0.21, 0.04, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// Inicio das retas superiores e inferiores
	glPushMatrix();
		
		glColor3f(0,1,0);
		glTranslatef(0,13,0);
		Retas(-37.5,0,37.5,0);
	
	glPopMatrix();
	
	glPushMatrix();
		
		glColor3f(0,1,0);
		glTranslatef(0,-13,0);
		Retas(-37.5,0,37.5,0);
	
	glPopMatrix();
	//Final das retas 
	
	//primeiro sinal de adição
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(-18,0,0);
		Retas(-1,0,1,0);
		glRotatef(90,0,0,1);
		Retas(-1,0,1,0);
		
	glPopMatrix();
	
	//segundo sinal de adição
	glPushMatrix();
	
		glColor3f(0,0,0);	
		glTranslatef(0,0,0);
		Retas(-1,0,1,0);
		glRotatef(90,0,0,1);
		Retas(-1,0,1,0);
		
	glPopMatrix();
	
	//sinal de igualdade
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(0,-0.5,0);
		glTranslatef(18,0.75,0);
		Retas(-1,0,1,0);
		glTranslatef(0,-0.75,0);
		Retas(-1,0,1,0);
		
	glPopMatrix();
	
	glPushMatrix();	// Desenha os textos em amarelo para demarcar onde os objetos devem ir
	
		glColor3f(0.08, 0.71, 0.9);
		glRasterPos2f(-10.25,-4); 
		DesenhaTexto(GLUT_BITMAP_9_BY_15,"Agua ");
		
		
		glColor3f(0.04, 0.7, 0.08);
		glRasterPos2f(-31,-4); 
		DesenhaTexto(GLUT_BITMAP_9_BY_15,"Semente ");
		
		glColor3f(0.97, 0.94, 0.03);
		glRasterPos2f(8.25,-4); 
		DesenhaTexto(GLUT_BITMAP_9_BY_15,"Sol ");
	
	glPopMatrix();
	
	
	glPushMatrix();	//translação em 5 unidades no eixo x
	
	glTranslatef(5,0,0);
	
	
	//Desenha a semente e a gota na posição correta
	glPushMatrix();
	
		glTranslatef(-5,0,0);
		Semente();
				
		glTranslatef(25,0,0);
		Gota();
		
	glPopMatrix();
	
	//desenha o sol na posição correta
	glPushMatrix();
	
		glTranslatef(-29,18,0);
		Sol();
	
	glPopMatrix();
	
	//Desenha o numero 1 na posição correta
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(-29.25,14.5,0);
		glScalef(0.01, 0.01, 0.01); // diminui o tamanho do fonte
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"1");
			
	glPopMatrix();
	
	//Desenha o numero 2 na posição correta
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(-5.25,14.5,0);
		glScalef(0.01, 0.01, 0.01); // diminui o tamanho do fonte
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"2");
			
	glPopMatrix();
	
	//Desenha o numero 3 na posição correta
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(19.6,14.5,0);
		glScalef(0.01, 0.01, 0.01); // diminui o tamanho do fonte
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"3");
			
	glPopMatrix();
	
	//Desenha a interrogaçao na posição correta
	glPushMatrix();
	
		glColor3f(0,0,0);
		glTranslatef(19.6,-4,0);
		glScalef(0.07, 0.07, 0.07); // diminui o tamanho do fonte
		glLineWidth(3); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"?");
			
	glPopMatrix();
	
	
	
	glPushMatrix();			//Desenha o texto em amarelo
	
		glColor3f(0,0,0);
		glTranslatef(-28,22,0);
		glScalef(0.015, 0.015, 0.015); // diminui o tamanho do fonte
		glLineWidth(3); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"PRESSIONE OS NUMEROS NA ORDEM PEDIDA");
			
	glPopMatrix();
	
	
	glPushMatrix();			//Desenha o texto em amarelo
	
		glColor3f(0,0,0);
		glTranslatef(-21,-20,0);
		glScalef(0.015, 0.015, 0.015); // diminui o tamanho do fonte
		glLineWidth(3); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,"E VENCA O GRANDE ENIGMA !!");
		
	glPopMatrix();
	
	glPopMatrix();			//Pop da translação de 5 no eixo x
	

	for(i=0;i<3;i++)		//Esse for serve para desenhar os objetos em cada local
	{
		
		if(i == 0)
		{
			glPushMatrix();
			
				
				if(entrada[i] == 1)
				{
					glTranslatef(-28.8,0,0);
					Sol();
				}
				else if(entrada[i] == 2)
				{
					glTranslatef(-28.75,-18,0);
					Semente();
				}
				else if(entrada[i] == 3)
				{
					glTranslatef(-28.75,-18,0);
					Gota();
				}	
				
			glPopMatrix();
		}
		
		if(i == 1)
		{
			glPushMatrix();
			

				
				if(entrada[i] == 1)
				{
					glTranslatef(-9,0,0);
					Sol();
				}
				else if(entrada[i] == 2)
				{
					glTranslatef(-9,-18,0);
					Semente();
				}
				else if(entrada[i] == 3)
				{
					glTranslatef(-9,-18,0);
					Gota();
				}	
			
			glPopMatrix();
		}
		
		if(i == 2)
		{
			glPushMatrix();
			
				
				if(entrada[i] == 1)
				{
					glTranslatef(9,0,0);
					Sol();
				}
				else if(entrada[i] == 2)
				{
					glTranslatef(9,-18,0);
					Semente();
				}
				else if(entrada[i] == 3)
				{
					glTranslatef(9,-18,0);
					Gota();
				}	
				
			glPopMatrix();
		}
		
		//Ualace
		glutPostRedisplay(); 		//Isso resolve o grande enigma
	}
	
	if(entrada[0] == verif[0] && entrada[1] == verif[1] && entrada[2] == verif[2] && pausa == 1) 
	{
		pausa = 0;
		printf("Voce solucionou o grande enigma.");
		printf("\n %d", pausa);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );  
		glutInitWindowPosition(100,30);  //Define a posição inicial na tela, do canto superior esquerdo a janela   
		glutInitWindowSize(1080,720);  //Define o tamanho inicial da janela GLUT que será criada
		glutCreateWindow("Recompensa");
		glutDisplayFunc(flor);
		// Registra a função callback de redimensionamento da janela de visualização
		//	glutReshapeFunc(AlteraTamanhoJanela); 
		// Registra a função callback para tratamento das teclas especiais
		glutSpecialFunc(TeclasEspeciais);   
		glutKeyboardFunc (Teclado);
		// Chama a função responsável por fazer as inicializações 
		Inicializa2();
			//Iniciar
					//O código chega nessa parte se o jogador desvendou o grande enigma e ganhou o jogo
	}

	glFlush();
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
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"# Aperte ESC para sair ou botao direito do mouse para opcoes");
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
	glRasterPos2f(-90,24); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"JOGO PLANTIO: ");
    glRasterPos2f(-90,20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 1 para selecionar a Semente ");
	glRasterPos2f(-90,14); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 2 para selecionar o Sol ");
	glRasterPos2f(-90,8);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> 3 para selecionar a Agua");
	glRasterPos2f(-90,2);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"JOGO ARVORE:");
	glRasterPos2f(-90,-4);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> PGUP/ PGDN para rotacionar arvore");
	glRasterPos2f(-90,-10);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Setas para cima e para baixo para crescer");
	glRasterPos2f(-90,-16);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"GERAIS:");
	glRasterPos2f(-90,-22);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> ESC para sair do jogo");
	glRasterPos2f(-90,-28);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"--> Botao direito do mouse para opcoes");

	// Exibe o desenha na janela
	glutSwapBuffers();
}

void arvore(void){
	
	
	glClearColor(0.11, 0.63, 0.93, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//desenha o sol
	glColor3f(1.0f, 1.0f, 0.2f);  //sol
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
		case 1: //Jogo Enigma
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );  
			glutInitWindowPosition(100,30);  //Define a posição inicial na tela, do canto superior esquerdo a janela   
			glutInitWindowSize(1080,720);  //Define o tamanho inicial da janela GLUT que será criada
			glutCreateWindow("Enigma");
			glutDisplayFunc(enigma);
			// Registra a função callback de redimensionamento da janela de visualização
			// Registra a função callback para tratamento das teclas especiais
			glutSpecialFunc(TeclasEspeciais);   
			glutKeyboardFunc (Teclado);
			// Chama a função responsável por fazer as inicializações 
			Inicializa2();
							
			break;
		
		case 2: //arvore
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
		    
		case 3: //Comandos    
			comandos();
			break;
		case 4: 
			//Sobre o Jogo
		    sobre();
		    break;	
		    
		case 5: 
			exit(0);
		    break;
	}	
}           


// Criacao do Menu
void menuSystem() 
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Jogo 1 - Plantio",1);
    glutAddMenuEntry("Jogo 2 - Crescimento",2);
    glutAddMenuEntry("Comandos",3);
    glutAddMenuEntry("Sobre o Jogo",4);
    glutAddMenuEntry("Sair",5);
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
