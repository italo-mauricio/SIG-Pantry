#include <stdio.h>
#include<stdlib.h>
#include "moduloSaidaItens.h"

void moduloSaidaItens(void)
{
    char escolha;
    do {
        escolha = telaSaidaItens();
        switch(escolha) {
            case '1':
                telaRegistrarSaida();
                break;
            case '2':
                telaCancelarSaida();
                break;
            default:
                printf("Opção inválida!");
                break;
        } 
     
    } while (escolha != '0');

    

}

char telaSaidaItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- SIG-Pantry - SAÍDA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |                  1- Registrar saída                       | \n");
    printf(" |                  2- Cancelar saída                        | \n");                 
    printf(" |                  0- Voltar à tela principal               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

void telaRegistrarSaida(void)
{
    char CodigodeBarras [13];
    char quantProduto [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- REGISTRAR SAÍDA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  Informe o código de barras do produto que será retirado: ");
    scanf("%[0-9]", CodigodeBarras);
    getchar(); 
    printf(" |  Informe a quantidade de produto retirado: ");
    scanf("%[A-Z a-z., 0-9., -]", quantProduto);
    getchar();
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}

void telaCancelarSaida(void)
{
    char CodigodeBarras [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- REGISTRAR SAÍDA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  Informe o código de barras do produto: ");
    scanf("%[0-9]", CodigodeBarras);
    getchar(); 
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}