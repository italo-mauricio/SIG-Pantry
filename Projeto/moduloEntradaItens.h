void menuEntradaItens(void);
char telaEntradaItens(void);

typedef struct entrada Entrada;
struct entrada
{
    char codigodeBarras [20];
    char quantProduto [20];
    char status;
};

typedef struct cancelarent CancelarEnt;
struct cancelarent
{
    char codigoBarras [20];
    char status;
};

Entrada* infoEntrada(void);
CancelarEnt* infoCancelarEntrada(void);
void gravaEntrada(Entrada*);
void gravaCancelamentoEnt(CancelarEnt*);