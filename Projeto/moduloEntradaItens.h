typedef struct entrada Entrada;
struct entrada
{
    char codigodeBarras [20];
    char quantProduto [20];
    int dia, mes, ano;
    char status;
};

void menuEntradaItens(void);
char telaRegistrarEntrada(void);
void infoEntrada(void);
void pesquisarEntrada(void);
void atualizarEntrada(void);
void excluirEntrada(void);
void listarEntrada(void);
void buscaInfoEntrada(void);
void exibeEntrada(Entrada* ent);
void gravaEntrada(Entrada*);