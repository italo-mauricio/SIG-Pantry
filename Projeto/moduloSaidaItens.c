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
    Item* it;
    int resp;
    int i;
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- Registrar saída de item ---------------- | \n");
    printf(" |                                                           | \n");    
    it = (Item*) malloc(sizeof(Item));
    
    printf("Informe quantos itens vão sair da despensa: ");
    scanf("%d", &resp);

        for (i = 1; i <= resp; i++) {
            do 
            {
                printf(" | Informe o código de barras: ");
                scanf("%s", it->codigoBarras);
                getchar();
            
            } while (!lerQuantidade(it->codigoBarras));

            do
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", it->quantProduto);  // acidionar o cálculo de saída
                getchar();
            
            } while (!lerQuantidade(it->quantProduto));
            
        }   

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    it->status = '1';
    gravaItem(it);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função de pesquisa a partir do código de barras
int buscainfoSaida(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char procurado[15];
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
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
    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item*), 1, fp))) {
        printf("Código de barras |%s|\n", it->codigoBarras);
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        system(" cls || clear ");
        printf(" | =================== Saída encontrada ==================== |\n");
        printf(" |                                                           |\n");    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Quantidade de produto: %s\n", it->quantProduto);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        printf("Os dados da saída %s não foram encontrados\n", procurado);
    }
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//listar saídas
int listarSaida(void) 
{
    FILE* fp;
    Item* it;
    fp = fopen("itens.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
                                                     
    it = (Item*)malloc(sizeof(Item));
    while(fread(it, sizeof(Item), 1, fp)) {
        system(" cls || clear ");
        printf(" | ==================== Lista de Saídas ==================== |\n");
        printf(" |                                                           |\n");    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Quantidade de produto: %s\n", it->quantProduto);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    }
    fclose(fp);
    free(it);
    return 0;

}