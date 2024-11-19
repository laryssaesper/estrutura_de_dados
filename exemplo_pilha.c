#include <stdio.h>
#include <stdlib.h>
//fazer uma pilha com 10 posições de inteiro

//constante
#define TAM 15 //#define nome conteúdo

//define a struct
typedef struct{
    int vet[TAM]; //vetor com o tamanho da pilha
    int topo; //variável de topo da pilha
}pilhavet; //nome da struct

//criar função para empilhar
//void (não retorna nada)
//parâmetros=valor que será inserido, ponteiro para struct pilhavet

void empilha(int valor, pilhavet*p){
    if(p->topo==TAM-1){
        //verifica se a pilha está cheia
        //TAM-1, pois o vetor vai de 0 a 9 e TAM é 10 (o usuário entende de 1 a 10)
        printf("\nPilha cheia");
        exit(0);
    }
    p->topo++; //incrementa topo
    p->vet[p->topo]=valor; //guarda o valor no topo
}

//criar função para desempilhar
int desempilha(pilhavet*p){
    int aux; //variável auxiliar
    
    if(p->topo<0){
        //verifica se a pilha está vazia
        printf("\nPilha vazia");
        exit(1); //exit(1); pois é o segundo exit do código
    }
    
    aux=p->vet[p->topo]; 
    p->topo--; //decrementa topo
    return aux; //retorna auxiliar para main
}

//criar função principal
int main(void){
    pilhavet pilha; //declara struct com nome pilha
    int valor; //valor a ser adicionado pelo usuário
    pilha.topo=-1; //inicia a pilha com valor -1 (começa do 0)
    
    //carregar pilha com for
    for(int i=0; i<TAM; i++){
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d", &valor);
        empilha(valor,&pilha); //chama função empilha e aloca os valores na struct com nome pilha
        //ao invés de seta para o ponteiro, chama o & para endereço de memória
    }
    
    //descarregar pilha
    for(int i=0; i<TAM; i++){
        printf("\n%d", desempilha(&pilha)); //chama a função desempilha e aloca na struct
    }
    
    printf("\n");
    system("pause");
}