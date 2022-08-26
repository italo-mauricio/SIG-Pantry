#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>










int main(void){
    int tela;
    system("clear||cls"); 
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ----- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // ------ |\n");
    printf("| -------- // Departamento de Computacao e Informatica // ---------------|\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");                                       
    printf("|               Disciplina: DCT1106 - PROGRAMACAO - 2022.2               |\n");
    printf("|          Projeto: Sistema de Controle de Despensa Domestica            |\n");
    printf("|            Colaboradores:  Manuelly Victor e Italo Mauricio            |\n"); 
    printf("|                  Docente: Dr Flavius Gorgonio                          |\n");
    printf("|                                                                        |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ---------------------- SIG - Pranty - 2022.2 ------------------------- |\n");
    printf("| ----------------- >>> Tecle <ENTER> para continuar... ---------------- |\n");
    

    tela = telaPrincipal();
    switch (tela)
    {
    case 1:
        printf("a");
        break;

    default:
        break;
    }
}
int telaPrincipal(void)

{
    int d;
    system("clear||cls"); 
    printf("| ====================================================================== |\n");
    printf("| ====================|       SIG - Pranty        |===================== |\n");
    printf("| ====================================================================== |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");
    printf("|                      1 - Cadastrar Produtos                            |\n");
    printf("|                      2 -                                               |\n"); 
    printf("|                      3 -                                              |\n");
    printf("|                      4 - Sair                                          |\n");
    printf("|                                                                        |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ====================================================================== |\n");
    scanf("%d",d);
    return d;

} 


