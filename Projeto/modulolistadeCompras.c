#include <stdio.h>
#include <stdlib.h>
#include "modulolistadeCompras.h"

void menulistadeCompras(void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            telaMontarLista();
            break;
        case '2':
            telaItensQuantMinima();
            break; 
        case '3':
            telaItensProxVencimento();
            break;
        case '4':
            telaAdicionarItensaLista();
            break; 
        case '5':
            telaItensCadastrados();
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    } while(escolha != '0');
        printf("Obrigado! Volte sempre!");

} 

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |          1- Montar sua lista de compras                              | \n");
    printf(" |          2- Visualizar itens no estoque com quantidade mínima        | \n");
    printf(" |          3- Visualizar itens próximos ao vencimento                  | \n");
    printf(" |          4- Adicionar itens à lista                                  | \n"); 
    printf(" |          5- Visualizar itens já cadastrados na lista                 | \n");      
    printf(" |          0- Voltar à tela principal                                  | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

} 

void telaItensQuantMinima(void)
{
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------- | ITENS NO ESTOQUE COM QUANTIDADE MÍNIMA | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens no estoque com quantidade mínima:  "); //criar função para puxar essa informação
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    system("Pause");
    system("cls");



}

void telaItensProxVencimento(void)
{
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | ITENS PRÓXIMOS AO VENCIMENTO | ----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens próximos ao vencimento: ");
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" Press ENTER to exit...");

}

char telaAdicionarItensaLista(void)
{

    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------ |    ADICIONAR ITENS À LISTA DE COMPRAS | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |           1- Adicionar automaticamente itens que estão acabando      | \n");
    printf(" |           2- Adicionar itens da sua escolha                          | \n"); 
    printf(" |           0- Voltar à tela de lista de compras                       | \n"); 
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;
// nessa opção de itens à sua escolha cria-se uma outra tela, onde terá nome; quantidade...
}

void telaMontarLista(void)
{
    char nome[20];
    char categoriaProduto[10];
    int quantidadeProduto;
    system (" clear||cls ");
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua Lista de Compras | ------------- | \n");
    printf("|                                                               | \n");
    do
    {
        printf(" | Informe o nome: ");
        scanf("%s", nome);
        getchar();
        
    } while (!lerLetras(nome));

    do
    {
        printf(" | Informe a categoria do produto: ");
        scanf("%s", categoriaProduto);
        getchar();
        
    } while (!lerLetras(categoriaProduto));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", quantidadeProduto);
        getchar();
        
    } while (!lerQuantidade(quantidadeProduto));
    
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf(" Press ENTER to exit...");
    
   /* printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");*/

}

void telaItensCadastrados(void)
{

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | ITENS JÁ CADASTRADOS NA LISTA | ---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens cadastrados na lista:  "); //criar função para puxar essa informação
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" Press ENTER to exit...");

}