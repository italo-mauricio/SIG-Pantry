#include <stdio.h>
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
                printf("Opção inválida!");
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
    printf(" | -------- SIG-Pantry - SAÍDA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |            1- Código de barras do produto retirado        | \n");
    printf(" |            2- Quantidade de produto                       | \n");                 
    printf(" |            0- Voltar à tela principal                     | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

char telaNomeProdutoRetirado(void)
{
    char CodigodeBarras [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- NOME DO PRODUTO RETIRADO --------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o código de barras do produto que será retirado: ");
    scanf("%[0-9]", CodigodeBarras);
    getchar(); 
    printf(" |  0- Voltar à tela de saída \n");
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
    printf(" |  0- Voltar à tela de saída \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}