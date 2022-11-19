typedef struct saida Saida;
struct saida
{
    char codigodeBarras[15];
    char QuantProduto[13];
    int dia, mes, ano;
    char status;
};

void menuSaidaItens(void);
char telaRegistrarSaida(void);
void infoSaida(void);
void gravaSaida(Saida*);
void listarSaida(void);
void buscainfoSaida(void);

