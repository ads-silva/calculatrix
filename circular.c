#include "includes.h"
/* Inicializa a fila circular */
void inicializaFilaCircular(){
    /* Exibe o cabecalho */
    telaCabecalhoExe("                              * FILA CIRCULAR *");
    /* Declara variaveis */
    int i, fila[10], qtde = 0, i_primeiro = 0, i_ultimo = 0;
    /* Zera os elementos do vetor */
    for(i = 0; i < 10; i++){
        fila[i] = 0;
    }
    /* Executa o exercicio da fila circular */
    exibeCircular(fila, i_primeiro, i_ultimo, qtde);
}

/* Executa a exibicao e logo depois o menu da fila circular */
void exibeCircular(int *fila, int i_primeiro, int i_ultimo, int qtde){
    /* Exibe a fila circular */
    exibeFilaCircular(fila, 32,8);

    /* Exibe status geral do vetor */
    exibeStatusFilaCircular(fila, i_primeiro, i_ultimo, qtde);

    /* Executa o menu de manipulacao do vetor */
    MenuCircular(fila, i_primeiro, i_ultimo, qtde);
}

/* Insere valor na fila circular */
void inserirNaFila(int *fila, int i_primeiro, int i_ultimo, int qtde){
    /* Valiada quantidade maxima da fila se for diferente de 10 */
    if(qtde != 10){
        int numero;
        /* Limpa 18 linhas abaixo na posicao 1,6 e retorna para a mesma posicao */
        limpaLinha(1,6,18);
        printf("|  Numero: ");
        /* Limpa o buffer */
        fflush(stdin);
        /* Entrada de dados do usuario */
        scanf("%d",&numero);
        /* Valida o numero digitado, mario que 0 e menor que 100 */
        if(numero > 0 & numero < 100){
            /* Valida o index do vetor, quando passar de 9 chegou ao fim do vetor
             * e reinicializa o index.*/
            if(i_primeiro > 9){
                /* Index volta a zero, ou seja, comeca no inicio do vetor */
                i_primeiro = 0;
                /* Atribui o valor na fila pelo index i_primeiro */
                fila[i_primeiro] = numero;
                /* Incrementa o index i_primeiro e qdte */
                i_primeiro++;
                qtde++;
            }else{
                /* Atribui o valor na fila pelo index i_primeiro */
                fila[i_primeiro] = numero;
                /* Incrementa i index i_primeiro e qdte */
                i_primeiro++;
                qtde++;
            }
            /* Volta no comeco do exercicio, com parametros atualizados */
            exibeCircular(fila, i_primeiro, i_ultimo, qtde);
        }else{
            /* Limpa 18 linhas abaixo na posicao 1,6 e retorna para a mesma posicao */
            limpaLinha(1,6,18);
            exibeErro(" * Numero Invalido *");
            /* Repete a funcao inserirNaFila */
            inserirNaFila(fila, i_primeiro, i_ultimo, qtde);
        }
    /* Se estiver cheio mostra a mensagem */
    }else{
        limpaLinha(1,6,18);
        exibeErro("    * Overflow *");
        /* Volta no comeco do exercicio, com parametros atualizados */
        exibeCircular(fila, i_primeiro, i_ultimo, qtde);
    }
}

/* Funcao responsavel para retirar valor da fila */
void removerDaFila(int *fila, int i_primeiro, int i_ultimo, int qtde){
    if(qtde != 0){
        /* Valida o index do vetor, quando chegar a 10 chegou ao fim do vetor
         * e reinicializa o index.*/
        if(i_ultimo > 9){
            /* Index volta a zero, ou seja, comeca no inicio do vetor */
            i_ultimo = 0;
            /* Atribui o valor na fila pelo index i_primeiro */
            fila[i_ultimo] = 0;
            /* Incrementa o index i_ultimo e decrementa a qdte */
            i_ultimo++;
            qtde--;
        }else{
            /* Atribui o valor na fila pelo index i_primeiro */
            fila[i_ultimo] = 0;
            /* Incrementa o index i_ultimo e decrementa a qdte */
            i_ultimo++;
            qtde--;
        }
        /* Volta no comeco do exercicio, com parametros atualizados */
        exibeCircular(fila, i_primeiro, i_ultimo, qtde);
    }else{
        limpaLinha(1,6,18);
        exibeErro("    * Underflow *");
        /* Volta no comeco do exercicio, com parametros atualizados */
        exibeCircular(fila, i_primeiro, i_ultimo, qtde);
    }
}

/* Menu para manipular o vetor circular */
void MenuCircular(int *fila, int i_primeiro, int i_ultimo, int qtde){
    char opcao_menu[1];

    /* Chama a tela do menu*/
    telaMenuCircular();

    /* Captura a entrada de dados */
    /* Executa funcoes de acordo com a entrada do usuario */
    gotoxy(16,18);
    fflush(stdin);
	switch (atoi(gets(opcao_menu))){
        case 1:
            /* Funcao de insercao de elemento no vetor */
            inserirNaFila(fila, i_primeiro, i_ultimo, qtde);
		break;
        case 2:
            /* Funcao de remocao de elemento no vetor */
            removerDaFila(fila, i_primeiro, i_ultimo, qtde);
		break;
		case 3:
		    /* Retorna ao menu principal do programa */
            MenuPrincipal();
		break;
		default:
		    /* Volta no comeco do exercicio, com parametros atualizados */
            exibeCircular(fila, i_primeiro, i_ultimo, qtde);
        break;
	}
}
