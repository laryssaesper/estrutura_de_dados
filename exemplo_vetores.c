#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaração de variáveis
    int vet[8], num, achei=0;
    
    //looping for para abastecer vetor
    for(int i=0; i<8; i++)
    {
        printf("\nDigite o elemento da posição %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    
    //& aloca na memória
    //para buscar um número do vetor abastecido
    printf("\n\nQual o número que deseja buscar?");
    scanf("%d", &num);
    
    //condicional para verificar se o número aparece em alguma posição e especificar em qual
    //a variável "achei" deixa de valer 0 e muda para 1
    for(int i=0; i<8; i++)
    {
        if(vet[i]==num)
        {
            printf("\nO número %d apareceu na posição %d", num, i+1);
            achei=1;
        }
    }
    
    //condicional para quando "achei" for diferente de 1
    if(achei!=1)
    {
        printf("\nElemento não encontrado");
        system("pause");
    }
}