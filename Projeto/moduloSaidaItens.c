#include<stdio.h>
#include<stdlib.h>
#include "moduloSaidaItens.h"

char moduloSaidaItens(void)
{
    int escolha;
    do {
        escolha = telaSaidaItens();
        switch(escolha) {
            case 1:
                telaNomeProdutoRetirado();
                break;
            case 2:
                telaQuantProduto();
                break;
            default:
                printf("Opcao invalida");
                break;
        } 
     
    } while (escolha != 0);

    return escolha;

}

char telaSaidaItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- SIG-Pantry - SAIDA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |              1- Nome do produto retirado                  | \n");
    printf(" |              2- Quantidade de produto                     | \n");                 
    printf(" |              0- Voltar a tela principal                   | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

char telaNomeProdutoRetirado(void)
{
    char nomeProdutoRetirado [20];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- NOME DO PRODUTO RETIRADO --------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o nome do produto que sera retirado: ");
    scanf("%[A-Z a-z]", nomeProdutoRetirado);
    getchar(); 
    printf(" |  0- Voltar a tela de saida \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaQuantProduto(void)
{
    char quantProduto [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------- QUANTIDADE DE PRODUTO RETIRADO ------------ | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe a quantidade de produto retirado: ");
    scanf("%[A-Z a-z., 0-9., -]", quantProduto);
    getchar(); 
    printf(" |  0- Voltar a tela de saida \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}