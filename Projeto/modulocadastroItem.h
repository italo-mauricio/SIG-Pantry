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

typedef struct atualNome AtualNome;
struct atualNome 
{
    char nome[30];
};

typedef struct atualCodigo AtualCodigo;
struct atualCodigo 
{
    char codBarras [13];
};

typedef struct atualData AtualData;
struct atualData
{
    int dia, mes, ano;
};

typedef struct excluirItem ExcluirItem;
struct excluirItem
{
    char barra [13];
};

void modulocadastroItem(void);
char telaMenuItens(void);
void infoItem(void);
void exibeItens(Item* it);
void listarItens(void);
void infoExcluir(void);
void suitefuncao(char);
void gravaItem(Item*);

//ANALISAR:
void telaEstoqueMinimo(void);
char telaCategoriadoProduto(void);
char telaLocaldeArmazenamento(void);
void telaAtualizarItem(void);
char telaAtualizarCategoria(void);
char telaAtualizarLocaldeArmazenamento(void);

//REFAZER EDIÇÃO
AtualNome* atualizNome();
AtualCodigo* atualizCodigo();
AtualData* atualizData();

