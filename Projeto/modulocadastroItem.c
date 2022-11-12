#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "modulocadastroItem.h"

void modulocadastroItem(void) 
{
    char escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case '1':
                infoItem(); //cadastrar item
                break;
            case '2':
                telaCategoriadoProduto();
                break;
            case '3': 
                telaLocaldeArmazenamento();
                break;
            case '4':
                telaEstoqueMinimo();
                break;
            case '5':
                telaAtualizarItem(); //edição (ainda precisa fazer)
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
    printf(" |                 1- Cadastrar item                         | \n"); 
    printf(" |                 2- Categoria do produto                   | \n"); 
    printf(" |                 3- Local de armazenamento                 | \n");
    printf(" |                 4- Estoque mínimo do item                 | \n");
    printf(" |                 5- Atualizar itens                        | \n");
    printf(" |                 6- Excluir itens                          | \n");                 
    printf(" |                 7- Listar itens                           | \n");
    printf(" |                 0- Voltar à tela principal                | \n");
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
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
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

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    it->status = '1'; //o 1 mostra que foi cadastrado
    gravaItem(it);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

char telaCategoriadoProduto(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------ CATEGORIA DO PRODUTO ----------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |                 1- Item alimentar                         | \n");
    printf(" |                 2- Item de higiene pessoal                | \n"); 
    printf(" |                 3- Item de limpeza                        | \n");         
    printf(" |                 0- Voltar à tela menu itens               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaLocaldeArmazenamento(void) 
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- LOCAL DE ARMAZENAMENTO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Geladeira                               | \n");
    printf(" |                2- Armário da cozinha                      | \n");
    printf(" |                3- Armário da área de serviço              | \n");  
    printf(" |                4- Armário do banheiro                     | \n"); 
    printf(" |                5- Guarda-roupa                            | \n");       
    printf(" |                0- Voltar à tela menu itens                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);  
    
    return opcao;

}

void telaEstoqueMinimo(void)
{
    char estoqueMinimo [20];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------- SIG-Pantry - ESTOQUE MÍNIMO DO ITEM --------- | \n");
    printf(" |                                                           | \n");
    do
    {
        printf(" | Informe o estoque mínimo do item: ");
        scanf("%s", estoqueMinimo);
        getchar();
        
    } while (!lerQuantidade(estoqueMinimo));
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}


//exibe produtos cadastrados
void exibeItens(Item* it) {
    printf(" | Nome: %s\n", it->nomeProduto);    
    printf(" | Nome da marca: %s\n", it->nomeMarca); 
    printf(" | Dia do vencimento: %d\n", it->dia); 
    printf(" | Mês do vencimento: %d\n", it->mes); 
    printf(" | Ano do vencimento: %d\n", it->ano); 
    printf(" | Código de barras: %s\n", it->codigoBarras);
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

//VAI TER QUE MUDAR
void telaAtualizarItem(void) 
{
    char op;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- ATUALIZAR ITEM -------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                  1- Nome do produto                       | \n");
    printf(" |                  2- Código de barras                      | \n");
    printf(" |                  3- Data de validade                      | \n");  
    printf(" |                  4- Categoria do produto                  | \n"); 
    printf(" |                  5- Local de armazenamento                | \n");       
    printf(" |                  0- Voltar à tela menu itens              | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &op); 
    getchar();
    suitefuncao(op); 

}

void suitefuncao(char op){ 
        AtualNome* atualizar;
        AtualCodigo* atualiz;
        AtualData* atuali;
        switch (op)
        {
        case '1':
            atualizar = atualizNome();
            break;
        case '2':
            atualiz = atualizCodigo();
            break;
        case '3':
            atuali = atualizData();
            break;
        case '4':
            telaAtualizarCategoria();
            break;
        case '5':
            telaAtualizarLocaldeArmazenamento();
            break;
        case '6':
            break;        
        default:
            printf("Opção inválida\n");
            break;
        }

        free (atualizar);
        free (atualiz);
        free (atuali);

}

AtualNome* atualizNome()
{
    AtualNome* atnome;
    atnome = (AtualNome*) malloc(sizeof(AtualNome));
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- ATUALIZAR NOME ------------------------ | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o novo nome do produto: ");
        scanf("%s", atnome->nome);
        getchar();
        
    } while (!lerLetras(atnome->nome));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf(" | Nome atualizado, por favor, digite ENTER...");
    getchar();
    
    return atnome;

}

AtualCodigo* atualizCodigo()
{
    AtualCodigo* atcodigo;
    atcodigo = (AtualCodigo*) malloc(sizeof(AtualCodigo));
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------- ATUALIZAR CÓDIGO DE BARRAS ------------------- | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", atcodigo->codBarras);
        getchar();
        
    } while (!lerQuantidade(atcodigo->codBarras));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Código de barras atualizado, por favor, digite ENTER...");
    getchar();

    return atcodigo;

}

AtualData* atualizData()
{
    AtualData* atdata;
    atdata = (AtualData*) malloc(sizeof(AtualData));
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------- ATUALIZAR DATA DE VALIDADE ------------------- | \n");
    printf(" |                                                                | \n");
    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &atdata->dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &atdata->mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &atdata->ano);
        getchar();
        
    } while(!valida_data(atdata->dia, atdata->mes, atdata->ano));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Press ENTER for continue...");
    getchar();

    return atdata;
    
}

char telaAtualizarCategoria(void) 
{
    char esc;
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------- ATUALIZAR CATEGORIA DO PRODUTO --------------- | \n");
    printf(" |                                                                | \n");    
    printf(" |                   1- Item alimentar                            | \n");
    printf(" |                   2- Item de higiene pessoal                   | \n"); 
    printf(" |                   3- Item de limpeza                           | \n");         
    printf(" |                   0- Voltar à tela menu itens                  | \n");
    printf(" |                                                                | \n");
    printf(" | ============================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaAtualizarLocaldeArmazenamento(void) 
{
    char esc;
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | -------------- ATUALIZAR LOCAL DE ARMAZENAMENTO -------------- | \n");
    printf(" |                                                                | \n");    
    printf(" |                   1- Geladeira                                 | \n");
    printf(" |                   2- Armário da cozinha                        | \n");
    printf(" |                   3- Armário da área de serviço                | \n");  
    printf(" |                   4- Armário do banheiro                       | \n"); 
    printf(" |                   5- Guarda-roupa                              | \n");       
    printf(" |                   0- Voltar à tela menu itens                  | \n");
    printf(" |                                                                | \n");
    printf(" | ============================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc); 
    getchar();
    return esc; 


}

void infoExcluir(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char resp;
    char procura[20];
    fp = fopen("itens.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    it = (Item*) malloc(sizeof(Item));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ EXCLUIR ITEM ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do produto que você deseja excluir: ");
    scanf(" %30[^\n]", procura);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(it, sizeof(Item), 1, fp))){
        if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')){
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
        printf("Os dados não foram encontrados!");
    }
    free(it);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//listar itens
void listarItens(void)
{
    FILE* fp;
    Item* it;
    fp = fopen("itens.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    printf(" | ===================== Exibe itens ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it = (Item*)malloc(sizeof(Item));
    while(fread(it, sizeof(Item), 1, fp)) {
        exibeItens(it);
    }
    fclose(fp);
    free(it);

}
