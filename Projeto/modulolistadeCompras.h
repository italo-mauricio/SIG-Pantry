//struct para a montagem da lista
typedef struct createList CreateList;
struct createList
{
    char nome[20];
    int quantidadeProduto;
    char status;
    char usernameUsuario[20];

};

//cabeçalho das funções usadas no arquivo.c
void menulistadeCompras(void);
char shoppingListScreen(void);
int itensQuantMinima(void);
int infoMontarLista(void);
void exibeListaCompras(CreateList* mtlist);
int listaComprasPronta(void); 
int gravaLista(CreateList*);
int buscarLista(void);
void pesquisarLista(void);
int atualizarLista(void);
int excluirLista(void);
char escAtualizarLista(void);