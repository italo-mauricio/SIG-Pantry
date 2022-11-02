void menuEntradaItens(void);
char telaEntradaItens(void);

typedef struct entrada Entrada;
struct entrada
{
    char codigodeBarras [15];
    char quantProduto [13];
};

typedef struct cancelarent CancelarEnt;
struct cancelarent
{
    char codigodeBarras [15];
};

void infoEntrada(void);
void infoCancelarEntrada(void);
void gravaEnt(Entrada*);