#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulomenuItem.h"

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
            telaAtualizarSaida(); //edição
            break;
        case '4':
            excluirSaida(); //exclusão
            break;
        case '5':
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
    printf(" |                 3- Atualizar saída                        | \n");                
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

//função para editar algum item
int telaAtualizarSaida(void)  
{
    FILE *fp;
    Item* it;
    char resp;
    int achou;
    char procurado[20];

    fp = fopen("itens.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar saída -------------------- | \n");
    printf("Informe o código de barras cadastrado: ");
    scanf(" %[0-9]", procurado);
    getchar();

    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
    }
    if (achou){

        listarSaidas();
        resp = escAtualizarSaida();
        printf("\n");

        if (resp == '1'){
            do
            {
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));

            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf("%s", it->quantProduto);
                getchar();

            } while(!lerQuantidade(it->quantProduto));

        }

        else if (resp == '2'){
            do
            {
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));

        }

        else if (resp == '3'){
            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf("%s", it->quantProduto);
                getchar();

            } while(!lerQuantidade(it->quantProduto));

        }
        
        it->status = '1';      
        fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
        fwrite(it, sizeof(Item), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
    }
    
    else 
    {
        printf("A saída de código de barras %s não foi encontrada\n", procurado);
    }
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(it);
    fclose(fp);      
    }

    return 0; 

}

//função para selecionar o que quer atualizar
char escAtualizarSaida(void)
{    
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar saída -------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Editar tudo                             | \n");
    printf(" |                2- Editar código de barras                 | \n");
    printf(" |                3- Editar quantidade do produto            | \n");
    printf(" |                0- Voltar à tela principal                 | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//função para exclusão lógica
int excluirSaida(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char resp;
    char procurado[20];
    fp = fopen("itens.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    it = (Item*) malloc(sizeof(Item));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ----------------------- Excluir saída ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras da saída que você deseja excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(it, sizeof(Item), 1, fp))){
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        listarSaidas();
        printf("Deseja realmente excluir os dados desta saída? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            it->status = '0';
            fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
            printf("\nDados da saída excluídos com sucesso!");
            gravaItem(it);
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("A saída não foi encontrada!");
    }
    free(it);
    fclose(fp);
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