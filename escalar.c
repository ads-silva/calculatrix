#include "includes.h"
void escalar(){
    int i, j, numero = 0;

    /* Exibe o cabecalho */
    telaCabecalhoExe("                         * MULTIPLICACAO POR ESCALAR *");
    limpaLinha(1,7,15);
    printf("| Tamanho da matriz:");
    quebra(2);

    /* Captura a entrada de linhas e colunas */
    int linha = getLinhas();
    int coluna = getColunas();

    int matriz1[linha][coluna];
    int matriz2[linha][coluna];

    /* Valida o tamanhp maximo da matriz */
    if(linha <= 4 && coluna <=4){
        limpaLinha(1,7,15);
        printf("| Preencha Matriz:");
        quebra(2);

        /* Funcao para popular a matriz */
        preencheMatriz(matriz1, linha, coluna, 1, 8);

        /* Função para exibir a matriz */
        exibeMatriz(matriz1,linha,coluna,30,9);
        exibeOperacao("*");
    }else{
        exibeErro(" * Tamanho invalido! *");
        escalar();
    }

    limpaLinha(1,7,15);
    printf("|  Multiplicar por: ");

    /* Atribui o valor a numero */
    fflush(stdin);
    scanf("%d", &numero);
    limpaLinha(1,9,10);

    /* Exibe o numero no lado direito */
    gotoxy(55,8);
    printf("+----+\n");
    gotoxy(55,9);
    printf("| %d\n",numero);
    gotoxy(60,9);
    printf("|");
    gotoxy(55,10);
    printf("+----+\n");

    /* Faz o calculo */
    for(i=0; i< linha; i++){
        for(j=0; j<coluna; j++){
            matriz2[i][j] = matriz1[i][j] * numero;
        }
    }

    /* Imprime o resultado ja em verde */
    exibeResultado(matriz2,linha,coluna,41,17);

    /* Rodape da tela */
    telaRodapeFixoExe();
}
