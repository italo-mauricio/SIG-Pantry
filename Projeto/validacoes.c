#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valiacoes.h"

int lerEmail(void)
{
  char email[50]={"abc@xyz.com"};
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for

    if (i == tam && depoisPonto > 1)
        printf("Valido");
    else
        printf("Invalido");





}


int lerCPF(void)
{


}


int lerData(void)
{


}


int lerCodigoBarras(void)
{


} 


int lerNome(void)
{
    char tamanho;
    char i;
    char nome [20];
    tamanho = strlen(nome);
    if (tamanho > 1) {
        return 0;
    }
        for (int i = 0; i < tamanho; i++) {
            if (nome[i] == 'a' && nome[i] <= 'z') {
                return 0;
            }
            if (nome[i] == 'A' && nome[i] <= 'Z') {
                return 0;
            } 
            if (nome[i] == ' ') {
                return 0;  
            }         
            if (nome[i] == '.') {
                return 1;
            }
            if (nome[i] == ',') {
                return 1;
            }
            if (nome[i] == '/') {
                return 1;
            }
            if (nome[i] == ';') {
                return 1;
            }
            else {
                return 1;  
            }          
        }  
}

}