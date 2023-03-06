//struct para a montagem da lista
typedef struct createList CreateList;
struct createList
{
    char name[20];
    int quantityProduct;
    char status;
    char usernameUser[20];

};

//cabeçalho das funções usadas no arquivo.c
void menulistadeCompras(void);
char shoppingListScreen(void);
int itensQuantMinima(void);
int infoBuildList(void);
void displayShoppingList(CreateList *list);
int listaComprasPronta(void); 
int saveList(CreateList* mtlist);
int searchListByUsername(char *username);
void pesquisarLista(void);
int updateList(void);
int excluirLista(void);
char screenUpdateList(void); 