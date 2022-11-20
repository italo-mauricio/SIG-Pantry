//struct para cadastro do usuário
typedef struct usuario Usuario;
struct usuario {
    char nomeUsuario[101];
    char emailUsuario[40];
    int dia;
    int mes;
    int ano;
    char usernameUsuario[20];
    char senhaUsuario[20];
    char status;
};

//cabeçalho das funções usadas no arquivo .c
void modulocadastroUsuario(void);
char telaMenuUsuario(void);
void atualizarUsuario(void);
void escolhafuncao(char);
void InfoUsuario(void);
void gravaUsuario(Usuario*);
void listaInfoUsuario(void);
void exibeInfoUsuario(Usuario* cliente);
void buscaInfoUsuario(void);
void infoExcluirUs(void);
int validaUsername(Usuario* cliente);
char escAtualizarUsuario(void);
