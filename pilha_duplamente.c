#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//lista duplamente encadeada
//contém dois ponteiros que ligam o nó anterior e posterior, podendo ir e voltar durante o processo
typedef struct dupla{
	int dado;
	struct dupla *elink, *dlink; //links direito e esquerdo com recursividade
}no;

no *crialde(int n){
	no *ini, *p; //ponteiro para início, ponteiro e auxiliar
	int valor;
	ini=NULL;
	for(int i=0; i<n; i++){
		printf("\nDigite o valor %d da lista: ", i+1);
		scanf("%d", &valor);
		
		p=(no*) malloc(sizeof(no));
		p->dado=valor; //coloca o valor dado no dado
		p->elink=NULL; //começa como nulo até ser ligado
		
		if(ini != NULL){
			ini->elink=p; //liga um nó ao outro
		}
		
		p->dlink=ini;
		ini=p;
	}
	return ini; //a função é um ponteiro, pois retorna um ponteiro
	//a função é tipo struct no, pois cria um no com os dados da struct
}

void escrevelista(no*p){
	while(p != NULL){
		printf("%d\t", p->dado);
		p=p->dlink;
	}
}

int main (void){
	no *primeira;
	int n;
	printf("Criando uma lista encadeada");
	
	do{
		printf("\nEntre com o número de nois: ");
		scanf("%d", &n);
	}while(n<0);
	
	primeira = crialde(n);
	
	if(primeira != NULL){
		printf("\nLista Criada\n");
		escrevelista(primeira);
	}
	else{
		printf("\nLista Vazia\n");
	}
	
	return(0);
}