#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"

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
    printf(" |                 3- Listar saída                           | \n");                                                                    
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    
   
}

//função para informar a saída de um item do estoque
void infoSaida(void)
{
    Saida* said;
    system ( " cls || clear " );
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
    gravaItem(said);
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

/*//função para gravar no arquivo:
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
    
} */

//função de pesquisa a partir do código de barras
void buscainfoSaida(void)
{
    FILE* fp;
    Saida* said;
    int achou;
    char procurado[15];
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    system ( " cls || clear " );
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
        system(" cls || clear ");
        printf(" | =================== Saída encontrada ==================== |\n");
        printf(" |                                                           |\n");    
        printf(" | Código de barras: %s\n", said->codigodeBarras);    
        printf(" | Quantidade de produto: %s\n", said->QuantProduto);
        printf(" | Status: %c\n", said->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        printf("Os dados da saída %s não foram encontrados\n", procurado);
    }
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//listar saídas
void listarSaida(void) 
{
    FILE* fp;
    Saida* said;
    fp = fopen("itens.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
                                                     
    said = (Saida*)malloc(sizeof(Saida));
    while(fread(said, sizeof(Saida), 1, fp)) {
        system(" cls || clear ");
        printf(" | ==================== Lista de Saídas ==================== |\n");
        printf(" |                                                           |\n");    
        printf(" | Código de barras: %s\n", said->codigodeBarras);    
        printf(" | Quantidade de produto: %s\n", said->QuantProduto);
        printf(" | Status: %c\n", said->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    }
    fclose(fp);
    free(said);

}