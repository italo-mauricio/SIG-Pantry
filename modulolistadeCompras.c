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
    int escolha;
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
            break;
    }

    } while(escolha != '0');
    printf("Obrigado, volte sempre!");

    return 0;


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
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}



char telaAlimentoVencimento(void)

{
    char esc;
    char nome[20];
    char datadeCadastro[10];
    system ( " clear||cls " );
    printf("| ============================================================== | \n");
    printf("| -------------------------------------------------------------- | \n");
    printf("| ------------ | Alimentos proximos ao vencimento | ------------ | \n");
    printf("|                                                                | \n");
    printf("|  1- Informe o nome:  ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("|  2- Informe a data de cadastro no sistema: ");
    scanf("%[0-9 /]", datadeCadastro);
    getchar();
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
  /*  printf("| Deseja receber uma notificacao quando o alimento estiver proxi | \n");
    printf("| mo do vencimento? Sim ou nao?                                  | \n"); */
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);

    return esc;

}



char telaHigieneVencimento(void)
{
    char nome[20];
    char datadeCadastro[10];
    char esc;
    system ( " clear||cls " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------- | Itens de higiene proximos ao vencimento | --------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("|  2- Informe a data de cadastro no sistema: ");
    scanf("%[0-9 / ]", datadeCadastro);
    getchar();
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
  /*  printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n"); */
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);
    getchar();

    return esc;

}


char telaLimpezaVencimento(void)
{
    char nome[20];
    char datadeCadastro[10];
    char esc;
    system ( " clear||cls " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| -------- | Itens de limpeza proximos ao vencimento | -------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome:  ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("|  2- Informe a data de cadastro no sistema: ");
    scanf("%[0-9 /]", datadeCadastro);
    getchar();
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
  /*  printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n"); */
    printf(" Press ENTER to exit...");   
    scanf("%c", &esc);

    return esc;

}


char telaMontarLista()
{
    char nome[20];
    char categoriaProduto[10];
    int quantidadeProduto;
    char esc;
    system ( " clear||cls " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua Lista de Compras| -------------- | \n");
    printf("|                                                               | \n");
    printf("|  1- Informe o nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("|  2- Informe a categoria do produto: ");
    scanf("%[A-Z a-z]", categoriaProduto);
    getchar();
    printf("|  3- Informe a quantidade do produto: ");
    scanf("%d", &quantidadeProduto);
    getchar();
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);
    
   /* printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n"); */

    return esc;
    
}