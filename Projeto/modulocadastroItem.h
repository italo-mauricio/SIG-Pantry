//cabeçalho das funções usadas no arquivo.c
void modulocadastroItem(void);
char telaMenuItens(void);
void telaEstoqueMinimo(void);
char telaCategoriadoProduto(void);
char telaLocaldeArmazenamento(void);
void telaAtualizarItem(void);
char telaAtualizarCategoria(void);
char telaAtualizarLocaldeArmazenamento(void);
void telaExcluirItem(void);
void suitefuncao(char);

typedef struct item Item;
struct item
{
    char nomeProduto [20];
    char nomeMarca [20];
    int dia, mes, ano;
    char codigoBarras [13];
};

typedef struct datav DataV;
struct datav{
    int dia;
    int mes;
    int ano;
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


Item* infoItem( );
DataV* veriDatav( );
AtualNome* atualizNome();
AtualCodigo* atualizCodigo();
AtualData* atualizData();