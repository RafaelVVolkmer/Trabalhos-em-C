#include <stdio.h>
#include <locale.h>

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
    setlocale(LC_ALL, "");

    float numero;
  
    printf("Digite o número que deseja fatorar: ");
    scanf("%f", &numero);
  
    float resposta = calculo(numero);
  
    printf("Seu valor fatorado é: %i", resposta);
  
    return 0;
}
