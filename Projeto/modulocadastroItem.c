#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "modulocadastroItem.h"

void modulocadastroItem(void) {
    char escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case '1':
                telaCadastrarItem();
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
                telaExcluirItem();
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
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

void telaCadastrarItem(void)
{
    char nomeProduto [20];
    char nomeMarca [20];
    int dia, mes, ano;
    char codigoBarras [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
    do
    {
        printf(" | Informe o nome do produto: ");
        scanf("%s", nomeProduto);
        getchar();
        
    } while (!lerLetras(nomeProduto));

    do
    {
        printf(" | Informe o nome da marca: ");
        scanf("%s", nomeMarca);
        getchar();
        
    } while (!lerLetras(nomeMarca));

    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", codigoBarras);
        getchar();
        
    } while (!lerQuantidade(codigoBarras));

    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &ano);
        getchar();
        
    } while(!valida_data(dia, mes, ano));  

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}
/*void telaCadastrarAlimento(void) 
{
    char opcao;
    if(opcao == 1){
        printf('Nome do item:\n');
    } if(opcao == 2) {
        printf('Data de validade:\n');
    } if(opcao == 3) {
        //printf('Local de armazenamento:\n'); pensar em puxar as opções: geladeira, armário...
    } else {
        printf('Voltar a tela de Cadastro de Itens');
    }

}
*/

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
        scanf("%[0-9]", estoqueMinimo);
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
        switch (op)
        {
        case '1':
            telaAtualizarNome();
            break;
        case '2':
            telaAtualizarCodigodeBarras();
            break;
        case '3':
            telaAtualizarDatadeValidade();
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

}


void telaAtualizarNome(void) 
{
    char nome [20];
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- ATUALIZAR NOME ------------------------ | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o novo nome do produto: ");
        scanf("%s", nome);
        getchar();
        
    } while (!lerLetras(nome));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf(" | Nome atualizado, por favor, digite ENTER...");
    getchar();

}

void telaAtualizarCodigodeBarras(void) 
{
    char codBarras [13];
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------- ATUALIZAR CÓDIGO DE BARRAS ------------------- | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", codBarras);
        getchar();
        
    } while (!lerQuantidade(codBarras));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Código de barras atualizado, por favor, digite ENTER...");
    getchar();

}

void telaAtualizarDatadeValidade(void) 
{

    int dia, mes, ano;
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------- ATUALIZAR DATA DE VALIDADE ------------------- | \n");
    printf(" |                                                                | \n");
    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &ano);
        getchar();
        
    } while(!valida_data(dia, mes, ano));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Press ENTER for continue...");
    getchar();

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

void telaExcluirItem(void)
{
    char barra [13];
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ----------------------- EXCLUIR ITENS ------------------------ | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", barra);
        getchar();
        
    } while (!lerQuantidade(barra));

    // aqui terá um if se o código de barra for encontrado ele entrará nas opções
    // if barra == (nosso banco de dados);
        // digite a quantidade de itens que deseja excluir;
        // os itens serão removidos.
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ============================================================== | \n");
    printf(" Press ENTER for continue... ");
    getchar();

}
