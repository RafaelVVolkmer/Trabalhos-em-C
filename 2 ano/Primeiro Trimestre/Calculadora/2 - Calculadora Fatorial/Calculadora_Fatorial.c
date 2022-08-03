#include <stdio.h>

float calculo (float numero)
{

  float resposta;
  
  for( ; numero >= 1; numero--)
  {
   resposta *= numero; 
  }
  
  return resposta;
}

int main (void)
{
  float numero;
  
  printf("Digite o número que deseja fatorar: ");
  scanf("%f", &numero);
  
  calculo();
  
  printf("Seu valor fatorado é: %i", &resposta);
  scanf("%f", &numero);
  
  return 0;
}
