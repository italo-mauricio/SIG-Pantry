#include<stdio.h>
#include<stdlib.h>
#include "moduloEntradaItens.h"

void menuEntradaItens(void)
{
    char escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case '1':
                telaRegistrarEntrada();
                break;
            case '2':
                CancelarEntrada();
                break;
        } 
     
    } while (escolha != '0');

}

char telaEntradaItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------ SIG-Pantry - ENTRADA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Registrar entrada                      | \n");
    printf(" |                 2- Cancelar entrada                       | \n");                 
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

void telaRegistrarEntrada(void)
{
    char codigodeBarras [13];
    char quantProduto [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- REGISTRAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  Informe o código de barras do produto que será adicionado: ");
    scanf("%[A-Z a-z]", codigodeBarras);
    getchar(); 
    printf(" |  Informe a quantidade de produto adicionado: ");
    scanf("%[A-Z a-z., 0-9., -]", quantProduto);
    getchar(); 
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}



