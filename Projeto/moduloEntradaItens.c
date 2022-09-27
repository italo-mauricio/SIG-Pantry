#include<stdio.h>
#include<stdlib.h>
#include "moduloEntradaItens.h"

char menuentradaitens(void)
{
    int escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case 1:
                telaNomeProdutoAdicionado();
                break;
            case 2:
                telaQuantProdutos();
                break;
        } 
     
    } while (escolha != 0);

    return escolha;

}


char telaEntradaItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------ SIG-Pantry - ENTRADA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |            1- Código de barras do produto adicionado      | \n");
    printf(" |            2- Quantidade de produto                       | \n");                 
    printf("              0- Voltar à tela principal                     | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

char telaNomeProdutoAdicionado(void)
{
    char codigodeBarras [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- NOME DO PRODUTO ADICIONADO ------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o código de barras do produto que será adicionado: ");
    scanf("%[A-Z a-z]", codigodeBarras);
    getchar(); 
    printf(" |  0- Voltar à tela de entrada \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaQuantProdutos(void)
{
    char quantProduto [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------- QUANTIDADE DE PRODUTO ADICIONADO ---------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe a quantidade de produto adicionado: ");
    scanf("%[A-Z a-z., 0-9., -]", quantProduto);
    getchar(); 
    printf(" |  0- Voltar à tela de entrada \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}


