//FAZER UM PROGRAMA UM FORMULÁRIO DE CLIENTES COM SEGUINTES DADOS: ID, IDADE, RENDA E NOME. 
//UTILIZE STRUCT (SLIDES 4 A 7). CADASTRAR 5 PESSOAS. AO FINAL O PROGRAMA DEVE EXIBIR QUANTOS 
//SÃO MAIORES DE IDADE.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	int id, idade;
	float renda;
	char nome[50];
}cadastro;

int main(void){
	cadastro cliente[5];
	
	for (int i=0; i<5; i++){
		printf("\ncadastro de cliente %d", i+1);
		printf("\nid: ");
		scanf("%d", &cliente[i].id);
		printf("\nidade: ");
		scanf("%d", &cliente[i].idade);
		printf("\nrenda: ");
		scanf("%f", &cliente[i].renda);
		printf("\nnome: ");
		scanf("%s", cliente[i].nome);		
	}	
	
	printf("\nClientes que sao maiores de idade: ");
	
	for (int i=0; i<5; i++){
		if (cliente[i].idade>=18){
			printf("\n%s", cliente[i].nome);
		}
	}	
		
	return (0);
}

