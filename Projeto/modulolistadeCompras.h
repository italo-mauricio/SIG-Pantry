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
int infoMontarLista(void);
void exibeListaCompras(MontarLista* mtlista);
int listaComprasPronta(void); //relatório
int gravaLista(MontarLista*);
int buscarLista(void);
void pesquisarLista(void);
int atualizarLista(void);
int excluirLista(void);
char escAtualizarLista(void);