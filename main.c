#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>


// Assinatura das funções
char  telaPrincipal ( void );
void  telaSobre ( void );

// Assinatura das funções
char telaPrincipal(void);
void telaSobre(void);




int  main ( void )
{
    char tela;
    tela = telaPrincipal ();
    switch (tela)
    {
        /* case '1':
            móduloCadastro();
            parar;
        caso '2':
            móduloCompras();
            parar; */
        case 3:
            telaSobre ();
            break ;
        defaut :
            printf ( " Opcao invalida \n " );
            break ;
    }

   
    return 0 ;

}


char  telaPrincipal ( void )
{
    char opcao;

    system("clear||cls"); 
    printf("| ====================================================================== |\n");
    printf("| ====================|       SIG - Pranty        |===================== |\n");
    printf("| ====================================================================== |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");
    printf("|                      1 - Cadastrar Produtos                            |\n");
    printf("|                      2 - Lista de compras                              |\n"); 
    printf("|                      3 - Informacoes                                   |\n");
    printf("|                      4 - Sair                                          |\n");
    printf("|                                                                        |\n");                                                                      
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ====================================================================== |\n");
    printf("| Escolha uma opcao:                                                     |\n");
    printf("| ====================================================================== |\n");
    scanf("%c", &opcao);

    return opcao;

}

void  telaSobre ( void )
{
    system ( " clear||cls " );
    printf ( " | ----------------------------------------------------------------- | \n " );
    printf ( " | --- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // --- | \n " );
    printf ( " | -------- // Departamento de Computação e Informática // --------- | \n " );
    printf ( " | ----------------------------------------------------------------- | \n " );
    printf ( " |                                                                   | \n " );                                       
    printf ( " |             Disciplina: DCT1106 - PROGRAMAÇÃO - 2022.2            | \n " );
    printf ( " |           Projeto: Sistema de Controle de Despensa Doméstica      | \n " );
    printf ( " |                     Docente: Dr Flávio Gorgonio                   | \n " );
    printf ( " |                                                                   | \n " );
    printf ( " | Este programa consiste no controle das atividades de uma despensa | \n " );
    printf ( " | doméstica, sendo dividida em categorias no intuito de ajudar na   | \n " );
    printf ( " | organização das atividades cotidianas                             | \n " );
    printf ( " |             Equipe: Manuelly Rodrigues e Italo Mauricio           | \n " );
    printf ( " |                                                                   | \n " );
    printf ( " | ----------------------------------------------------------------- | \n " );
    printf ( " | ---------------------- SIG - Pranty - 2022.2 -------------------- | \n " );


}

