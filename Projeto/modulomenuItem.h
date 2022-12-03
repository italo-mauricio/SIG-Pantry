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
    char estoqueMinimo[20];  // PASSAR PARA INT
    char categoria[10];
    char localArmazenamento[50];
    char quantProduto[20];  // PASSAR PARA INT ALTERAR A CADA ENTRADA E SAIDA

   
};

//cabeçalho das funções usadas no arquivo .c
void modulomenuItem(void);
char telaMenuItens(void);
void infoItem(void);
int listarItens(void);
int infoExcluir(void);
void suitefuncao(char);
int telaAtualizarItem(void);
int buscarItem(void);
char telaLocaldeArmazenamento(void);
char escAtualizarItem(void);
int gravaItem(Item* it);
void exibeItens(Item* it);

