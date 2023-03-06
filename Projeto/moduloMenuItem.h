//struct para cadastro do item
typedef struct item Item;
struct item
{
    char productName[30];
    char nameBrand[30];
    int day; //vencimento
    int month; //vencimento
    int year; //vencimento
    int dayEntry;
    int monthEntry;
    int yearEntry;
    int dayExit;
    int monthExit;
    int yearExit;
    char barCode[20];
    char status;
    int minimumInventory; 
    char category;
    char storageLocation;
    int quantProduct;
    char usernameUser[30];  
    char dateToday[40];
    char tipe;
    int quantEntry;
    int quantExit;

};


//assinatura das funções do arquivo .c
void moduloMenuItem(void);
char screenRegisterItem(void);
int infoItem(void);
int listarItens(void);
int searchItemInfo(void);
int updateItemScreen(void);
char updateItemMenu(void);
int deleteItem(void);
int saveItem(Item* it); 
int entradaItem(void);
int saidaItem(void);
char categoryScreen(void);
char scrennStorageLocation(void);
int validaCod(char* item);
void displayItemInfo(Item* it);
char* verDiaMesAno(void);