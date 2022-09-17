#include <stdio.h>
#include <stdlib.h>
#include "modulolistadeCompras.h"

char telaListadeCompras(void);
char telaAlimentoVencimento(void);
char telaHigieneVencimento(void);
char telaLimpezaVencimento(void);
char telaMontarLista(void);

int  main (void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            telaAlimentoVencimento();
            break;
        /*    char alimentosVencimento;
              do {
                    alimentosVencimento = telaAlimentoVencimento();      // testar com if 
                    switch (alimentosVencimento) {
                    case '1':
                        nomeItemAlimentar();
                        break;
                    case '2':
                        dataCadastroAlimento();
                        break; 
                    case '0':
                        telaListadeCompras();
                            
                    default :
                        printf ("Opcao invalida \n");
                        break;
                } 

                } while(alimentosVencimento != '0'); */

        case '2':
            telaHigieneVencimento();
            break; 
        case  '3':
            telaLimpezaVencimento();
            break;
        case '4':
            telaMontarLista();
            break; 
        default :
            printf ("Opcao invalida!\n");
            break;
    }

    } while(escolha != '0');

    return  0 ;
} 

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |      1- Visualizar itens alimentares proximos ao vencimento          | \n");
    printf(" |      2- Visualizar itens de higiene pessoal proximos ao vencimento   | \n");
    printf(" |      3- Visualizar itens de limpeza proximos ao vencimento           | \n");
    printf(" |      4- Montar a propria listinha                                    | \n");    
    printf(" |      0- Voltar a tela principal                                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}



char telaAlimentoVencimento(void)

{
    char nome[20];
    char datadeCadastro[10];
    char opcao;
    printf("| ============================================================== | \n");
    printf("| -------------------------------------------------------------- | \n");
    printf("| ------------ | Alimentos proximos ao vencimento | ------------ | \n");
    printf("|                                                                | \n");
    printf("| Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf(" | Informe a data de cadastro nesse modelo (__/__/____): \n");
    scanf("%[0-9/.]", datadeCadastro);
    getchar();    
    printf("| 0- Voltar a tela de lista de compras \n");
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    getchar();

    return opcao;
}



char telaHigieneVencimento(void)
{
    char nome[20];
    char datadeCadastro[10];
    char opcao;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------- | Itens de higiene proximos ao vencimento | --------- | \n");
    printf("|                                                               | \n");
    printf("| Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf(" | Informe a data de cadastro nesse modelo (__/__/____): \n");
    scanf("%[0-9/.]", datadeCadastro);
    getchar();    
    printf("| 0- Voltar a tela de lista de compras \n");
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    getchar();
    
    return opcao;
}


char telaLimpezaVencimento(void)
{
    char nome[20];
    char datadeCadastro[10];
    char opcao;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| -------- | Itens de limpeza proximos ao vencimento | -------- | \n");
    printf("|                                                               | \n");
    printf("| Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf(" | Informe a data de cadastro nesse modelo (__/__/____): \n");
    scanf("%[0-9/.]", datadeCadastro);
    getchar();    
    printf("| 0- Voltar a tela de lista de compras \n");
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    getchar();
    
    return opcao;
}


char telaMontarLista()
{
    char nome[20];
    char categoriaProduto[10];
    int quantidadeProduto[10];
    char opcao;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua Lista de Compras| -------------- | \n");
    printf("|                                                               | \n");
    printf(" | Informe o nome: \n");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf(" | Informe a categoria do produyo: \n");
    scanf("%[A-Z a-z]", categoriaProduto);
    getchar();    
    printf("| 0- Voltar a tela de lista de compras \n");
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    getchar();
    
    return opcao;
}