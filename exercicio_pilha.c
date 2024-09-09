#include <stdio.h>
#include <stdlib.h>

#define constante 5

typedef struct{
	int tamanho[constante];
	int topo;
}pilha;

void empilhar(int valor, pilha*p){
	if(p->topo==constante-1){
		printf("\nA pilha esta cheia.");
		exit(0);
	}
	p->topo++;
	p->tamanho[p->topo]=valor;
}

int desempilhar(pilha*p){
	int local;
	if(p->topo==-1){
		printf("\nA pilha esta vazia.");
		exit(1);
	}
	local=p->tamanho[p->topo];
	p->topo--;
	return local;
}

int main(void){
	pilha pilha;
	int valor;
	pilha.topo=-1;
	for(int i=0; i<constante; i++){
		printf("Valor que sera empilhado: ");
		scanf("%d", &valor);
		empilhar(valor, &pilha);
	}
	for(int i=0; i<constante; i++){
		printf("\nDesempilhando...");
		printf("\n%d", desempilhar(&pilha));
	}
}