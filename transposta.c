#include "includes.h"
void transposta(){
    int i, j;

    /* Exibe o cabecalho */
    telaCabecalhoExe("                             * MATRIZ TRANSPOSTA *");
    limpaLinha(1,7,15);
    printf("|  Tamanho da matriz:");
    quebra(2);

    /* Captura a entrada de linhas e colunas */
    int linha = getLinhas();
    int coluna = getColunas();

    int matriz1[linha][coluna];
    int matriz2[coluna][linha];

    /* Valida o tamanhp maximo da matriz */
    if(linha <= 4 && coluna <=4){
        limpaLinha(1,7,15);
        printf("|  Preencha Matriz:");
        quebra(2);

        /* Funcao para popular a matriz */
        preencheMatriz(matriz1, linha, coluna, 1, 8);
    }else{
        exibeErro(" * Tamanho invalido! *");
        transposta();
    }

    for(i=0; i< linha; i++){
        for(j=0; j<coluna; j++){
            matriz2[j][i] = matriz1[i][j];
        }
    }

    /* Imprime o resultado ja em verde */
    exibeResultado(matriz2,coluna,linha,38,12);

    /* Rodape da tela */
    telaRodapeFixoExe();
}
