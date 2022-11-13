//struct para cadastro do usuário
typedef struct usuario Usuario;
struct usuario {
    char nome[101];
    char email[40];
    int dia;
    int mes;
    int ano;
    char username[20];
    char senha[20];
    char status;
};

void modulocadastroUsuario(void);
char telaMenuUsuario(void);
void telaAtualizarUsuario(void);
void escolhafuncao(char);
void InfoUsuario(void);
void gravaUsuario(Usuario*);
void listaInfoUsuario(void);
void exibeInfoUsuario(Usuario* cliente);
void buscaInfoUsuario(void);
void infoExcluirUs(void);
