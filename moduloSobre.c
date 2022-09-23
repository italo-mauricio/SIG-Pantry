#include <stdio.h>
#include <stdlib.h>
#include "moduloSobre.h"

char moduloSobre(void) {
    int escolha;
    do {
        escolha = telaSobre();
        switch(escolha) {
            case 1:
                telaSobre();
                break;
            default:
                break;           
        } 
              
    } while (escolha != 0);
    return escolha;
}



char telaSobre(void)
{
    char esc;
    system ( " clear||cls " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // --- | \n " );
    printf ( " | -------- // Departamento de Computação e Informática // ---------- | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " |                                                                    | \n " );                                       
    printf ( " |            Disciplina: DCT1106 - PROGRAMAÇÃO - 2022.2              | \n " );
    printf ( " |         Projeto: Sistema de Controle de Despensa Doméstica         | \n " );
    printf ( " |                    Docente: Dr Flavius Gorgonio                    | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " |  Este programa consiste no controle das atividades de uma despensa | \n " );
    printf ( " |    doméstica, sendo dividida em categorias no intuito de ajudar na | \n " );
    printf ( " |                organização das atividades cotidianas.              | \n " );
    printf ( " |           Developers: Manuelly Rodrigues e Italo Mauricio          | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---------------------- SIG - Pranty - 2022.2 --------------------- | \n " );
    printf ("\t\t\t>>> Tecle <ENTER> para continuar.. " );
    scanf("%c", &esc);

    return esc;


}