void moduloSaidaItens(void);
char telaSaidaItens(void);

typedef struct saida Saida;
struct saida
{
    char codigodeBarras[15];
    char QuantProduto[13];
    char status;
};

typedef struct cancelarsaid CancelarSaid;
struct cancelarsaid
{
    char codigodeBarras[15];
    char QuantProduto[13];
    char status;
};

Saida* infoSaida(void);
CancelarSaid* infoCancelarSaid(void);
void gravaSaida(Saida*);
void gravaCancelamentoSaida(CancelarSaid*);
