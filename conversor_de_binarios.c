#include <stdlib.h>
#include <stdio.h>

#define constante 50

typedef struct{
	int vetor[constante];
	int topo;
}conversor_binario;

void empilha(int valor, conversor_binario*p){
    if(p->topo==constante){
        printf("\nCHEIO");
        exit(0);
    }
    p->topo++;
    p->vetor[p->topo]=valor;
}

int desempilha(conversor_binario*p){
    int local;    
    if(p->topo<0){
        printf("\nVAZIO.");
        exit(1);
    }    
    local=p->vetor[p->topo]; 
    p->topo--;
    return local;
}

int main(void){
	conversor_binario conversor_binario;
	int valor, resto;
    conversor_binario.topo=-1;
    
	printf("Digite o valor: ");
	scanf("%d", &valor);    
	
	while (valor>0){
		valor=valor/2; //atualiza valor
		resto=valor%2; //guarda resto
		empilha(resto, &conversor_binario);
	}
	
	while (conversor_binario.topo>=0){
        printf("%d", desempilha(&conversor_binario));
    }
    
	return (0);
}