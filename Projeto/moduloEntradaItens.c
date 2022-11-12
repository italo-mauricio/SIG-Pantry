#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"

void menuEntradaItens(void)
{
    Entrada* regEntrada;
    CancelarEnt* cancEntrada;
    char escolha;
    do {
        escolha = telaEntradaItens();
        switch(escolha) {
            case '1':
                regEntrada = infoEntrada();
                gravaEntrada(regEntrada);
                free(regEntrada);
                break;
            case '2':
                cancEntrada = infoCancelarEntrada();
                gravaCancelamentoEnt(cancEntrada);
                free(cancEntrada);
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
Entrada* infoEntrada(void)
{
    Entrada* ent;
    ent = (Entrada*)malloc(sizeof(Entrada));
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
        
    } while(!lerQuantidade(ent->codigodeBarras));

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
    ent->status = '1'; //o true mostra que foi cadastrado
    return ent;

}

//Função para gravar no arquivo:
void gravaEntrada(Entrada* ent) 
{
    FILE* fp;
    fp = fopen("entrada.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(ent, sizeof(Entrada), 1, fp);
    fclose(fp);
    
}

//Função para procurar o produto que deseja fazer o cancelamento
CancelarEnt* infoCancelarEntrada(void)
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
        scanf("%s", canc->codigoBarras);
        getchar();
        
    } while (!lerQuantidade(canc->codigoBarras));
    
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();
    canc->status = '1'; 
    return canc;

}


//Função para gravar no arquivo:
void gravaCancelamentoEnt(CancelarEnt* canc) 
{
    FILE* fp;
    fp = fopen("cancentrada.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(canc, sizeof(CancelarEnt), 1, fp);
    fclose(fp);
    
}