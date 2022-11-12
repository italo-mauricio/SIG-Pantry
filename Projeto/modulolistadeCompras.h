typedef struct montarLista MontarLista;
struct montarLista
{
    char nome[20];
    char categoriaProduto[10];
    char quantidadeProduto[15];
};

//cabeçalho das funções usadas no arquivo.c
void menulistadeCompras(void);
char telaListadeCompras(void);
void telaItensQuantMinima(void);
void telaItensProxVencimento(void);
char telaAdicionarItensaLista(void);
void infoMontarLista(void);
void exibeListaCompras(void);
void gravaLista(MontarLista*);