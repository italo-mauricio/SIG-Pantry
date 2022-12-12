
typedef struct noItem NoItem;

struct noItem 
{
    char nomeProduto[20];
    char nomeMarca[20];
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
    int estoqueMinimo; 
    char categoria;
    char localArmazenamento;
    int quantProduto;
    char usernameUsuario[20];  
    char dataAtual[40]; 
    NoItem* prox;

};


//cabeçalho da função usada no arquivo.c
char telaRelatorio(void);
char moduloRelatorio (void);
char relatorioLocalArmaz(void);
char relatorioCategoria(void);
void escRelatoriosCategoria(void);
void escRelatoriosLocal(void);
int exibirItensHigiene(void);
int exibirItensLimpeza(void);
int exibirItensAlimento(void);
int exibirGeladeira(void);
int exibirArmarioCozinha(void);
int exibirAreaServ(void);
int exibirGuardaRoupa(void);
int exibirBanheiro(void);
NoItem* listaOrdenadaItens(void);
void exibeOrdemItem(NoItem* lista);