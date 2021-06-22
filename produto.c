#include "includes.h"
void produto(){
    int i, j, x, l, c, soma, cont2 = 0,linha_m1 = 0, coluna_m1 = 0, linha_m2 = 0, coluna_m2 = 0;
    /* Exibe o cabecalho */
    telaCabecalhoExe("                             * PRODUTO DE MATRIZES *");

    /* Primeira matriz */
    limpaLinha(1,7,15);
    printf("|  Tamanho da matriz 1:");
    quebra(2);

    /* Captura a entrada de linhas e colunas */
    linha_m1 = getLinhas();
    coluna_m1 = getColunas();

    /* Declara a Primeira matriz */
    int matriz1[linha_m1][coluna_m1];

    /* Valida o tamanho maximo da matriz */
    if(linha_m1 <= 3 && coluna_m1 <=3){
        printf("|  Preencha Matriz 1:");
        quebra(2);

        /* Funcao para popular a matriz */
        preencheMatriz(matriz1, linha_m1, coluna_m1, 1, 8);

        /* Função para exibir a matriz */
        exibeMatriz(matriz1,linha_m1,coluna_m1,30,9);
    }else{
        exibeErro(" * Tamanho invalido! *");
        produto();
    }

    /* imprime a operacao na tela */
    exibeOperacao("*");

    /* Segunda matriz */
    limpaLinha(1,7,15);
    printf("|  Tamanho da matriz 2:");
    quebra(2);

    /* Captura a entrada de linhas e colunas */
    linha_m2 = getLinhas();
    coluna_m2 = getColunas();

    /* Declara a segunda matriz */
    int matriz2[linha_m2][coluna_m2];

    /* Valida o tamanho maximo */
    if(linha_m2 <= 3 && coluna_m2 <=3){

        /* Valida a regra matematica para multiplicacao de matrizes */
        if(coluna_m1 == linha_m2){
            limpaLinha(1,7,15);
            printf("|  Preencha Matriz 2:");
            quebra(2);

            /* Funcao para popular a matriz */
            preencheMatriz(matriz2, linha_m2, coluna_m2, 1, 8);

            /* Função para exibir a matriz */
            exibeMatriz(matriz2,linha_m2, coluna_m2,54,9);
        }else{
            telaErroExe("* Numero de coluna da matriz 1,", "* deve ser igual o numero de linhas da matriz 2!");
            produto();
        }
    }else{
        exibeErro(" * Tamanho invalido! *");
        produto();
    }
/* ------------------------ Fim da captura de dados --------------------------------------*/


/* -------------------------- Inicio dos calculos ----------------------------------------*/
    /* inicializando terceira matriz */
    int matriz3[linha_m1][coluna_m2];

    /* Declara vetor para armazenar o resultado final */
    int vet3[linha_m1*coluna_m2];

    /* Percorrendo a matriz 1 */
    for(i = 0; i < linha_m1 ; i++){
        for(j = 0; j < coluna_m2; j++){

            /* Declara vetores auxiliares */
            int vet1[coluna_m1];
            int vet2[linha_m2];

            /* Armazena todas as colunas de uma linha da primeira matriz em um vetor*/
            for(x = 0; x < coluna_m1; x++){
                vet1[x] = matriz1[i][x];

            }

            /* Percorrendo a matriz 2 */
            for(l = 0; l < linha_m2; l++){
                for(c = 0; c < coluna_m2; c++){

                    /* Se o numero da da linha da matriz 1 for igual o numero da coluna da matriz 2 */
                    /* Armazenado no vetor varias linhas de apenas uma coluna */
                    if (j == c){
                        vet2[l] = matriz2[l][c];
                    }
                }
            }

            /* soma recebe a soma de cada mutiplicacao */
            soma = 0;
            for(x = 0; x < coluna_m1; x++){
                soma = soma + (vet1[x] * vet2[x]);

            }
            /* armazena a soma das multiplicacoes em um vetor */
            vet3[cont2] = soma;
            cont2++;
        }
    }

    /* Percorrendo a matriz 3 */
    /* Passando do vetor para a matriz */
    x = 0;
    for(i = 0; i < linha_m1 ; i++){
        for(j = 0; j < coluna_m2 ; j++){
            matriz3[i][j] = vet3[x];
            x++;
        }
    }

    /* Imprime a matriz resultado na cor verde */
    exibeResultado(matriz3,linha_m1,coluna_m2,41,17);

    /* Rodape da tela */
    telaRodapeFixoExe();
}
