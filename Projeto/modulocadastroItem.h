typedef struct item Item;
struct item
{
    char nomeProduto [20];
    char nomeMarca [20];
    int dia;
    int mes;
    int ano;
    char codigoBarras [20];
    char status;
    char estoqueMinimo [20];
};

void modulocadastroItem(void);
char telaMenuItens(void);
void infoItem(void);
void exibeItens(Item* it);
void listarItens(void);
void infoExcluir(void);
void suitefuncao(char);
void gravaItem(Item*);
void telaAtualizarItem(void);
void buscarItem(void);

char telaCategoriadoProduto(void);
char telaLocaldeArmazenamento(void);
char telaAtualizarCategoria(void);
char telaAtualizarLocaldeArmazenamento(void);


