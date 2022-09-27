#include <stdio.h>
#include <stdlib.h>
#include "modulolistadeCompras.h"

char menulistadeCompras(void)
{
    int escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case 1:
            telaMontarLista();
            break;
        /*    char alimentosVencimento;
              do {
                    alimentosVencimento = telaAlimentoVencimento();      // testar com if 
                    switch (alimentosVencimento) {
                    case '1':
                        nomeItemAlimentar();
                        break;
                    case '2':
                        dataCadastroAlimento();
                        break; 
                    case '0':
                        telaListadeCompras();
                            
                    default :
                        printf ("Opcao invalida \n");
                        break;
                } 

                } while(alimentosVencimento != '0'); */

        case 2:
            telaItensQuantMinima();
            break; 
        case 3:
            telaItensProxVencimento();
            break;
        case 4:
            telaAdicionarItensaLista();
            break; 
        case 5:
            telaItensCadastrados();
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    } while(escolha != 0);
        printf("Obrigado! Volte sempre!");

    return escolha;

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

char telaItensQuantMinima(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------- | ITENS NO ESTOQUE COM QUANTIDADE MÍNIMA | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens no estoque com quantidade mínima:  "); //criar função para puxar essa informação
    printf(" |  0- Voltar à tela de lista de compras");
    scanf("%c", &esc);
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" Press ENTER to exit...");

    return esc;

}

char telaItensProxVencimento(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | ITENS PRÓXIMOS AO VENCIMENTO | ----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens próximos ao vencimento: ");
    printf(" |  0- Voltar à tela lista de compras ");
    scanf("%c", &esc);
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" Press ENTER to exit...");

    return esc;

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

char telaMontarLista(void)
{
    char nome[20];
    char categoriaProduto[10];
    int quantidadeProduto;
    char esc;
    system (" clear||cls ");
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua Lista de Compras| -------------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("|  2- Informe a categoria do produto: ");
    scanf("%[A-Z a-z]", categoriaProduto);
    getchar();
    printf("|  3- Informe a quantidade do produto: ");
    scanf("%d", &quantidadeProduto);
    getchar();
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);
    
   /* printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");*/

   return esc;

}

char telaItensCadastrados(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | ITENS JÁ CADASTRADOS NA LISTA | ---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens cadastrados na lista:  "); //criar função para puxar essa informação
    printf(" |  0- Voltar à tela de lista de compras");
    scanf("%c", &esc);
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" Press ENTER to exit...");

    return esc;

}