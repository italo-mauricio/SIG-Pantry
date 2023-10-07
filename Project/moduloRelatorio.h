
typedef struct noItem NoItem;

struct noItem 
{
    char relatoryProductName[20];
    char relatoryBrandName[20];
    int relatoryDay; //vencimento
    int relatoryMonth; //vencimento
    int relatoryYear; //vencimento
    int diaEnt;
    int mesEnt;
    int anoEnt;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    char relatoryBarCode[20];
    char status;
    int minimumStock; 
    char categoryAux;
    char localStorage;
    int quantProductAux;
    char usernameUsuario[20];  
    char dataAtual[40]; 
    NoItem* prox;

};


//cabeçalho da função usada no arquivo.c
void displayInfoItem(Item* it);
char relatoryScreen(void);
char moduleRelatory(void);
char relatoryCategory(void);
void menuCategory(void);
char stockRelatoryLocal(void);
char relatorioCategoria(void);
void escRelatoriosCategoria(void);
void menuLocalRelatory(void);
int displayHygieneItens(void);
int displayCleaningItens(void);
int displayFoodItens(void);
int displayRefrigerator(void);
int displayKitchenCabinet(void);
int displayServiceArea(void);
int displayCloset(void);
int displayBathroom(void);
NoItem* ordenedListItens(void);
void displayOrderItem(NoItem *lista);