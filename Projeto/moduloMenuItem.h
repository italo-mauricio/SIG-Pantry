//struct para cadastro do item
typedef struct item Item;
struct item
{
    char nomeProduto[30];
    char nomeMarca[30];
    int dia; //vencimento
    int mes; //vencimento
    int ano; //vencimento
    int diaEnt;
    int mesEnt;
    int anoEnt;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    char codigoBarras[20];
    char status;
    int minimumInventory; 
    char categoria;
    char localArmazenamento;
    int quantProduct;
    char usernameUsuario[30];  
    char dataAtual[40];
    char tipo;
    int quantEntrada;
    int quantSaida;

};


//assinatura das funções do arquivo .c
void moduloMenuItem(void);
char telaRegistrarItem(void);
int infoItem(void);
int listarItens(void);
int buscaInfoItem(void);
int telaAtualizarItem(void);
char escAtualizarItem(void);
int excluirItem(void);
int gravaItem(Item* it);
int entradaItem(void);
int saidaItem(void);
char telaEscCategoria(void);
char telaEscLocalArmaz(void);
int validaCod(char* item);
void exibeInfoItem(Item* it);
char* verDiaMesAno(void);