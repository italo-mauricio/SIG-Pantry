//struct para cadastro do item
typedef struct item Item;
struct item
{
    char nomeProduto[20];
    char nomeMarca[20];
    int dia;
    int mes;
    int ano;
    char codigoBarras[20];
    char status;
    char estoqueMinimo[20];
    char categoria[10];
    char localArmazenamento[50];
  
};

//cabeçalho das funções usadas no arquivo .c
void modulocadastroItem(void);
char telaMenuItens(void);
void infoItem(void);
void listarItens(void);
void infoExcluir(void);
void suitefuncao(char);
void gravaItem(Item*);
void telaAtualizarItem(void);
void buscarItem(void);
char telaLocaldeArmazenamento(void);
char escAtualizarItem(void);


