typedef struct montarLista MontarLista;
struct montarLista
{
    char nome[20];
    char nomeLista[20];
    char categoriaProduto[10];
    char quantidadeProduto[15];
    char status;
};

//cabeçalho das funções usadas no arquivo.c
void menulistadeCompras(void);
char telaListadeCompras(void);
void telaItensQuantMinima(void);
void telaItensProxVencimento(void);
void infoMontarLista(void);
void exibeListaCompras(MontarLista* mtlista);
void listaComprasPronta(void); //relatório
void gravaLista(MontarLista*);
void buscaLista(void);
void pesquisarLista(void);
void editarLista(void);
void excluirLista(void);