typedef struct montarLista MontarLista;
struct montarLista
{
    char nome[20];
    char categoriaProduto[10];
    char quantidadeProduto[15];
    char status;
};

//cabeçalho das funções usadas no arquivo.c
void menulistadeCompras(void);
char telaListadeCompras(void);
//char itensQuantMinima(void);
//void itensProxVencimento(void);
void infoMontarLista(void);
void exibeListaCompras(MontarLista* mtlista);
void listaComprasPronta(void); //relatório
void gravaLista(MontarLista*);
void buscarLista(void);
void pesquisarLista(void);
void atualizarLista(void);
void excluirLista(void);
char escAtualizarLista(void);