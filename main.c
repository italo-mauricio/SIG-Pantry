#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>



// Assinatura das funções
void telaPrincipal(void);
void telaSobre(void);


int main(void)
{
    telaPrincipal();
    telaSobre();
   
    return 0;
}


void telaPrincipal(void)

{
    char opcao;
    char tela;
    system("clear||cls"); 
    printf("| ====================================================================== |\n");
    printf("| ====================|       SIG - Pranty        |===================== |\n");
    printf("| ====================================================================== |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");
    printf("|                      1 - Cadastrar Produtos                            |\n");
    printf("|                      2 -                                               |\n"); 
    printf("|                      3 - Informacoes                                   |\n");
    printf("|                      4 - Sair                                          |\n");
    printf("|                                                                        |\n");                                                                      
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ====================================================================== |\n");
    printf("| Escolha uma opcao:                                                     |\n");
    printf("| ====================================================================== |\n");
    scanf("%d", opcao);
    tela = telaPrincipal();
    switch (tela)
    {
    case '1':
        ;
        break;

    default:
        break;
    }
    return tela;

} 

void sobre(void){
    int telaSobre;
    system("clear||cls"); 
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ----- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // ------ |\n");
    printf("| -------- // Departamento de Computacao e Informatica // ---------------|\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");                                       
    printf("|               Disciplina: DCT1106 - PROGRAMACAO - 2022.2               |\n");
    printf("|          Projeto: Sistema de Controle de Despensa Domestica            |\n");
    printf("|                    Docente: Dr Flavius Gorgonio                        |\n");
    printf("|                                                                        |\n");
    printf("|    Este programa consiste no controle das atividades de uma despensa   |\n");
    printf("|     doméstica, sendo dividido em categorias no intuito de ajudar na    |\n");
    printf("|                  organizacao das atividades cotidianas                 |\n");
    printf("|              Equipe:  Manuelly Rodrigues e Italo Mauricio              |\n"); 
    printf("|                                                                        |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ---------------------- SIG - Pranty - 2022.2 ------------------------- |\n");
    printf("| ----------------- >>> Tecle <ENTER> para continuar... ---------------- |\n");
