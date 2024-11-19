#include <stdio.h> //padrão
#include <stdlib.h> //ponteiro

#define TAM 8 //constante

//definir struct
typedef struct{
	int R; //retaguarda
	int F; //frente
	int vet[TAM];
}filavet;

//função enfileirar
//void = não retorna nada para a main, só executa
void enfileirar(int valor, filavet*p){
	//verificar se a fila está cheia
	//fila cheia quando o R chega ao limite (tamanho do vetor)
	if(p->R==TAM-1){
		printf("\nFila cheia");
		exit(0);
	}
	p->R++; //incrementa R
	p->vet[p->R]=valor; //Armazena valor dentro do vetor (fila)
}

//função desenfileirar
//int = retorna para main
int desenfileirar(filavet*p){
	int aux; //variável auxiliar para se comunicar com a main
	//F==TAM, pois se for TAM-1, não retira o último a ser colocado na fila
	if(p->F==TAM){
		printf("\nFila vazia");
		exit(1);
	}
	aux=p->vet[p->F]; //desenfileira o vetor 
	p->F++; //incrementa F, pois fica embaixo e precisa subir até nivelar com R
	return aux; //retorna valor para a main
}

//função main
int main (void) {
	filavet fila; //declarar struct
	int valor; //variável que recebe o valor digitado
	fila.R=-1;
	fila.F=0;
	//chama função enfileirar
	for(int i=0; i<TAM; i++){
		printf("Digite o valor a ser enfileirado: \n");
		scanf("%d", &valor);
		enfileirar(valor, &fila);		
	}
	//chama função desenfileirar
	for(int i=0; i<TAM; i++){
		printf("\n%d", desenfileirar(&fila));
	}
	return 0;
}