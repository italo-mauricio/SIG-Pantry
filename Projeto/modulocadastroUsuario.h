//cabeçalho das funções usadas no arquivo.c
void modulocadastroUsuario(void);
int telaMenuUsuario(void);
void telaAtualizarUsuario(void);
void exibeUsuario(void);
void escolhafuncao(char);

typedef struct usuario Usuario;
struct usuario {
  char nome[101];
  char email[40];
  char username[20];
  char senha[20];
};

typedef struct data Data;
struct data{
    int dia;
    int mes;
    int ano;
};

typedef struct excluirUsuario ExcluirUsuario;
struct excluirUsuario
{
    char email [40];
};

typedef struct atualizarNome AtualizarNome;
struct atualizarNome
{
    char nome [40];
};

typedef struct atualizarEmail AtualizarEmail;
struct atualizarEmail
{
    char email [40];
};

typedef struct atualizarDataNasc AtualizarDataNasc;
struct atualizarDataNasc
{
    int dia, mes, ano;
};

typedef struct atualizarUsername AtualizarUsername;
struct atualizarUsername
{
    char username[20];
};

typedef struct atualizarSenha AtualizarSenha;
struct atualizarSenha
{
    char senha[20];
};

Usuario* infoUsuario( );
Data* veriData( );
ExcluirUsuario* infoExcluirUs();
AtualizarNome* atualizaNome();
AtualizarEmail* atualizEmail();
AtualizarDataNasc* atualizarData();
AtualizarUsername* atualizUsername();
AtualizarSenha* atualizSenha();