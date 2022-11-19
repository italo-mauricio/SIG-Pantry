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
    gravaSaida(said);
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função para gravar no arquivo:
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

//função de pesquisa a partir do código de barras
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

void exibeSaida(Saida* said) 
{   
    system(" cls || clear ");
    printf(" | ==================== Saída registrada =================== |\n");
    printf(" |                                                           |\n");    
    printf(" | Código de barras: %s\n", said->codigodeBarras);    
    printf(" | Quantidade do produto: %s\n", said->QuantProduto);
    printf(" | Status: %c\n", said->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para edição
void atualizarSaida(void) 
{
    FILE *fp;
    Saida* said;
    char resp;
    char escolha;
    said = (Saida*) malloc(sizeof(Saida));
    system(" cls || clear");
    printf(" | Digite o código de barras cadastrado: ");
    scanf("%s", said->codigodeBarras);
    getchar();
    if ((said == NULL) || (said->status == '0')) {
        printf("\nSaída não encontrada\n");
        exit(1);
    }

    fp = fopen("saida.dat", "r+t");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }

    exibeSaida(said);
    printf("\nEsta é a saída que você quer alterar os dados? S/N");
    scanf("%c", &resp);
    getchar();
    system("cls || clear");
    if (resp == 'S' || resp == 's'){
        system(" cls || clear");
        printf(" | ========================================================= | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf(" | -------------------- Atualizar saída -------------------- | \n");
        printf(" |                                                           | \n");
        printf(" |                 1- Editar código de barras                | \n");
        printf(" |                 2- Editar quantidade                      | \n");
        printf(" |                 0- Voltar à tela principal                | \n");    
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf(" | Selecione uma opção: ");
        scanf("%c", &escolha);
        getchar();
        while (escolha != '0')
        {
            switch (escolha){
                case '1':
                do
                {
                    printf(" | Informe o novo código de barras do item: ");
                    scanf("%s", said->codigodeBarras);
                    getchar();
        
                } while(!lerQuantidade(said->codigodeBarras));
                printf("\nSaída editada com sucesso!\n");
                break;

                case '2':
                do
                {
                    printf(" | Informe a nova quantidade de produto: ");
                    scanf("%s", said->QuantProduto);
                    getchar();
                    
                } while(!lerQuantidade(said->QuantProduto));

                default:
                    printf("\nPor favor, insira uma opção válida.\n");
                    break;
                }

                escolha = '0';
            }
            fseek(fp, (-1) * sizeof(Saida), SEEK_CUR);
            fwrite(said, sizeof(Saida), 1, fp);
        }

    else {
        printf("\nOk, os dados não foram alterados!\n");
    }
    fclose(fp);
    free(said);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
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
        printf("A saída não foi encontrada!");
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
                                                     
    said = (Saida*)malloc(sizeof(Saida));
    while(fread(said, sizeof(Saida), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Lista saída ======================= | \n");
        printf(" |                                                           | \n");
        exibeSaida(said);
    }
    fclose(fp);
    free(said);

}