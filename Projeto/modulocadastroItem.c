#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "modulocadastroItem.h"
#include "modulocadastroUsuario.h"

void modulocadastroItem(void) 
{
    char escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case '1':
                infoItem(); //cadastro do item
                break;
            case '2': 
                telaLocaldeArmazenamento(); //escolha do local de armazenamento
                break;
            case '3':
                buscarItem(); //pesquisa
                break;
            case '4':
                telaAtualizarItem(); //edição 
                break;
            case '5':
                telaAtualizarLocaldeArmazenamento(); //edição 
                break;
            case '6':
                infoExcluir(); //exclusão
                break;
            case '7':
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
    printf(" |                1- Cadastrar item                          | \n"); 
    printf(" |                2- Local de armazenamento                  | \n");
    printf(" |                3- Pesquisar item                          | \n");
    printf(" |                4- Atualizar cadastro                      | \n");
    printf(" |                5- Atualizar local de armazenamento        | \n");
    printf(" |                6- Excluir itens                           | \n");                 
    printf(" |                7- Listar itens                            | \n");
    printf(" |                0- Voltar à tela principal                 | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//Função para o cadastro dos itens
void infoItem(void)
{
    Item* it;
    system ( " cls || clear" );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - Cadastrar itens ------------- | \n");
    printf(" |                                                           | \n");
    it = (Item*) malloc(sizeof(Item));
    do
    {
        printf(" | Informe o nome do produto: ");
        scanf("%s", it->nomeProduto);
        getchar();
        
    } while (!lerLetras(it->nomeProduto));

    do
    {
        printf(" | Informe o nome da marca: ");
        scanf("%s", it->nomeMarca);
        getchar();
        
    } while (!lerLetras(it->nomeMarca));
    do
    {
        printf(" | Informe o número corespondente a categoria do produto: \n1- Higiente pessoal; \n2- Limpeza; \n3- Alimento): \n");
        scanf("%s", it->categoria);
        getchar();

    } while (!lerQuantidade(it->categoria)); 

    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", it->codigoBarras);
        getchar();
        
    } while (!lerQuantidade(it->codigoBarras));
    
    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &it->dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &it->mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &it->ano);
        getchar();
        
    } while(!valida_data(it->dia, it->mes, it->ano));  

    do
    {
        printf(" | Informe o estoque mínimo do item: ");
        scanf("%s", it->estoqueMinimo);
        getchar();
        
    } while (!lerQuantidade(it->estoqueMinimo));
    
    do
    {
        printf(" | Escolha o local de armazenamento: ");
        scanf("%s", it->localArmazenamento);
        getchar();
    } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));
    

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it->status = '1'; //o 1 mostra que foi cadastrado
    gravaItem(it);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

char telaLocaldeArmazenamento(void) 
{
    Item* it;
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- Local de armazenamento ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Geladeira                               | \n");
    printf(" |                2- Armário da cozinha                      | \n");
    printf(" |                3- Armário da área de serviço              | \n");  
    printf(" |                4- Armário do banheiro                     | \n"); 
    printf(" |                5- Guarda-roupa                            | \n");       
    printf(" |                0- Voltar à tela menu itens                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it = (Item*) malloc(sizeof(Item));
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);  
    return opcao;
    gravaItem(it);
    free(it);
    getchar();
//ver como salvar isso em "localArmazenamento"

}

//exibe produtos cadastrados
void exibeItens(Item* it) {
    system(" cls || clear");
    printf(" | ===================== Item cadastrado =================== |\n");
    printf(" |                                                           |\n");   
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
void gravaItem(Item* it) 
{
    FILE* fp;
    fp = fopen("itens.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        exit(1);
    }
    
    fwrite(it, sizeof(Item), 1, fp);
    fclose(fp);

}

//a partir do código de barras a função abaixo fará a pesquisa
void buscarItem(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char procurado[15];
    fp = fopen("item.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
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
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        printf("Os dados do produto %s não foram encontrados\n", procurado);
    }
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para editar algum item
void telaAtualizarItem(void)  
{
    FILE *fp;
    Item* it;
    char resp;
    char escolha;
    it = (Item*) malloc(sizeof(Item));
    system(" cls || clear");
    printf(" | Digite o código de barras cadastrado: ");
    scanf("%s", it->codigoBarras);
    getchar();
    if ((it == NULL) || (it->status == '0')) {
        printf("\nItem não encontrado\n");
        exit(1);
    }

    fp = fopen("item.dat", "r+t");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }

    exibeItens(it);
    printf("\nEste é o item que você quer alterar os dados? S/N");
    scanf("%c", &resp);
    getchar();
    system("cls || clear");
    if (resp == 'S' || resp == 's'){
        system(" cls || clear");
        printf(" | ========================================================= | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf(" | -------------------- Atualizar item --------------------- | \n");
        printf(" |                                                           | \n");
        printf(" |                 1- Editar nome                            | \n");
        printf(" |                 2- Editar nome da marca                   | \n");
        printf(" |                 3- Editar data de vencimento              | \n");                 
        printf(" |                 4- Editar código de barras                | \n");
        printf(" |                 5- Editar categoria do produto            | \n");                                                                    
        printf(" |                 6- Editar estoque mínimo                  | \n");                                                                    
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
                    printf(" | Informe o novo nome: ");
                    scanf("%[A-Z a-z 0-9 ]", it->nomeProduto);
                    getchar();
            
                } while (!validarLetras(it->nomeProduto, tamanhoString(it->nomeProduto)));
                printf("\nItem editado com sucesso!\n");
                break;

                case '2':
                do 
                {
                    printf(" | Informe o novo nome da marca: ");   
                    scanf("%s", it->nomeMarca);
                    getchar();

                } while (!validarLetras(it->nomeMarca, tamanhoString(it->nomeMarca)));
                printf("\nItem editado com sucesso!\n");
                break;

                case '3':
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
                printf("\nItem editado com sucesso!\n");
                break;

                case '4':
                do
                {
                    printf(" | Informe o novo código de barras: ");
                    scanf("%s", it->codigoBarras);
                    getchar();
        
                } while (!lerQuantidade(it->codigoBarras));
                printf("\nItem editado com sucesso!\n");
                break;

                case '5':
                do
                {
                    printf(" | Informe o número corespondente a nova categoria do produto: \n1- Higiente pessoal; \n2- Limpeza; \n3- Alimento): \n");
                    scanf("%s", it->categoria);
                    getchar();

                } while (!lerQuantidade(it->categoria)); 
                printf("\nItem editado com sucesso!\n");
                break;

                case '6':
                do
                {
                    printf(" | Informe o novo estoque mínimo do item: ");
                    scanf("%s", it->estoqueMinimo);
                    getchar();
        
                } while (!lerQuantidade(it->estoqueMinimo));
                printf("\nItem editado com sucesso!\n");
                break;

                default:
                    printf("\nPor favor, insira uma opção válida.\n");
                    break;
                }

                escolha = '0';
            }
            fseek(fp, (-1) * sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
        }

    else {
        printf("\nOk, os dados não foram alterados!\n");
    }
    fclose(fp);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}


char telaAtualizarLocaldeArmazenamento(void) 
{
    Item* it;
    char opcao;
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | -------------- Atualizar local de armazenamento -------------- | \n");
    printf(" |                                                                | \n");    
    printf(" |                   1- Geladeira                                 | \n");
    printf(" |                   2- Armário da cozinha                        | \n");
    printf(" |                   3- Armário da área de serviço                | \n");  
    printf(" |                   4- Armário do banheiro                       | \n"); 
    printf(" |                   5- Guarda-roupa                              | \n");       
    printf(" |                   0- Voltar à tela menu itens                  | \n");
    printf(" |                                                                | \n");
    printf(" | ============================================================== | \n");
    it = (Item*) malloc(sizeof(Item));
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);  
    return opcao;
    gravaItem(it);
    free(it);
    getchar();

}

void infoExcluir(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char resp;
    char procurado[20];
    fp = fopen("itens.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
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
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
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
    
}

//listar itens (relatório)
void listarItens(void)
{
    FILE* fp;
    Item* it;
    fp = fopen("item.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
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

}
