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
void pesquisarSaida(void);
void atualizarSaida(void);
void excluirSaida(void);
void listarSaida(void);
void buscainfoSaida(void);
void exibeSaida(Saida* said);
