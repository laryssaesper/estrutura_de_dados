#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//pilha dinâmica: contém  uma lista encadeada no lugar de um vetor, não sendo linear

typedef struct lista{
    int dado;
    struct lista*link; 
}no;

// crialista é tipo no (struct) e um ponteiro, pois ela retorna outro ponteiro (return topo)
no *crialista(int n){
    no *topo, *p;
    int valor;
    topo=NULL; //começa como nulo, pois a pilha começa vazia
    
    for(int i=1; i<=n; i++){
        printf("\nDigite o valor %d da pilha: ", i);
        scanf("%d", &valor);
        p=(no*)malloc(sizeof(no)); // alocar um espaço na memória do tamanho de um no
        p->dado=valor; //o ponteiro irá apontar para o espaço do dado e colocar o valor
        p->link=topo; //o topo irá linkar o nó feito por último, no anterior. fazendo com que este se torne o primeiro
        topo=p; // assim, o novo nó irá se tornar o novo topo da lista
    }
    return topo;
}

void escrevelista(no*p){
    while(p!=NULL){
        printf("%d\t", p->dado);
        p=p->link;
    }
    printf("\n");
}

int main(void){
    no*primeira;
    int n;
    printf("Criando pilha\n");
    
    do{
        printf("\nEntre com o numero de nos: ");
        scanf("%d", &n);
    }
    while(n<0);{
      primeira=crialista(n);
      if(primeira!=NULL){
          printf("\nPilha criada\n");
          escrevelista(primeira);
      }
      else{
          printf("\nPilha vazia\n");
      }
    }
    system("pause");
    return 0;
}