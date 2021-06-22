#include "includes.h"
/** Biblioteca com funções padrões do sistema.
  */
char logado[25];
/* Função que define o tamanho da tela e titulo */
void screenSize(int x, int z){
    HANDLE wHnd;
    HANDLE rHnd;

    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    /* define o titulo*/
    SetConsoleTitle("CALCULATRIX - v2.00");

    SMALL_RECT windowSize = {0, 0, x, z};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    COORD bufferSize = {10, 10};

    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

/* Função que define o scrollbar */
void remove_scrollbar(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

/* Função que seta o tamanho, as cores, e o scroolbar */
void configuraLayout(){
    textcolor(WHITE);
    textbackground(BLUE);
    screenSize(80,25);
    remove_scrollbar();
}

/* Funcao que seta o nome do susuario*/
void setLogin(char c[]){
    strcpy(logado, c);
}

/* Funcao que imprime o usuario logado. */
void getLogin(){
    if(strlen(logado) > 0){
        gotoxy(2,4);
        printf("USUARIO: ");
        textcolor(LIGHTGREEN);
        printf("%s",strupr(logado));
        textcolor(WHITE);
    }
}

/* Função para imprimir no console a quebra de linha
 * de acordo com a quantidade informada no parâmetro */
void quebra(int linha){
int i = 0;
    for(i = 0; i< linha; i++){
        printf("\n");
    }
}

/* Funcao para limpar linhas de acordo com a posicao do cursor*/
void limpaLinha(int x, int y, int n){
    int i;
    gotoxy(x,y);
    for (i = 0; i < n; i++){
        printf("|                      \n");
    }
    gotoxy(x,y);
}

/* Função para imprimir mensagem de erro personalizada. */
void exibeErro(char msg[50]){
    limpaLinha(1,7,15);
    quebra(1);
    printf("|");
    textcolor(LIGHTRED);
    printf(msg);
    textcolor(WHITE);
    pause();
}

/* Captura uma entrada do teclado e em seguida limpa o buffer */
void pause(){
    getch();
    setbuf(stdin,NULL);
    fflush(stdin);
}

/* Funcao responsavel pela validacao do login */
void login(){
    char usuario[25];
    int retorno_s = 0;
    char *senha;
    char str[25];
    str[0] = 'a';

    /* Chama a tela de login */
    telaLogin();

    /* captura a entrada: usuario */
    gotoxy(37,13);
    gets(usuario);
    fflush(stdin);

    /* captura a entrada: senha */
    gotoxy(37,14);
    senha = getpass(NULL, &str);
    fflush(stdin);

    /* Compara a senha e retorna '0' se for igual */
    retorno_s = strcmp(senha, "123");

    /* verifica retorno_s */
    if(retorno_s == 0){
        /* Se for '0'
        /* Seta o nome do usuario logado na variavel global */
        setLogin(usuario);
        /* Chama o menu principal */
        MenuPrincipal();
    }
    /* Se nao, mostra erro de senha */
    telaErroSenha();
}

/* Funcao responsavel pelas acoes do menu principal */
void MenuPrincipal(){
    char opcao_menu[1];

    /* Chama a tela do menu*/
    telaMenuPrincipal();

    /* Captura a entrada de dados */
    /* Executa funcoes de acordo com a entrada do usuario */
    gotoxy(47,22);
    fflush(stdin);
	switch (atoi(gets(opcao_menu))){
        case 9:
            telaEncerrar();
		break;
        case 1:
            subtracaoSoma("+");
		break;
		case 2:
            subtracaoSoma("-");
		break;
		case 3:
            transposta();
		break;
		case 4:
            produto();
        break;
		case 5:
            escalar();
        break;
		case 6:
            cramer();
        break;
        case 7:
            sarrus();
        break;
        case 8:
            inicializaFilaCircular();
        break;
		default:
            MenuPrincipal();
        break;
	}
}
