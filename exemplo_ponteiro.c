#include <stdio.h> //padrão
#include <stdlib.h> //ponteiro
#include <string.h> //string

//definição de struct
typedef struct{
    //conteúdo
    int mat;
    char nome[40];
    float nota;
}aluno; //nome do formulario

int main()
{
    //transformar o struct em vetores
    aluno ed[4]; //tipo aluno (nome do struct) para especificar que é um vetor de struct
    aluno java[3];
    
    printf("\nTurma de Estrutura de Dados:");
    //looping for para poder carregar os elementos
    for(int i=0; i<4; i++){
        printf("\nDigite a matricula do %d aluno: ", i+1);
        scanf("%d", &ed[i].mat);
        printf("\nDigite a nota do %d aluno: ", i+1);
        scanf("%f", &ed[i].nota);
        getchar(); //getchar para poder utilizar espaços
        printf("\nDigite o nome do %d aluno: ", i+1);
        gets(ed[i].nome); //gets pertence a biblioteca de string
    }
    
    printf("\nTurma de Java: ");
    for(int i=0; i<3; i++){
        printf("\nDigite a matricula do %d aluno: ", i+1);
        scanf("%d", &java[i].mat);
        printf("\nDigite a nota do %d aluno: ", i+1);
        scanf("%f", &java[i].nota);
        getchar();
        printf("\nDigite o nome do %d aluno: ", i+1);
        gets(java[i].nome);
    }
    
    //comparação entre duas pontas para verificar se há dados repetidos
    //utilizando dois "for", sendo um "fixado" a fim de comparar com os dados do outro
    //no exemplo, está comparando a turma de ed com de java
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if(ed[i].mat == java[j].mat){
                puts(ed[i].nome);
                //compara a matrícula com o if
                //imprime o nome de quem tem a matrícula igual
            }
        }
    }
    
    system("pause"); //pode colocar return
}