#include<stdio.h>
#include<stdlib.h>

char telaAtualizar(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- SIG-Pantry - ATUALIZAR ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ------------ 1- Quantidade de item alimentar ------------ | \n");
    printf(" | -------- 2- Quantidade de item de higiene pessoal ------- | \n"); 
    printf(" | ----------- 3- Quantidade de item de limpeza ------------ | \n"); 
    printf(" | ------- 4- Local de armazenamento de item alimentar ----- | \n");    
    printf(" | ---------------- 0- Voltar a tela principal ------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);

    return opcao;

}