#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"

void menuSaidaItens(void)
{
    char escolha;
    do {
        escolha = telaRegistrarSaida();
        switch(escolha) {
        case '1':
            infoSaida(); //informações do item
            break;
        case '2':
            buscainfoSaida(); //pesquisa
            break;
        case '3':
            atualizarSaida(); //edição
            break; 
        case '4':
            excluirSaida(); //exclusão
            break;
        case '5':
            listarSaida(); //relatório
            break;     
        default:
            printf("Opção inválida\n");
            break;
        }
          
    } while (escolha != '0');

}

char telaRegistrarSaida(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------- REGISTRAR SAÍDA DE ITENS DA DESPENSA --------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Informar saída                         | \n");
    printf(" |                 2- Pesquisar saída                        | \n");
    printf(" |                 3- Editar saída                           | \n");                 
    printf(" |                 4- Excluir saída                          | \n");
    printf(" |                 5- Listar saída                           | \n");                                                                    
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    
   
}

//Função para informar a saída de um item do estoque
void infoSaida(void)
{
    Saida* said;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- Registrar saída de item ---------------- | \n");
    printf(" |                                                           | \n");    
    said = (Saida*) malloc(sizeof(Saida));
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", said->codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(said->codigodeBarras));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", said->QuantProduto);
        getchar();
        
    } while (!lerQuantidade(said->QuantProduto));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    said->status = '1';
    gravaSaida(said);
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//Função para gravar no arquivo:
void gravaSaida(Saida* said) 
{
    FILE* fp;
    fp = fopen("saida.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(said, sizeof(Saida), 1, fp);
    fclose(fp);
    
}

//A partir do código de barras
void buscainfoSaida(void)
{
    FILE* fp;
    Saida* said;
    int achou;
    char procurado[15];
    fp = fopen("saida.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados da saída                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o código de barras: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    said = (Saida*) malloc(sizeof(Saida));
    achou = 0;
    while((!achou) && (fread(said, sizeof(Saida), 1, fp))) {
        printf("Código de barras |%s|\n", said->codigodeBarras);
        if ((strcmp(said->codigodeBarras, procurado) == 0) && (said->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeSaida(said);
    } else {
        printf("Os dados da saída %s não foram encontrados\n", procurado);
    }
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    

}

void exibeSaida(Saida* said) 
{
    printf(" | Código de barras: %s\n", said->codigodeBarras);    
    printf(" | Quantidade do produto: %s\n", said->QuantProduto);
    printf(" | Status: %c\n", said->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//EDITAR AQUI
void atualizarSaida(void) {
    
}

//Função para exclusão lógica
void excluirSaida(void)
{
    FILE* fp;
    Saida* said;
    int achou;
    char resp;
    char procura[20];
    fp = fopen("saida.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    said = (Saida*) malloc(sizeof(Saida));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir saída ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do produto que você deseja excluir: ");
    scanf(" %30[^\n]", procura);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(said, sizeof(Saida), 1, fp))){
        if ((strcmp(said->codigodeBarras, procura) == 0) && (said->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeSaida(said);
        getchar();
        printf("Deseja realmente excluir os dados desta saída? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            said->status = '0';
            fseek(fp, (-1)*sizeof(Saida), SEEK_CUR);
            fwrite(said, sizeof(said), 1, fp);
            printf("\nDados da saída excluídos com sucesso!");
            gravaSaida(said);
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("Os dados não foram encontrados!");
    }
    free(said);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//listar saídas
void listarSaida(void) 
{
    FILE* fp;
    Saida* said;
    fp = fopen("saida.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    printf(" | ===================== Exibe saída ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    said = (Saida*)malloc(sizeof(Saida));
    while(fread(said, sizeof(Saida), 1, fp)) {
        exibeSaida(said);
    }
    fclose(fp);
    free(said);

}