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
    char estoqueMinimo[20]; //transformar para int
    char categoria[10];
    char localArmazenamento[50];
    char quantProduto[20];  //transformar para int
   
};

//assinatura das funções do arquivo .c
void menuEntradaItens(void);
char telaRegistrarEntrada(void);
void infoEntrada(void);
int listarEntradas(void);
int buscaInfoEntrada(void);
int telaAtualizarEntrada(void);
char escAtualizarEntrada(void);
int excluirEntrada(void);
int gravaItem(Item* it);