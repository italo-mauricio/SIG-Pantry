#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"

int lerEmail(char email[])
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
      if (ponto) { // se já encontrou . depois de @@
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
        return 0;
    else
        return 1;


}

int lerUsernameSenha(char usernameSenha[]) 
{// retorna 0 se for true e 1 se for false
  int tamanho = strlen(usernameSenha);   
  if (tamanho < 4) { //para não ter usuários com só: @ ou a@ ou 12... 
    return 1;
  } else {
    for (int i = 0; i < tamanho; i++) { 
      if ((usernameSenha[i] == 'a') && (usernameSenha[i] <= 'z')) { 
        return 0;
      }
      else if ((usernameSenha[i] == 'A') && (usernameSenha[i] <= 'Z')) {
        return 0;
      }
      else if ((usernameSenha[i] == '_') || (usernameSenha[i] == '-')) {
        return 0;
      }
      else if ((usernameSenha[i] == '@') || (usernameSenha[i] == '.')) {
        return 0;
      }
      else if ((usernameSenha[i] == '0') && (usernameSenha[i] <= 9)) {
        return 0;
      }   
      else {
        break;  
      }     
    }

    } 
    
}

int lerLetras(char nome[])
{

  int tamanho = strlen(nome);

  if (tamanho < 1) {
      return 1; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((nome[i] <= 'z') && (nome[i] >= 'A'))
        {
           if ((nome[i] <= 'a') && (nome[i] <= 'Z') || (nome[i] == ' ')) 
            return 0;
              if((nome[i] == '@') || (nome[i] == 0) || (nome[i] <= 9)) {
                return 1;
              }
            } else{  
              return 1;
      
              }          
      }    

  }


int dataValida(int maiorDia[]) { //adaptado de by @flgorgonio
  
  int maiorDia;
  int aa;
  int mm;
  int dd;
      if (aa < 0 || mm < 1 || mm > 12 || dd < 1)
          return 0;
      if (mm == 2) {
          if (bissexto(aa))
            maiorDia = 29;
          else
            maiorDia = 28;
        } else if (mm == 4 || mm == 6 ||
                    mm == 9 || mm == 11) {
                      maiorDia = 30;
        } else
          maiorDia = 31;

        if (dd > maiorDia)
          return 0;

        return 1;
        }


int anoBissexto(int aa) { //adaptado de by @flgorgonio
    if ((aa % 4 == 0) && (aa % 100 != 0)) {
      return 1;
        } else if (aa % 400 == 0) {
          return 1;
    } else {
      return 0;
  }
}

  
int lerQuantidade(char numero[], int tamanho)
{
  tamanho = strlen(numero);

  if (tamanho < 1) {
      return 1; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((numero[i] <= '9') && (numero[i] >= '0'))
        {
              if((numero[i] == '@') || (numero[i] == '.') || (numero[i] == ';')) {
                return 1;
              }
            } else{  
              return 1;
      
              }          
      } 

}


void deixarTelaLimpa(void) //adaptado de by @flgorgonio
{
  if(system("clear") || system("cls")) {
  }
  
}