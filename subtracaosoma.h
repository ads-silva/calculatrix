void subtracaoSoma(char op[1]){
    int i, j, linha = 0, coluna = 0;
    /* Exibe o cabecalho */
    telaCabecalhoExe(1);
    printf("                        * SOMA E SUBTRACAO DE MATRIZES *");
    quebra(2);

    /* Primeira matriz */
    limpaLinha(1,7,15);
    printf("  Tamanho da matriz 1:");
    quebra(2);

    /* Captura a entrada de linhas e colunas */
    linha = getLinhas();
    coluna = getColunas();

    int matriz1[linha][coluna];

    /* Valida o tamanhp maximo da matriz */
    if(linha <= 4 && coluna <=4){
        printf("  Preencha Matriz 1:");
        quebra(2);

        /* Funcao para popular a matriz */
        preencheMatriz(matriz1, linha, coluna, 2, 8);
    }else{
        exibeErro(" * Tamanho invalido! *");
        subtracaoSoma(op);
    }
    exibeMatriz(matriz1,linha,coluna,30,9);

    /* imprime a operacao na tela */
    exibeOperacao(op);

    /* segunda matriz */
    int matriz2[linha][coluna];
    limpaLinha(1,7,15);

    printf("  Preencha Matriz 2:");
    quebra(2);

    /* Funcao para popular a matriz */
    preencheMatriz(matriz2, linha, coluna, 2, 8);

    /* Função para exibir a matriz */
    exibeMatriz(matriz2,linha,coluna,54,9);

    /* Calculo da matriz1 e matriz2  */
    int matriz3[linha][coluna];
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            switch (op[0]){
                case '+':
                    matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                break;
                case '-':
                    matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
                break;
            }
        }
    }

    /* Imprime o resultado ja em verde */
    exibeResultado(matriz3,linha,coluna,41,17);

    /* Rodape da tela */
    telaRodapeFixoExe();
}
