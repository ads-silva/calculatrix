#include "includes.h"
void cramer(){
    int dp = 0, dx = 0, dy = 0, dz = 0, m1[3][4], m2[3][5], temp[3][4];
    float x,y,z;
    /* Exibe o cabecalho */
    telaCabecalhoExe("                        * SOLUCAO SISTEMA 3X3 POR CRAMER *");
    /* Limpa o lado esquerdo da tela e reposiciona o cursor */
    limpaLinha(1,7,15);
    printf("|  Preencha o Sistema:");
    /* Pula duas linhas */
    quebra(2);

    /* Popula a matriz */
    preencheSistema(m1, 3, 4, 1, 8, "XYZ=");
    /* Limpa o lado esquerdo da tela e reposiciona o cursor */
    limpaLinha(1,7,15);

    /** Resolve o determinante principal */
    /* Faz a copia da matriz m1 para matriz temporaria temp */
    replicaMatriz(temp, m1,3,4);
    /* Monta o esquema de Sarrus com colunas adicionais */
    setMatrizSarrus(m2,m1,3,5,4);
    /* Efetua a multiplicacao das diagonais e retorna atribuindo na variavel dp */
    dp = getResultadoSarrus(m2,3,5,3);

    /** Resolve o determinante Ax */
    /* Copia a coluna depois do igual para coluna 0 */
    SetColuna(m1,m1,3,4,3,0);
    /* Monta o esquema de Sarrus com colunas adicionais */
    setMatrizSarrus(m2,m1,3,5,4);
    /* Restaura a matriz m1 copiando da matriz temp */
    replicaMatriz(m1,temp,3,4);
    /* Efetua a multiplicacao das diagonais e retorna atribuindo na variavel dx */
    dx = getResultadoSarrus(m2,3,5,3);

    /** Resolve o determinante Ay */
    /* Copia a coluna depois do igual para coluna 1 */
    SetColuna(m1,m1,3,4,3,1);
    /* Monta o esquema de Sarrus com colunas adicionais */
    setMatrizSarrus(m2,m1,3,5,4);
    /* Restaura a matriz m1 copiando da matriz temp */
    replicaMatriz(m1,temp,3,4);
    /* Efetua a multiplicacao das diagonais e retorna atribuindo na variavel dy */
    dy = getResultadoSarrus(m2,3,5,3);

    /** Resolve o determinante Az */
    /* Copia a coluna depois do igual para coluna 2 */
    SetColuna(m1,m1,3,4,3,2);
    /* Monta o esquema de Sarrus com colunas adicionais */
    setMatrizSarrus(m2,m1,3,5,4);
    /* Restaura a matriz m1 copiando da matriz temp */
    replicaMatriz(m1,temp,3,4);
    /* Efetua a multiplicacao das diagonais e retorna atribuindo na variavel dz */
    dz = getResultadoSarrus(m2,3,5,3);

    /* Valida se o sistema e S.P.I */
    if (dp == 0 & dx == 0){
        textcolor(LIGHTGREEN);
        gotoxy(30,11);
        printf("* RESULTADO *");
        gotoxy(30,13);
        printf("SISTEMA S.P.I");
        textcolor(WHITE);
    }else{
        /* Valida se o sistema e S.I */
        if(dp == 0 & dx != 0){
            textcolor(LIGHTGREEN);
            gotoxy(30,11);
            printf("* RESULTADO *");
            gotoxy(30,13);
            printf("SISTEMA S.I");
            textcolor(WHITE);
        }else{
            /* Senao exibe o resultado S.P.D*/
            /* Divide variaveis pela determinante principal */
            x = dx / dp;
            y = dy / dp;
            z = dz / dp;

            gotoxy(25,6);
            printf("Det Ap = %d ",dp);
            gotoxy(25,8);
            printf("Det Ax = %d ",dx);
            gotoxy(25,9);
            printf("Det Ay = %d ",dy);
            gotoxy(25,10);
            printf("Det Az = %d ",dz);
            gotoxy(2,5);

            gotoxy(25,13);
            printf("Det Ax            Det Ay             Det Az");
            gotoxy(24,14);
            printf("--------          --------           --------");
            gotoxy(25,15);
            printf("Det Ap            Det Ap             Det Ap");

            gotoxy(33,14);
            printf("= %3.2f", x);
            gotoxy(51,14);
            printf("= %3.2f", y);
            gotoxy(70,14);
            printf("= %3.2f", z);

            gotoxy(25,19);
            textcolor(LIGHTGREEN);
            printf("CONJUNTO SOLUCAO: S = {( %3.2f , %3.2f , %3.2f )}", x,y,z);
            gotoxy(50,21);
            printf("SISTEMA S.P.D");
            textcolor(WHITE);
        }
    }

    /* Rodape da tela */
    telaRodapeFixoExe();
}
