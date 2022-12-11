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
    char dataUsu[20];

    
};

//cabeçalho das funções usadas no arquivo .c
void modulocadastroUsuario(void);
char telaMenuUsuario(void);
int atualizarUsuario(void);
void escolhafuncao(char);
void InfoUsuario(void);
int gravaUsuario(Usuario*);
int listaInfoUsuario(void);
void exibeInfoUsuario(Usuario* cliente);
int buscaInfoUsuario(void);
int infoExcluirUs(void);
int validaUser(char* user);
char escAtualizarUsuario(void);
