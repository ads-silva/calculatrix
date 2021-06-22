#include "includes.h"
/* Captura o numero de linhas e retorna*/
int getLinhas(){
    int linhas = 0;
    gotoxy(1,9);
    printf("| Linhas: ");

    /* Limpa buffer de entrada de dados */
    fflush(stdin);

    /* Atribui o valor a linhas */
    scanf("%d", &linhas);
    limpaLinha(1,9,10);

    /* Valida a entrada */
    if (linhas > 0 && linhas < 999){
        gotoxy(1,9);
        printf("| Linhas: %d", linhas);
        return linhas;
    }else{
        getLinhas();
    }
}

/* Captura o numero de colunas e retorna*/
int getColunas(){
    int colunas = 0;
    gotoxy(1,10);
    printf("| Colunas: ");

    /* Limpa buffer de entrada de dados */
    fflush(stdin);

    /* Atribui o valor a colunas */
    scanf("%d", &colunas);
    limpaLinha(1,10,10);

    /* Valida a entrada */
    if (colunas > 0 && colunas < 999){
        limpaLinha(1,7,15);
        return colunas;
    }else{
        getColunas();
    }
}

/* Imprime a operacao */
void exibeOperacao(char op[1]){
    textcolor(LIGHTRED);
    gotoxy(49,9);
    printf(op);
    textcolor(WHITE);
}

/* preenche matriz */
void preencheMatriz(int *m, int linha, int coluna, int cursorX, int cursorY){
    int i, j;
    for (i = 0; i < linha; i++){
        limpaLinha(cursorX,cursorY,15);
        textcolor(LIGHTRED);
        gotoxy(cursorX+3, cursorY+1);
        printf("Linha %d:", i+1);
        textcolor(WHITE);
        for (j = 0; j < coluna; j++){
            gotoxy(cursorX+3, cursorY+j+2);
            printf("Coluna %d: ", j+1);
            scanf("%d", &*(m + (i * coluna) + j));
        }
        limpaLinha(cursorX,cursorY,15);
    }
}

/* preenche sistema */
void preencheSistema(int *m, int linha, int coluna, int cursorX, int cursorY, char c[]){
    int i, j;
    for (i = 0; i < linha; i++){
        limpaLinha(cursorX,cursorY,15);
        textcolor(LIGHTRED);
        gotoxy(cursorX+3, cursorY+1);
        printf("Equacao %d:", i+1);
        textcolor(WHITE);
        for (j = 0; j < coluna; j++){
            gotoxy(cursorX+11, cursorY+j+2);
            printf("%c: ", c[j]);
            fflush(stdin);
            scanf("%d", &*(m + (i * coluna) + j));
        }
        limpaLinha(cursorX,cursorY,15);
    }
}

/* Imprime a matriz na tela */
void exibeMatriz(int *m, int linha, int coluna, int cursorX, int cursorY){
    int i, j, tmpCursorX;
    /* faz uma copia da variavel para uso posterior */
    tmpCursorX = cursorX;

    /* imprime as coluas na horizontal uma linha antes do valor original */
    gotoxy(cursorX,cursorY-2);
    for (i = 0; i < coluna; i++){
        printf("  %d ", i+1);
    }

    /* imprime a linha inicial */
    gotoxy(cursorX,cursorY-1);
    for (i = 0; i < coluna; i++){
        printf("+---");
    }
    printf("+");

    /* Percorre as linhas até i < l */
    for (i = 0; i < linha; i++){

        /* Retorna o cursosr quatro colunas */
        gotoxy(cursorX-4,cursorY);

        /* Imprime o numero da linha */
        printf("  %d ", i+1);

        /* Percorre cada coluna até i < j*/
        for (j = 0; j < coluna; j++){

            /* Posiciona o cursor no valor original*/
            gotoxy(cursorX,cursorY);
            printf("|");

            /* Posiciona o cursor avancando mais uma coluna*/
            gotoxy(cursorX+1,cursorY);

            /* Imprime o conteudo do endereço usando geometria de ponteiro */
            printf("%d", *(m + (i * coluna) + j));

            /* Coluna avança mais quatro */
            cursorX = cursorX + 4;
        }
        /* Posiciona o cursor */
        gotoxy(cursorX,cursorY);
        printf("|\n");

        /* Linha avança + um  */
        cursorY++;

        /* Coluna recebe valor original. */
        cursorX = tmpCursorX;
    }

    /* imprime a linha final */
    gotoxy(cursorX,cursorY);
    for (i = 0; i < coluna; i++){
        printf("+---");
    }
    printf("+");
}

/* Imprime a matriz na tela */
void exibeResultado(int *m, int linha, int coluna, int cursorX, int cursorY){
    limpaLinha(1,7,15);
    gotoxy(cursorX-16,cursorY);
    textcolor(LIGHTGREEN);
    printf("Resultado:");

    int i, j, tmpCursorX;
    /* faz uma copia da variavel para uso posterior */
    tmpCursorX = cursorX;

    /* imprime as coluas na horizontal uma linha antes do valor original */
    gotoxy(cursorX,cursorY-2);
    for (i = 0; i < coluna; i++){
        printf("  %d  ", i+1);
    }

    /* imprime a linha inicial */
    gotoxy(cursorX,cursorY-1);
    for (i = 0; i < coluna; i++){
        printf("+----");
    }
    printf("+");

    /* Percorre as linhas até i < l */
    for (i = 0; i < linha; i++){

        /* Retorna o cursosr quatro colunas */
        gotoxy(cursorX-4,cursorY);

        /* Imprime o numero da linha */
        printf("  %d ", i+1);

        /* Percorre cada coluna até i < j*/
        for (j = 0; j < coluna; j++){

            /* Posiciona o cursor no valor original*/
            gotoxy(cursorX,cursorY);
            printf("|");

            /* Posiciona o cursor avancando mais uma coluna*/
            gotoxy(cursorX+1,cursorY);

            /* Imprime o conteudo do endereço usando geometria de ponteiro */
            printf("%d", *(m + (i * coluna) + j));

            /* Coluna avança mais quatro */
            cursorX = cursorX + 5;
        }
        /* Posiciona o cursor */
        gotoxy(cursorX,cursorY);
        printf("|\n");

        /* Linha avança + um  */
        cursorY++;

        /* Coluna recebe valor original. */
        cursorX = tmpCursorX;
    }

    /* imprime a linha final */
    gotoxy(cursorX,cursorY);
    for (i = 0; i < coluna; i++){
        printf("+----");
    }
    printf("+");
    textcolor(WHITE);
}

 /* Transfere a ultima coluna da matriz 1 para a matriz 2 na coluna especificada */
void SetColuna(int *m2, int *m1, int linha, int coluna, int origem, int destino){
    int i,j;
    for (i = 0; i < linha; i++){
        *(m2 + (i * coluna) + destino) = *(m1 + (i * coluna) + origem);
    }
}

 /* Realiza o calculo de Sarrus */
 /* (matriz, linha, coluna, limite de colunas no loop) */
int getResultadoSarrus(int *m, int linha, int coluna, int coluna_max){
    int i,j,dt,cont,soma, mult;

    /* Calcula a soma da miltiplicacao das diagonais primarias */
    soma =0 , mult = 1;
    for(j = 0; j < linha; j++){
        for(i = 0; i < coluna_max; i++){
            mult = mult * (*(m + (i * coluna) + j+i));
        }
        soma = soma + mult;
        mult = 1;
    }

    /* Armazena o resutado das diagonais primarias */
    dt = soma;

    /* Calcula a soma da miltiplicacao das diagonais secundarias */
    soma =0 , mult = 1;
    for(j = 0; j < coluna_max; j++){
        cont = 0;
        for(i = linha-1; i > -1; i--){
            mult = mult * (*(m + (i * coluna) + j+cont));
            cont++;
        }
        soma = soma + mult;
        mult = 1;
    }
    /* Subtrai principal com secundaria */
    dt = dt - soma;
    return dt;
}

/* Funcao que faz copia do conteudo de uma matriz para outra */
/* (matriz destino, matriz origem, linha, coluna) */
void replicaMatriz(int *m2, int *m1, int linha, int coluna){
    int i,j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            *(m2 + (i * coluna) + j) = *(m1 + (i * coluna) + j);
        }
    }
}

 /* Copia da matriz 1 para a matriz 2 Replicando a primeira e segunada coluna no final */
void setMatrizSarrus(int *m2, int *m1, int l, int c, int h){
    int i,j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(j == 3){
                *(m2 + (i * c) + 3) = *(m1 + (i * h) + 0);
            }else if( j == 4){
                *(m2 + (i * c) + 4) = *(m1 + (i * h) + 1);
            }else{
                *(m2 + (i * c) + j) = *(m1 + (i * h) + j);
            }
        }
    }
}
