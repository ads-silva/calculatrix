#include "includes.h"
/* Função cabeçalho personalizada com parâmetro char[], passando o nome da operação
 * normalmente é utilizada para construir telas subsequentes as do menu.
 */
void telaCabecalhoExe(char c[80]){
    clrscr();
	printf("+=============================================================================+\n");
	printf("|");
	textcolor(LIGHTGREEN);
	printf("%s",c);
	textcolor(WHITE);
	gotoxy(79,2);
    printf("|\n");
	printf("+=============================================================================+");
	quebra(1);
	telaBorda_Rodape();
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

/* Funcao que exibe fila circular */
void exibeFilaCircular(int *fila, int x, int y){
    int i;
    /* Desenha na tela as posicoes do vetor */
    gotoxy(x,y-2);
    printf("  0   1   2   3   4   5   6   7   8   9");
    gotoxy(x,y-1);
    printf("+---------------------------------------+");
    gotoxy(x,y);
    printf("|   |   |   |   |   |   |   |   |   |   |");
    gotoxy(x,y+1);
    printf("+---------------------------------------+");

    /* Imprime o conteudo do vetor dentro do desenho */
    gotoxy(x+1,y);
    for(i = 0; i < 10; i++){
        x++;
        gotoxy(x,y);
        /* Se for igual a 0 */
        if(fila[i] == 0){
            /* imprime um espaco */
            printf(" ");
        }else{
            /* Se nao imprime o vetor indexado */
            printf(" %d", fila[i]);
        }
        x = x + 3;
    }
}

void exibeStatusFilaCircular(int *fila, int i_primeiro, int i_ultimo, int qtde){
    /* imprime o relatorio com o status na tela */
    textcolor(LIGHTGREEN);
    gotoxy(32,12);
    printf("+----------------------+----------------+");
    gotoxy(32,13);
    printf("|      INFORMACAO      |     VALOR      |");
    gotoxy(32,14);
    printf("+----------------------+----------------+");
    textcolor(WHITE);
    gotoxy(32,15);
    printf("| Primeiro elemento    |                |");
    gotoxy(32,16);
    printf("+----------------------+----------------+");
    gotoxy(32,17);
    printf("| Ultimo elemento      |                |");
    gotoxy(32,18);
    printf("+----------------------+----------------+");
    gotoxy(32,19);
    printf("| Quantidade           |                |");
    gotoxy(32,20);
    printf("+----------------------+----------------+");
    gotoxy(32,21);
    printf("| Status               |                |");
    gotoxy(32,22);
    printf("+----------------------+----------------+");

    /* Equaliza valores valores de exibicao */
    i_primeiro--;
    if(i_ultimo == 10){
        i_ultimo = 0;
    }

    /* Apenas exibe os valores quando a quantidade for diferente de 0 */
    if(qtde > 0){
        gotoxy(61,15);
        printf("%d -> %d", i_primeiro, fila[i_primeiro]);
        gotoxy(61,17);
        printf("%d -> %d", i_ultimo, fila[i_ultimo]);
    }

    /* Mostra a quantidade */
    gotoxy(63,19);
    printf("%d", qtde);
    gotoxy(60,21);

    /* Valida se a fila esta cheia ou vazia atravez da quantidade */
    if(qtde > 0 & qtde < 10){/* Normal */
        textcolor(LIGHTGREEN);
        printf("Normal");
        textcolor(WHITE);
    }
    if(qtde == 0){
        textcolor(LIGHTRED);
        printf("Underflow");/* Vazia */
        textcolor(WHITE);
    }
    if(qtde == 10){
        textcolor(LIGHTRED);
        printf("Overflow");/* Cheia */
        textcolor(WHITE);
    }
}

/* Tela do menu da fila circular */
void telaMenuCircular(){
    limpaLinha(1,6,17);
    printf("|   +-----------------+\n");
    printf("|   |    ELEMENTOS    |\n");
    printf("|   +-----------------+\n");
	printf("|   |                 |\n");
	printf("|   |   1 - Inserir   |\n");
	printf("|   |   2 - Remover   |\n");
	printf("|   |                 |\n");
	printf("|   |   3 - Sair      |\n");
    printf("|   |                 |\n");
    printf("|   +-----------------+\n");
    quebra(2);
    printf("|   Selecione:\n");
}

