#include "includes.h"
void sarrus(){
    int dt = 0, ordem, m1[3][3], m2[3][5],m3[2][2], m4[1][1];
    /* Exibe o cabecalho */
    telaCabecalhoExe("                        * SOLUCAO SISTEMA POR SARRUS *");
    /* Limpa o lado esquerdo da tela e reposiciona o cursor */
    limpaLinha(1,7,15);
    printf("|  Matriz de ordem: ");
    scanf("%d",&ordem);
    quebra(2);

    if(ordem > 0 & ordem < 4){
        if(ordem == 3){
            limpaLinha(1,7,15);
            printf("|  Preencha a matriz:");
            quebra(2);

            /* Popula a matriz*/
            preencheMatriz(m1, 3, 3, 1, 8);
            limpaLinha(1,7,15);

            /* Resolve o determinante */
            setMatrizSarrus(m2,m1,3,5,3);
            dt = getResultadoSarrus(m2,3,5,3);

            /* Reultado */
            exibeMatriz(m2,3,5,30,8);
            gotoxy(32,15);
            textcolor(LIGHTGREEN);
            printf(" Determinante: %d", dt);
            textcolor(WHITE);
        }

        if(ordem == 2){
            limpaLinha(1,7,15);
            printf("|  Preencha a matriz:");
            quebra(2);

            /* Popula a matriz*/
            preencheMatriz(m3, 2, 2, 1, 8);
            limpaLinha(1,7,15);

            /* Resolve o determinante */
            dt = (m3[0][0] * m3[1][1]) - (m3[1][0] * m3[0][1]);

            /* Reultado */
            exibeMatriz(m3,2,2,36,9);
            gotoxy(32,15);
            textcolor(LIGHTGREEN);
            printf(" Determinante: %d", dt);
            textcolor(WHITE);
        }

        if(ordem == 1){
            limpaLinha(1,7,15);
            printf("|  Preencha a matriz:");
            quebra(2);

            /* Popula a matriz*/
            preencheMatriz(m4, 1, 1, 1, 8);
            limpaLinha(1,7,15);

            /* Reultado */
            exibeMatriz(m4,1,1,37,9);
            gotoxy(32,15);
            textcolor(LIGHTGREEN);
            printf(" Determinante: %d", m4[0][0]);
            textcolor(WHITE);
        }
    }else{
        limpaLinha(1,7,15);
        exibeErro("   * Matriz de ordem invalida *");
        sarrus();
    }
    /* Rodape da tela */
    telaRodapeFixoExe();
}
