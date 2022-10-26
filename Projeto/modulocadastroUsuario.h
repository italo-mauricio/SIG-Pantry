//cabeçalho das funções usadas no arquivo.c
void modulocadastroUsuario(void);
int telaMenuUsuario(void);
char telaRemove(void);
char telaListar(void);
void telaEditar(void);

typedef struct usuario Usuario;
struct usuario {
  char nome[40];
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

Usuario* infoUsuario( );
Data* veriData( );
