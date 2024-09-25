#include <stdlib.h>
#include <stdio.h>

#define TAM 10

//q é uma variável auxiliar que irá fazer a adição de novos conteúdos, 
//fazendo a fila circular e não desperdiçar espaço na memória

typedef struct{
	int R, F, Q;
	int vet[TAM];
}filacircular;

void enfileirar(int valor, filacircular*p){
	if(p->Q==TAM+1){
		printf("\n Fila Cheia!");
		exit(0);
	}	
	if(p->R==TAM-1){
		p->R=0; //volta ao início
	}
	else{
		p->R++;
	}
	p->vet[p->R]=valor; //aloca valor dentro da fila na posição do r
	p->Q++; //incrementa q
}

int desenfileirar(filacircular*p){
	int aux; //variável auxiliar
	if(p->Q==0){ //q desce
		printf("\nFila Vazia!");
		exit(1);
	}
	
	aux=p->vet[p->F]; //valor da casa em que f está vai para a auxiliar
	
	if(p->F==TAM-1){
		p->F=0;
	}
	
	else{
		p->F++; //sobe o f para retirar mais
	}
	
	p->Q--; //desce o q
	return aux;
}

int main(void){
	filacircular fila;
	int valor; //valor a ser adicionado
	fila.R=-1;
	fila.F=0;
	fila.Q=0;
	
	for(int i=0; i<TAM; i++){
		printf("Digite o valor a ser enfileirado: \n");
		scanf("%d", &valor);
		enfileirar(valor, &fila);
	}
	
	for(int i=0; i<TAM; i++){
		printf("\nRetirando...");
		printf("\n%d", desenfileirar(&fila));
	}
	
	system("pause");
}
	