#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"

void menuEntradaItens(void)
{
    Entrada* regEntrada;
    CancelarEnt* cancEnt;
    char escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case '1':
                regEntrada = infoEntrada( );
                break;
            case '2':
                cancEnt = infoCancelarEntrada();
                break;
        } 
     
    } while (escolha != '0');

    free (regEntrada);
    free (cancEnt);


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

Entrada* infoEntrada( );
{
    Entrada* ent;
    ent = (Entrada*) malloc(sizeof(Entrada));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- REGISTRAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", ent->codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(ent->codigodeBarras));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", ent->quantProduto);
        getchar();
        
    } while(!lerQuantidade(ent->quantProduto));
    
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

    return ent;
}

CancelarEnt* infoCancelarEntrada()
{
    CancelarEnt* canc;
    canc = (CancelarEnt*) malloc(sizeof(CancelarEnt));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------- CANCELAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", canc->codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(canc->codigodeBarras));
    
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

    return canc;

}



