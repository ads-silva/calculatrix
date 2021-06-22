#include "includes.h"
#include "bibliotecas.h"


int main() {
    /* Seta o layout e as cores do console*/
    configuraLayout();
    /* Tela de apresentação.*/
    telaApresentacao();
    /* Efetua o login no sistema*/
    login();
    /* Executa o menu principal.*/
    MenuPrincipal();
    /*Retorna 0 e finaliza o sistema*/
	return 0;
}
