#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "moduloMenuItem.h"

void menuSaidaItens(void)
{
    char escolha;
    do {
        escolha = telaRegistrarSaida();
        switch(escolha) {
        case '1':
            infoSaida(); //informações da saída
            break;
        case '2':
            buscainfoSaida(); //pesquisa
            break;
        case '3':
            listarSaidas(); //relatório
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
int infoSaida(void)
{
    FILE* fp;
    Item* it;
    int resp;
    int i;
    //int estoque;
    //int novovalor;
    int achou;
    
    char cod [15]; 
    fp = fopen("itens.dat", "r+b");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- Registrar saída de item ---------------- | \n");
    printf(" |                                                           | \n");   
    printf(" | Por favor, Informe o código de barras cadastrado: ");
    scanf("%s", cod);
    getchar();
    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, cod) == 0) && (it->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou){
        printf("Informe quantos itens vão sair da despensa: ");
        scanf("%d", &resp);

            for (i = 1; i <= resp; i++) {
                do
                {
                    printf(" | Informe a quantidade desse item que deixará a despensa: ");
                    scanf("%s", it->quantProduto);  // acidionar o cálculo de saída
                    getchar();
                
                } while (!lerQuantidade(it->quantProduto));

                

                fseek(fp, -1*sizeof(Item), SEEK_CUR);
                fwrite(it, sizeof(Item), 1, fp);

                printf("Retirado com sucesso!");



                // o campo de quantidade de produtos já foi acessado, agora precisamos resgatar
                // a informação que está no módulo de entrada, e subtrair com o que está saindo



                
         
            }
            
          

    }else {
        printf("Produto não encontrado!");
    }
    //colocar uma condicional aqui para perguntar se a pessoa realmente tem certeza dessa saída
    //se ela não tiver, fecha o arquivo e não salva

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it->status = '1';
    gravaItem(it);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;

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


//listar saídas - relatório
int listarSaidas(void) 
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