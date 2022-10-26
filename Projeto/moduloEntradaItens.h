void menuEntradaItens(void);
char telaEntradaItens(void);
void telaRegistrarEntrada(void);
void telaCancelarEntrada(void);

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

Entrada* infoEntrada( );
CancelarEnt* infoCancelarEntrada( );