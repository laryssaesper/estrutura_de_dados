//fazer um código que crie um formulário de cadastro para clientes com cpf, idade, renda e nome
//5 clientes
//com struct
//faça a leitura dos dados
//imprimir quantidade de clientes com renda superior a 5000.00

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float cpf;
    int idade;
    float renda;
    char nome[40];
}cliente;

int main(void)
{
    cliente form[5];
    
    for(int i=0; i<5; i++){
        printf("\nDigite o CPF do %d cliente: ", i+1);
        scanf("%f", &form[i].cpf);
        
        printf("\nDigite a idade do %d cliente: ", i+1);
        scanf("%d", &form[i].idade);
        
        printf("\nDigite a renda do %d cliente: ", i+1);
        scanf("%f", &form[i].renda);
        
        getchar();
        printf("\nDigite o nome do %d cliente: ", i+1);
        gets(form[i].nome);
    }
    
    printf("Os clientes que tem a renda igual ou superior a R$5000 sao:\n");
    
    for(int i=0; i<5; i++){
        if(form[i].renda >= 5000){
            puts(form[i].nome);
        }
    }
    
    return 0;
}