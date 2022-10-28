#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "modulocadastroItem.h"

void modulocadastroItem(void) {
    Item* produto;
    ExcluirItem* excItem;
    char escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case '1':
                produto = infoItem();
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
                telaAtualizarItem();
                break;
            case '6':
                excItem = infoExcluir();
                break;
            default:
                printf("Opção inválida\n");
                break;
        } 
     
    } while (escolha != '0');

    free (produto);
    free (excItem);

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
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

Item* infoItem( )
{
    Item* it;
    it = (Item*) malloc(sizeof(Item));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
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
    
    veriDatav( );

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();
    return it;

}

DataV* veriDatav( )
{
    DataV* dv;
    dv = (DataV*) malloc(sizeof(DataV));
    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &dv->dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &dv->mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &dv->ano);
        getchar();
        
    } while(!valida_data(dv->dia, dv->mes, dv->ano));  
    return dv;
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
        printf(" | Informe o estoque mínimo: ");
        scanf("%s", estoqueMinimo);
        getchar();
        
    } while (!lerQuantidade(estoqueMinimo));
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}

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

ExcluirItem* infoExcluir()
{
    ExcluirItem* exc;
    exc = (ExcluirItem*) malloc(sizeof(ExcluirItem));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ----------------------- EXCLUIR ITENS ------------------------ | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", exc->barra);
        getchar();
        
    } while (!lerQuantidade(exc->barra));

    // aqui terá um if se o código de barra for encontrado ele entrará nas opções
    // if barra == (nosso banco de dados);
        // digite a quantidade de itens que deseja excluir;
        // os itens serão removidos.
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ============================================================== | \n");
    printf(" Press ENTER for continue... ");
    getchar();

    return exc;

}
