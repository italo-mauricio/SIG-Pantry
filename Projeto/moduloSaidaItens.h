void moduloSaidaItens(void);
char telaSaidaItens(void);

typedef struct saida Saida;
struct saida
{
    char codigodeBarras[15];
    char QuantProduto[13];
};

typedef struct cancelarsaid CancelarSaid;
struct cancelarsaid
{
    char codigodeBarras[15];
    char QuantProduto[13];
};

Saida* infoSaida( );
CancelarSaid* infoCancelarSaid( );
