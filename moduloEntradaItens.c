#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroItem.h"

//Fazer as telas...

char telaEntradaItens(void); //pois já foi declarada na main
char telaNomeProdutoAdicionado(void);
char telaQuantProduto();


char telaEntradaItens(void)
{
    int escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case 1:
                telaNomeProdutoAdicionado();
                break;
            case 2:
                telaQuantProduto();
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
    printf(" | ------ SIG-Pantry - ENTRADA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |              1- Nome do produto adicionado                | \n");
    printf(" |              2- Quantidade de produto                     | \n");                 
    printf(" |              0- Voltar a tela principal                   | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

char telaNomeProdutoAdicionado(void)
{
    char nomeProdutoAdicionado [20];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- NOME DO PRODUTO ADICIONADO ------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o nome do produto que sera adicionado: ");
    scanf("%[A-Z a-z]", nomeProdutoAdicionado);
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
    printf(" | ------------- QUANTIDADE DE PRODUTO ADICIONADO ---------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe a quantidade de produto adicionado: ");
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