void menuEntradaItens(void);
char telaEntradaItens(void);

typedef struct entrada Entrada;
struct entrada
{
    char codigodeBarras [20];
    char quantProduto [20];
};

typedef struct cancelarent CancelarEnt;
struct cancelarent
{
    char codigoBarras [20];
};

void infoEntrada(void);
void infoCancelarEntrada(void);
//void gravaEnt(Entrada*);