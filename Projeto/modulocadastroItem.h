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


void telaEstoqueMinimo(void);
char telaCategoriadoProduto(void);
char telaLocaldeArmazenamento(void);
char telaAtualizarCategoria(void);
char telaAtualizarLocaldeArmazenamento(void);


