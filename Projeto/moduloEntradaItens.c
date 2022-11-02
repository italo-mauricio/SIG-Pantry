#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"

void menuEntradaItens(void)
{
    char escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case '1':
                infoEntrada( );
                break;
            case '2':
                infoCancelarEntrada();
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

//Função para entrada de um item ao estoque
void infoEntrada(void)
{
    Entrada* ent;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- REGISTRAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    ent = (Entrada*)malloc(sizeof(Entrada));
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

}

//Função para procurar o produto que deseja fazer o cancelamento
void infoCancelarEntrada(void)
{
    CancelarEnt* canc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------- CANCELAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");  
    canc = (CancelarEnt*) malloc(sizeof(CancelarEnt));  
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

}

//Função para gravar no arquivo:
void gravaEnt(Entrada* ent) 
{
    FILE* fp;
    fp = fopen("ent.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(ent, sizeof(Entrada), 1, fp);
    fclose(fp);
    
}



