/* Função padrão de cabeçalho que é chamada ao construir a tela
 * não sendo necessário reescrever a cada nova tela.
 */
void telaCabecalho(){
    LOGIN lg;
    clrscr();
	printf("+=============================================================================+\n");
	printf("|");
	textcolor(LIGHTRED);
	printf("                                  CALCULATRIX                                ");
	textcolor(WHITE);
    printf("|\n");
	printf("+=============================================================================+");
}

/* Função rodapé padrão */
void telaRodape(){
	printf("+=============================================================================+");
	getLogin();
}

/* Função cabeçalho personalizada com parâmetro int, para identificar a operação
 * normalmente é utilizada para construir telas subsequentes as do menu.
 */
void telaCabecalhoExe(int x){
    clrscr();
	printf("+=============================================================================+\n");
	printf("|");
	textcolor(LIGHTRED);
	printf("                                  OPERACAO %d                                 ",x);
	textcolor(WHITE);
    printf("|\n");
	printf("+=============================================================================+");
	quebra(2);
}

/* (FIXO) Rodapé padrão para as telas subsequentes as telas do menu
 * pressionando uma tecla, volta ao menu principal.
*/
void telaRodapeFixoExe(){
    gotoxy(1,23);
    quebra(1);
	printf("+==================================== FIM ====================================+");
    quebra(1);
    pressionar();
	pause();
    MenuPrincipal();
}

/* Imprime uma mensagem de encerramento, logo depois do escape do menu e emcerra o sistema */
void telaEncerrar(){
    clrscr();
	printf("+=============================================================================+\n");
	printf("|");
	textcolor(LIGHTRED);
	printf("                                SISTEMA ENCERRADO                            ");
	textcolor(WHITE);
    printf("|\n");
	printf("+=============================================================================+");
	quebra(1);
    pressionar();
	getch();
	ExitProcess(0);
}

/* tela do menu principal */
void telaMenuPrincipal(){
    telaCabecalho();
    quebra(2);
    printf("                          +---------------------------+\n");
    printf("                          |    CALCULO DE MATRIZES    |\n");
    printf("                          +---------------------------+\n");
	printf("                          |                           |\n");
	printf("                          |       1 - Soma            |\n");
	printf("                          |       2 - Subtracao       |\n");
	printf("                          |       3 - Transposta      |\n");
	printf("                          |       4 - matriz 4        |\n");
    printf("                          |       5 - matriz 5        |\n");
    printf("                          |       6 - matriz 6        |\n");
    printf("                          |       7 - matriz 7        |\n");
    printf("                          |                           |\n");
    printf("                          |       9 - Sair            |\n");
    printf("                          |                           |\n");
	printf("                          +---------------------------+\n");
	quebra(2);
	printf("                                   Selecione:\n");
    quebra(2);
    telaRodape();

    /* Posiciona o cursor no canto direito e imprime a versao do sistema. */
    gotoxy(67,24);
    textcolor(LIGHTGREEN);
    printf("Versao: 1.30");
    textcolor(WHITE);
}

/* Tela de apresentacao do programa*/
void telaApresentacao(){
    telaCabecalho();
    quebra(6);
    printf("                            +------------------------+\n");
	printf("                            |                        |\n");
	printf("                            |      CALCULATRIX       |\n");
    printf("                            |                        |\n");
	printf("                            +------------------------+\n");
	quebra(2);
    pressionar();
    quebra(9);
    telaRodape();
    gotoxy(63,16);
    pause();
}

/* Tela de erro de senha*/
void telaErroSenha(){
    telaCabecalho();
    quebra(8);
	textcolor(LIGHTRED);
    printf("                     +-------------------------------------+\n");
	printf("                     |                                     |\n");
    printf("                     |     USUARIO OU SENHA INVALIDOS!     |\n");
    printf("                     |                                     |\n");
	printf("                     +-------------------------------------+\n");
	textcolor(WHITE);
    quebra(1);
    pressionar();
    quebra(7);
    telaRodape();
	gotoxy(63,17);
    pause();
	login();
}

/* Tela de login */
void telaLogin(){
    telaCabecalho();
	quebra(8);
    printf("                          +------------------------+\n");
	printf("                          |                        |\n");
    printf("                          | USUARIO:_____________  |\n");
	printf("                          |   SENHA:_____________  |\n");
    printf("                          |                        |\n");
	printf("                          +------------------------+\n");
	quebra(8);
    telaRodape();
}

/* Funcao que imprime a mensagem para pressionar qualquer tecla */
void pressionar(){
    printf("                     Pressione qualquer tecla para continuar:");
}
