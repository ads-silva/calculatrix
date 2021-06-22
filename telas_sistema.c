#include "includes.h"
/* Fun็ใo padrใo de cabe็alho que ้ chamada ao construir a tela
 * nใo sendo necessแrio reescrever a cada nova tela.
 */
void telaCabecalho(){
    clrscr();
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("|");
	textcolor(LIGHTGREEN);
	printf("                                  CALCULATRIX                                ");
	textcolor(WHITE);
    printf("|\n");
    printf("+อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ+");
}

/* Fun็ใo padrใo para exibir bordas e rodapes nas telas principais */
void telaBorda_Rodape(){
    int i;
    /* Desenha a borda direita */
    for (i = 4; i < 25; i++){
        gotoxy(1,i);
        printf("|\n");
    }

    /* Desenha a borda esquerda */
    for (i = 4; i < 25; i++){
        gotoxy(79,i);
        printf("|\n");
    }
    gotoxy(1,25);
    printf("+อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ+");
}

/* Imprime uma mensagem de encerramento, logo depois do escape do menu e emcerra o sistema */
void telaEncerrar(){
    clrscr();
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("|");
	textcolor(LIGHTGREEN);
	printf("                                SISTEMA ENCERRADO                            ");
	textcolor(WHITE);
    printf("|\n");
	printf("+อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ+");
	quebra(1);
    pressionar();
    telaBorda_Rodape();
	getch();
	ExitProcess(0);
}

/* tela do menu principal */
void telaMenuPrincipal(){
    telaCabecalho();
    quebra(2);
    printf("                          ษ---------------------------ป\n");
    printf("                          |    CALCULO DE MATRIZES    |\n");
    printf("                          +---------------------------+\n");
	printf("                          |                           |\n");
	printf("                          |       1 - Soma            |\n");
	printf("                          |       2 - Subtracao       |\n");
	printf("                          |       3 - Transposta      |\n");
	printf("                          |       4 - Produto         |\n");
    printf("                          |       5 - Escalar         |\n");
    printf("                          |       6 - Cramer          |\n");
    printf("                          |       7 - Sarrus          |\n");
    printf("                          |       8 - Fila Circular   |\n");
    printf("                          |                           |\n");
    printf("                          |       9 - Sair            |\n");
	printf("                          |                           |\n");
	printf("                          +---------------------------+\n");
	quebra(1);
	printf("                                   Selecione:\n");
    quebra(2);
    telaBorda_Rodape();

    /* Posiciona o cursor no canto direito e imprime a versao do sistema. */
    gotoxy(66,24);
    textcolor(LIGHTGREEN);
    printf("Versao: 2.00");
    textcolor(WHITE);
    getLogin();
}

/* Tela de apresentacao do programa*/
void telaApresentacao(){
    telaCabecalho();
    quebra(6);
    printf("                            ษ------------------------ป\n");
	printf("                            |                        |\n");
	printf("                            |      CALCULATRIX       |\n");
    printf("                            |                        |\n");
	printf("                            +------------------------+\n");
	quebra(2);
    pressionar();
    quebra(9);
    telaBorda_Rodape();
    gotoxy(63,16);
    pause();
}

/* Tela de erro de senha*/
void telaErroSenha(){
    telaCabecalho();
    quebra(8);
	textcolor(LIGHTRED);
    printf("                     ษ-------------------------------------ป\n");
	printf("                     |                                     |\n");
    printf("                     |     USUARIO OU SENHA INVALIDOS!     |\n");
    printf("                     |                                     |\n");
	printf("                     +-------------------------------------+\n");
	textcolor(WHITE);
    quebra(1);
    pressionar();
    quebra(7);
    telaBorda_Rodape();
	gotoxy(63,17);
    pause();
	login();
}

/* Tela de erro de exercicio */
void telaErroExe(char c[50],char x[50]){
    telaCabecalho();
    quebra(8);
	textcolor(LIGHTRED);
	gotoxy(15,11);
    printf("%s\n",c);
    gotoxy(15,12);
    printf("%s\n",x);
	textcolor(WHITE);
    quebra(1);
    pressionar();
    quebra(7);
    telaBorda_Rodape();
	gotoxy(63,14);
    pause();
}

/* Tela de login */
void telaLogin(){
    telaCabecalho();
	quebra(8);
    printf("                          ษ------------------------ป\n");
	printf("                          |                        |\n");
    printf("                          | USUARIO:_____________  |\n");
	printf("                          |   SENHA:_____________  |\n");
    printf("                          |                        |\n");
	printf("                          +------------------------+\n");
	quebra(8);
    telaBorda_Rodape();
}

/* Funcao que imprime a mensagem para pressionar qualquer tecla */
void pressionar(){
    printf("                     Pressione qualquer tecla para continuar:");
    clreol();
}

