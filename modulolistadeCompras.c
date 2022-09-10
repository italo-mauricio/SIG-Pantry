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
            printf ("Opcao invalida \n");
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
    printf(" |      1- Visualizar itens alimentares proximos do vencimento          | \n");
    printf(" |      2- Visualizar itens de higiene pessoal proximos do vencimento   | \n");
    printf(" |      3- Visualizar itens de limpeza proximos do vencimento           | \n");
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
    int datadeCadastro[10], datadeVencimento[10];
    char esc;
    printf("| ============================================================== | \n");
    printf("| -------------------------------------------------------------- | \n");
    printf("| ------------ | Alimentos proximos do vencimento | ------------ | \n");
    printf("|                                                                | \n");
    printf("|  1- Informe o nome:  \n");
    scanf("%[A-Za-z]", nome);
    printf("|  2- Informe a data de cadastro no sistema: \n");
    scanf("%[0-9, -, /, .]", datadeCadastro);
    printf("|  3- Data de vencimento: \n");
    scanf("%[0-9, -, /, .]", datadeVencimento);
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Deseja receber uma notificacao quando o alimento estiver proxi | \n");
    printf("| mo do vencimento? Sim ou nao?                                  | \n");
    scanf("%c", &esc);
    getchar();

}



char telaHigieneVencimento(void)
{
    
    char nome[20];
    int datadeCadastro[10], datadeVencimento[10];
    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------- | Itens de higiene proximos do vencimento | --------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome:  \n");
    scanf("%[A-Za-z]", nome);
    printf("|  2- Informe a data de cadastro no sistema: \n");
    scanf("%[0-9, -, /, .]", datadeCadastro);
    printf("|  3- Data de vencimento: \n");
    scanf("%[0-9, -, /, .]", datadeVencimento);
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n");
    scanf("%c", &esc);
    getchar();

}



char telaLimpezaVencimento(void)
{
    
    char nome[20];
    int datadeCadastro[10], datadeVencimento[10];
    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| -------- | Itens de limpeza proximos do vencimento | -------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome:  \n");
    scanf("%[A-Za-z]", nome);
    printf("|  2- Informe a data de cadastro no sistema: \n");
    scanf("%[0-9, -, /, .]", datadeCadastro);
    printf("|  3- Data de vencimento: \n");
    scanf("%[0-9, -, /, .]", datadeVencimento);
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n");
    scanf("%c", &esc);
    getchar();

}


char telaMontarLista()
{

    char nome[20], categoriaProduto[10];
    int quantidadeProduto[10];
    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua Lista de Compras| -------------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome:  \n");
    scanf("%[A-Z, a-z]", nome);
    printf("| 2- Categoria do produto: \n");
    scanf("%[A-Z, a-z", categoriaProduto);
    printf("| 3- Quantidade do produto:  \n");
    scanf("%[0-9]", quantidadeProduto);
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n");
    scanf("%c", &esc);
    getchar();

}