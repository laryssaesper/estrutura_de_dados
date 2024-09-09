#include <stdio.h>
#include <stdlib.h>

#define constante 5

typedef struct{
	int tamanho[constante];
	int frente;
	int retaguarda;
}fila;

void enfileirar(int valor, fila*p){
	if(p->retaguarda==constante){
		printf("\nA fila esta cheia.");
		exit(0);
	}
	p->retaguarda++;
	p->tamanho[p->retaguarda]=valor;
}

int desenfileirar(fila*p){
	int local;
	if(p->frente==constante){
		printf("\nA fila esta vazia.");
		exit(1);
	}
	local=p->tamanho[p->frente];
	p->frente++;
	return local;
}

int main(void){
	fila fila;
	int valor;
	fila.frente=0;
	fila.retaguarda=-1;
	for(int i=0; i<constante; i++){
		printf("Valor que sera enfileirado: ");
		scanf("%d", &valor);
		enfileirar(valor, &fila);
	}
	for(int i=0; i<constante; i++){
		printf("\nRetirando...");
		printf("\n%d", desenfileirar(&fila));
	}
	return 0;
}