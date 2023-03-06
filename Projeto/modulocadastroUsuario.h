//struct para cadastro do usuário
typedef struct user User;
struct user {
    char nameUser[101];
    char emailUser[40];
    int day;
    int month;
    int year;
    char usernameUser[20];
    char senhaUsuario[20];
    char status;
    char userDate[20];

    
};

//cabeçalho das funções usadas no arquivo .c
void modulocadastroUsuario(void);
char userMenuScreen(void);
int updateUser(void);
void escolhafuncao(char);
void userInfo(void);
int gravaUsuario(User*);
int listaInfoUsuario(void);
void exibeInfoUsuario(User* cliente);
int searchUserInfor(void);
int infoExcluirUs(void);
int validaUser(char* user);
char escAtualizarUsuario(void);
