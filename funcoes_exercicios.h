/* Captura o numero de linhas e retorna*/
int getLinhas(){
    int linhas = 0;
    gotoxy(1,9);
    printf("  Linhas: ");
    scanf("%d", &linhas);
    return linhas;
}

/* Captura o numero de colunas e retorna*/
int getColunas(){
    int colunas = 0;
    printf(" Colunas: ");
    scanf("%d", &colunas);
    return colunas;
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
        printf("\n  Linha %d: \n\n", i+1);
        textcolor(WHITE);
        for (j = 0; j < coluna; j++){
            printf("  Coluna %d: ", j+1);
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
    textcolor(WHITE);
}
