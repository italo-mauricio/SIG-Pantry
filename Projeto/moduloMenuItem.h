//struct para cadastro do item
typedef struct item Item;
struct item
{
    char nomeProduto[20];
    char nomeMarca[20];
    int dia;
    int mes;
    int ano;
    int diaEnt;
    int mesEnt;
    int anoEnt;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    char codigoBarras[20];
    char status;
    int estoqueMinimo; //transformar para int
    char categoria[10];
    char localArmazenamento[50];
    int quantProduto;  //transformar para int
   
};

typedef struct mov Mov;
struct mov
{

    char codigoBarras[20];
    int diaEnt;
    int mesEnt;
    int anoEnt;
    int quantMovimento;
    char tipo;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    
};

//assinatura das funções do arquivo .c
void moduloMenuItem(void);
char telaRegistrarItem(void);
void infoItem(void);
int listarItens(void);
int buscaInfoItem(void);
int telaAtualizarItem(void);
char escAtualizarItem(void);
int excluirItem(void);
int gravaItem(Item* it);
int gravaMov(Mov* mv);
int entradaItem(void);
int saidaItem(void);