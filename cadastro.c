
#include<stdio.h>
#include<stdlib.h>

/*
DENTRO DESSE CADASTRO: nome, data de validade, local de armazenamento na despensa (armário, geladeira, 
área de serviço...); opção: consultar produtos já existentes (tela principal)
*/

char telaCadastro(void);
char telaAlimento(void);
char telaHigiene(void);
char telaLimpeza(void);

int  main ( void )
{
    char tela;
    tela = telaCadastro ();
    switch (tela)
    {
        case '1':
            cadastrarAlimento();
            break;
        case '2':
            cadastrarHigiente();
            break; 
        case  '3' :
            cadastrarLimpeza();
            break;
        case '4' :
            printf ( "Opcao invalida!\n" );
            break;
    }
}
char telaCadastro(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------ SIG-Pantry - CADASTRO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ------------ \t1- Cadastrar item alimentar -------------- | \n");
    printf(" | ---------- \t2- Cadastrar item de higiene pessoal ------- | \n"); 
    printf(" | ------------- \t3- Cadastrar item de limpeza ------------ | \n");    
    printf(" | -------------- \t0- Voltar a tela principal ------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);

    return opcao;

}

char telaAlimento(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- CADASTRAR ITEM ALIMENTAR -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de Validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaHigiene(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------- CADASTRAR ITEM DE HIGIENE PESSOAL ------------ | \n");
    printf(" |                                                           | \n");
    printf(" | --------------- 1- Nome do Item ------------------------- | \n");
    printf(" | --------------- 2- Data de Validade --------------------- | \n"); 
    printf(" | --------------- 3- Local de armazenamento --------------- | \n");    
    printf(" | --------------- 0- Voltar a tela principal -------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaLimpeza(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- CADASTRAR ITEM DE LIMPEZA -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de Validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;
    

}
