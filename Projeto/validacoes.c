#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"



//------------------------------------------------------------------//
//                       Validação de Email                         //
//                                                                  //
// Código by: https://pt.stackoverflow.com/users/110948/rogério-dec //
//------------------------------------------------------------------//


// retorna 0 se for false e 1 se for true

int lerEmail(char email[])
{
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
         break; // não pode ter uma segunda @
      arroba++;
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
        return 1;
    else
        return 0;

}





// --------------------------------------- |
//        Validação de Username            |
// --------------------------------------  |


int lerUsernameSenha(char usernameSenha[]) 
{
  int tamanho = strlen(usernameSenha);   
  if (tamanho < 4) { //para não ter usuários com só: @ ou a@ ou 12... 
    return 0;
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
    return 1; 
    
}







// --------------------------------------- |
//        Validação de Letras              |
// --------------------------------------  |

int lerLetras(char nome[])
{

  int tamanho = strlen(nome);

  if (tamanho < 1) {
      return 0; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((nome[i] <= 'z') && (nome[i] >= 'A'))
        {
           if (((nome[i] <= 'a') && (nome[i] <= 'Z')) || (nome[i] == ' ')) {
            return 1;
           }
              if((nome[i] == '@') || (nome[i] == 0) || (nome[i] <= 9)) {
                return 0;
              }
            } else{  
              return 0;
      
              }          
      }
      return 1;    
  }

int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char decimais[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};




//------------------------------------------------------------------//
//                       Validação de Email                         //
//                                                                  //
// Código by: https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas //
//------------------------------------------------------------------//



int valida_data(int dia, int mes, int ano) //by https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas
    {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}





// ---------------------------------------- |
//        Validação de numeros              |
// ---------------------------------------  |

  
int lerQuantidade(char numero[])
{
  int tamanho = strlen(numero);

  if (tamanho < 1) {
      return 0; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((numero[i] <= '9') && (numero[i] >= '0'))
        {
              if((numero[i] == '@') || (numero[i] == '.') || (numero[i] == ';')) {
                return 1;
              }
            } else{  
              return 0;      
              }          
      }

      return 1;
}




void deixarTelaLimpa(void) //adaptado by @flgorgonio
{
  if(system("clear") || system("cls")) {
  }
  
}