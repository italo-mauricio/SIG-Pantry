#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>


// Assinatura das funções
char telaPrincipal (void);
char telaCadastroUsuario(void);
char telaCadastroItens(void);
char telaListadeCompras(void);
char telaRelatorio(void);
char telaSobre (void);


int  main (void){

    char escolha;
        escolha = telaPrincipal();
        switch (escolha) {
        case '1':
            telaCadastroUsuario();
            break;
        case '2':
            telaCadastroItens();
            break; 
        case  '3':
            telaListadeCompras();
            break;
        case '4':
            telaRelatorio();
            break; 
        case '5':    
            telaSobre ();
            break;
        default:
            printf("Opção inválida");
            break;   
        }
}



char telaPrincipal(void)

{
    setlocale(LC_ALL, "portuguese-brazilian");
    char opcao;
    system ( " clear||cls " );
    printf (" | =================================================================== | \n");
    printf (" | =========================| SIG - Pranty |========================== | \n");
    printf (" | =================================================================== | \n");
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" |                                                                     | \n");
    printf (" |                        1 - Cadastrar usuario                        | \n");
    printf (" |                        2 - Cadastrar itens                          | \n");
    printf (" |                        3 - Lista de compras                         | \n");
    printf (" |                        4 - Relatorio                                | \n");
    printf (" |                        5 - Informacoes                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opcao:                                                  | \n");
    printf (" | =================================================================== | \n");
    scanf("%c", &opcao);
    return opcao;


}

char telaCadastroUsuario(void)
{
    setlocale(LC_ALL, "portuguese-brazilian");
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - CADASTAR USUARIO |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                     1- Cadastrar usuario                             | \n");
    printf(" |                     2- Editar cadastro                               | \n"); 
    printf(" |                     3- Listar usuario                                | \n");  
    printf(" |                     3- Remover usuario                               | \n");    
    printf(" |                     0- Voltar a tela principal                       | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");



}

char telaCadastroItens(void)
{
    setlocale(LC_ALL, "portuguese-brazilian");
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - CADASTRAR ITENS |----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                    1- Cadastrar item alimentar                       | \n");
    printf(" |                    2- Cadastrar item de higiene pessoal              | \n"); 
    printf(" |                    3- Cadastrar item de limpeza                      | \n");    
    printf(" |                    0- Voltar a tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");

    getchar();
    
    return opcao;



}

char telaListadeCompras(void)

{   char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |      1- Visualizar itens alimentares proximo ao vencimento           | \n");
    printf(" |      2- Visualizar itens de higiene pessoal proximo ao vencimento    | \n");
    printf(" |      3- Visualizar itens de limpeza proximo ao vencimento            | \n");
    printf(" |      4- Visualizar itens alimentares que estao no estoque            | \n");
    printf(" |      5- Visualizar itens de higiente pessoal que estao no estoque    | \n");
    printf(" |      6- Visualizar itens de limpeza que estao no estoque             | \n");
    printf(" |      7- Montar a propria listinha                                    | \n");    
    printf(" |      0- Voltar a tela principal                                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;



}

char telaRelatorio(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - RELATORIO |----------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                    1- Estoque de alimento                            | \n");
    printf(" |                    2- Estoque de higiene pessoal                     | \n");
    printf(" |                    3- Estoque de limpeza                             | \n");
    printf(" |                    0- Voltar a tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;



}

char  telaSobre ( void )
{
    char esc;
    setlocale(LC_ALL, "portuguese-brazilian");
    system ( " clear||cls " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // --- | \n " );
    printf ( " | -------- // Departamento de Computação e Informatica // ---------- | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " |                                                                    | \n " );                                       
    printf ( " |            Disciplina: DCT1106 - PROGRAMACAO - 2022.2              | \n " );
    printf ( " |         Projeto: Sistema de Controle de Despensa Domestica         | \n " );
    printf ( " |                    Docente: Dr Flavius Gorgonio                    | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " |  Este programa consiste no controle das atividades de uma despensa | \n " );
    printf ( " |    domestica, sendo dividida em categorias no intuito de ajudar na | \n " );
    printf ( " |                organização das atividades cotidianas.              | \n " );
    printf ( " |             Equipe: Manuelly Rodrigues e Italo Mauricio            | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---------------------- SIG - Pranty - 2022.2 --------------------- | \n " );
    printf ("\t\t\t>>> Tecle <ENTER> para continuar...                              | \n " );
    scanf("%c", &esc);
    return esc;
    
}