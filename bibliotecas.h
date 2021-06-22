/* funcoes_sistema.c */
void screenSize(int x, int z);
void remove_scrollbar();
void configuraLayout();
void setLogin(char c[]);
void getLogin();
void quebra(int linha);
void limpaLinha(int x, int y, int n);
void exibeErro(char msg[50]);
void pause();
void login();
void MenuPrincipal();

/* funcoes_exercicios.c */
int getLinhas();
int getColunas();
void exibeOperacao(char op[1]);
void preencheMatriz(int *m, int linha, int coluna, int cursorX, int cursorY);
void preencheSistema(int *m, int linha, int coluna, int cursorX, int cursorY, char c[]);
void exibeMatriz(int *m, int linha, int coluna, int cursorX, int cursorY);
void exibeResultado(int *m, int linha, int coluna, int cursorX, int cursorY);
void SetColuna(int *m2, int *m1, int linha, int coluna, int origem, int destino);
int getResultadoSarrus(int *m, int linha, int coluna, int coluna_max);
void replicaMatriz(int *m2, int *m1, int linha, int coluna);
void setMatrizSarrus(int *m2, int *m1, int l, int c, int h);

/* telas_sistema.c */
void telaCabecalho();
void telaBorda_Rodape();
void telaEncerrar();
void telaMenuPrincipal();
void telaApresentacao();
void telaErroSenha();
void telaErroExe(char c[50],char x[50]);
void telaLogin();
void pressionar();

/* telas_exercicios.c */
void telaCabecalhoExe(char c[80]);
void telaRodapeFixoExe();
void exibeFilaCircular(int *fila, int x, int y);
void exibeStatusFilaCircular(int primeiro, int ultimo, int qtde, int status);
void telaMenuCircular();


/* subtracaoSoma.c */
void subtracaoSoma(char op[1]);
/* transposta.c */
void transposta();
/* produto.c */
void produto();
/* escalar.c */
void escalar();
/* cramer.c */
void cramer();
/* sarrus.c */
void sarrus();

/* circular.c */
void inicializaFilaCircular();
void circular(int *fila, int p, int u);
void inserirNaFila(int *fila, int primeiro, int ultimo, int qtde, int status);
void removerDaFila(int *fila, int i_primeiro, int i_ultimo, int qtde);
void MenuCircular(int *fila, int primeiro, int ultimo, int qtde, int status);
