#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "modulomenuItem.h"
#include "modulocadastroUsuario.h"
#include "moduloEntradaItens.h"
#include "moduloSaidaItens.h"


void modulomenuItem(void) 
{
    char escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case '1': 
                buscarItem(); //pesquisa
                break;
            case '2':
                telaAtualizarItem(); //edição 
                break;
            case '3':
                infoExcluir(); //exclusão
                break;
            case '4':
                listarItens(); //relatório
                break;
            default:
                printf("Opção inválida\n");
                break;
        } 
     
    } while (escolha != '0');

}


char telaMenuItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- SIG-Pantry - MENU ITENS --------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Pesquisar item                          | \n");
    printf(" |                2- Atualizar cadastro                      | \n");
    printf(" |                3- Excluir itens                           | \n");                 
    printf(" |                4- Listar itens                            | \n");
    printf(" |                0- Voltar à tela principal                 | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}


//exibe produtos cadastrados
void exibeItens(Item* it) {
    system(" cls || clear");
    printf(" | ===================== Item cadastrado =================== |\n");
    printf(" |                                                           |\n");
    printf(" | Nome do produto: %s\n", it->nomeProduto);   
    printf(" | Nome da marca: %s\n", it->nomeMarca); 
    printf(" | Dia do vencimento: %d\n", it->dia); 
    printf(" | Mês do vencimento: %d\n", it->mes); 
    printf(" | Ano do vencimento: %d\n", it->ano); 
    printf(" | Código de barras: %s\n", it->codigoBarras);
    printf(" | Estoque mínimo: %s\n", it->estoqueMinimo);
    printf(" | Categoria do produto: %s\n", it->categoria);
    printf(" | Local de armazenamento: %s\n", it->localArmazenamento);
    printf(" | Status: %c\n", it->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para gravar no arquivo
int gravaItem(Item* it) 
{
    FILE* fp;
    fp = fopen("itens.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        return 0;
    }
    
    fwrite(it, sizeof(Item), 1, fp);
    fclose(fp);
    return 0;

}

//a partir do código de barras a função abaixo fará a pesquisa
int buscarItem(void)
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
    printf(" |                   Buscar dados do item                    | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o código de barras: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        system(" cls || clear");
        printf(" | ==================== Item encontrado ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome: %s\n", it->nomeProduto);    
        printf(" | Código de barras: %s\n", it->codigoBarras);
        printf(" | Nome da marca: %s\n", it->nomeMarca); 
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes); 
        printf(" | Ano do vencimento: %d\n", it->ano); 
        printf(" | Categoria do produto: %s\n", it->categoria); 
        printf(" | Estoque mínimo: %s\n", it->estoqueMinimo);
        printf(" | Local de armazenamento: %s\n", it->localArmazenamento); 
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
   
    
    } else {
        printf("Os dados do produto %s não foram encontrados\n", procurado);
    }
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//função para editar algum item
int telaAtualizarItem(void)  
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
    printf(" | --------------------- Atualizar item -------------------- | \n");
    printf("Informe o código de barras: ");
    scanf(" %[0-9]", procurado);
    getchar();

    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
    }
    if (achou){

        exibeItens(it);
        resp = escAtualizarItem();
        printf("\n");

        if (resp == '1'){
            do
            {
                printf("Informe o novo nome: ");
                scanf(" %49[^\n]", it->nomeProduto);
                getchar();

            } while(!validarLetras(it->nomeProduto, tamanhoString(it->nomeProduto)));

            do
            {
                printf("Informe o novo nome da marca: ");
                scanf(" %49[^\n]", it->nomeMarca);
                getchar();

            } while(!validarLetras(it->nomeMarca, tamanhoString(it->nomeMarca)));

            do
            {
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));

            do
            {
                printf("Informe o novo estoque mínimo: ");
                scanf("%s", it->estoqueMinimo);
                getchar();

            } while(!lerQuantidade(it->estoqueMinimo));

            do
            {        
                printf(" | Informe o novo dia de vencimento: ");
                scanf("%d", &it->dia);
                getchar();
                printf(" | Informe o novo mês de vencimento: ");
                scanf("%d", &it->mes);
                getchar();
                printf(" | Informe o novo ano de vencimento: ");
                scanf("%d", &it->ano);
                getchar();
        
            } while(!valida_data(it->dia, it->mes, it->ano));  

            do //por enquanto será assim
            {
                printf(" | ================== Categoria do produto ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                      Higiene pessoal                     |\n");
                printf(" |                      Limpeza                             |\n");
                printf(" |                      Alimento                            |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite a nova categoria do produto: ");
                scanf("%[A-Z a-z]", it->categoria);
                getchar();

            } while (!validarLetras(it->categoria, tamanhoString(it->categoria)));

            do //por enquanto será assim
            {
                printf(" | ================ Local de Armazenamento ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                   Geladeira                              |\n");
                printf(" |                   Armário da cozinha                     |\n");
                printf(" |                   Área de serviço                        |\n");
                printf(" |                   Banheiro                               |\n");
                printf(" |                   Guarda-roupa                           |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite o novo local de armazenamento (sem acentuação): ");
                scanf("%[A-Z a-z]", it->localArmazenamento);
                getchar();

            } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));

        }

        else if (resp == '2'){
            do
            {
                printf("Informe o novo nome: ");
                scanf(" %49[^\n]", it->nomeProduto);
                getchar();

            } while(!validarLetras(it->nomeProduto, tamanhoString(it->nomeProduto)));
        }

        else if (resp == '3'){
            do
            {
                printf("Informe o novo nome da marca: ");
                scanf(" %49[^\n]", it->nomeMarca);
                getchar();

            } while(!validarLetras(it->nomeMarca, tamanhoString(it->nomeMarca)));

        }

        else if (resp == '4'){
            do
            {
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));
        }
        
        else if (resp == '5'){
            do
            {
                printf("Informe o novo estoque mínimo: ");
                scanf(" %s", it->estoqueMinimo);
                getchar();

            } while(!lerQuantidade(it->estoqueMinimo));
        }

        else if (resp == '6'){
            do
            {        
                printf(" | Informe o novo dia de vencimento: ");
                scanf("%d", &it->dia);
                getchar();
                printf(" | Informe o novo mês de vencimento: ");
                scanf("%d", &it->mes);
                getchar();
                printf(" | Informe o novo ano de vencimento: ");
                scanf("%d", &it->ano);
                getchar();
        
            } while(!valida_data(it->dia, it->mes, it->ano));
        }  

        else if (resp == '7'){
            do 
            {
                printf(" | ================= Categoria do produto ================= |\n");
                printf(" |                                                          |\n");
                printf(" |                      Higiene pessoal                     |\n");
                printf(" |                      Limpeza                             |\n");
                printf(" |                      Alimento                            |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite a nova categoria do produto: ");
                scanf("%[A-Z a-z]", it->categoria);
                getchar();

            } while (!validarLetras(it->categoria, tamanhoString(it->categoria)));
        }
        
        else if (resp == '8') {
            do //por enquanto será assim
            {
                printf(" | ================ Local de Armazenamento ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                   Geladeira                              |\n");
                printf(" |                   Armário da cozinha                     |\n");
                printf(" |                   Área de serviço                        |\n");
                printf(" |                   Banheiro                               |\n");
                printf(" |                   Guarda-roupa                           |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite o novo local de armazenamento (sem acentuação): ");
                scanf("%[A-Z a-z]", it->localArmazenamento);
                getchar();

            } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));
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
        printf("O item de código de barras %s não foi encontrado\n", procurado);
    }
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(it);
    fclose(fp);      

    }
    return 0; 
}

//função para selecionar o que quer atualizar
char escAtualizarItem(void)
{    
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- Atualizar item -------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Editar tudo                             | \n");
    printf(" |                2- Editar nome do item                     | \n");
    printf(" |                2- Editar nome da marca                    | \n");
    printf(" |                3- Editar código de barras                 | \n");
    printf(" |                4- Editar estoque mínimo                   | \n");
    printf(" |                5- Editar data de vencimento               | \n");                 
    printf(" |                6- Editar categoria                        | \n");
    printf(" |                7- Editar local de armazenamento           | \n");                                                                    
    printf(" |                0- Voltar à tela principal                 | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//função para exclusão lógica
int infoExcluir(void)
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
    printf(" | ------------------------ Excluir item ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do produto que você deseja excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(it, sizeof(Item), 1, fp))){
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeItens(it);
        printf("Deseja realmente excluir os dados deste item? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            it->status = '0';
            fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
            printf("\nDados do item excluídos com sucesso!");
            gravaItem(it);
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("O item não foi encontrado!");
    }
    free(it);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//listar itens (relatório)
int listarItens(void)
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
        system(" cls || clear");
        printf(" | ===================== Lista item ======================== | \n");
        printf(" |                                                           | \n");
        exibeItens(it);
    }
    fclose(fp);
    free(it);
    return 0;

}
