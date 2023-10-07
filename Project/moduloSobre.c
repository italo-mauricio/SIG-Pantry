#include <stdio.h>
#include <stdlib.h>
#include "moduloSobre.h"
#include <string.h>

void displayAboutScreen(void)
{
    system("clear||cls");
    printf("| ------------------------------------------------------------------ |\n");
    printf("| ---- // FEDERAL UNIVERSITY OF RIO GRANDE DO NORTE - CERES // ----- |\n");
    printf("| -------- // Department of Computer Science and Informatics // ---- |\n");
    printf("| ------------------------------------------------------------------ |\n");
    printf("|                                                                    |\n");
    printf("|            Course: DCT1106 - PROGRAMMING - 2022.2                  |\n");
    printf("|         Project: Home Pantry Control System                        |\n");
    printf("|                Instructor: Dr. Flavius Gorgônio                    |\n");
    printf("|                                                                    |\n");
    printf("|  This program is about controlling home pantry activities, divided |\n");
    printf("|  into categories to help with daily organization.                  |\n");
    printf("|                                                                    |\n");
    printf("|          Developers: Manuelly Rodrigues and Italo Maurício         |\n");
    printf("|                                                                    |\n");
    printf("| ------------------------------------------------------------------ |\n");
    printf("| ---------------------- SIG - Pantry - 2022.2 --------------------- |\n");
    printf("| Press any key to exit...\n");
    getchar();
}
