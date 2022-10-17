#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"

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
                telaCancelarEntrada();
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
    char codigodeBarras [15];
    char quantProduto [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- REGISTRAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%[0-9]", codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(codigodeBarras));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", quantProduto);
        getchar();
        
    } while (!lerQuantidade(quantProduto));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("clear");
}

void telaCancelarEntrada(void)
{
    char codigodeBarras [13];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------- CANCELAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(codigodeBarras));
    
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

}


