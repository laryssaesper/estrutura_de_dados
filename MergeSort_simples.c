#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int i = 0;
    int j = 0;
    int k = inicio;
    
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int vet_esquerdo[n1], vet_direito[n2]; 

    for (int x = 0; x < n1; x++) {
        vet_esquerdo[x] = vetor[inicio + x];
    }

    for (int x = 0; x < n2; x++) {
        vet_direito[x] = vetor[meio + 1 + x];
    }

    while (i < n1 && j < n2) {
        if (vet_esquerdo[i] <= vet_direito[j]) {
            vetor[k] = vet_esquerdo[i];    
            i++;
        } 
        
        else {
            vetor[k] = vet_direito[j];    
            j++;
        }    
        
        k++;   
    }   

    while (i < n1) {
        vetor[k] = vet_esquerdo[i];    
        i++;    
        k++;    
    }    

    while (j < n2) {
        vetor[k] = vet_direito[j];    
        j++;    
        k++;    
    }    
}

void mergeSort(int vetor[], int inicio, int fim) {  
    if (inicio < fim) {  
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }  
}  
  
int main(void) {  
    int vetor[] = {12, 31, 25, 8, 32, 17, 40, 42, 10}; //vetor exemplo
    
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Antes de arrumar os elementos:\n");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", vetor[i]);  
    }  
    printf("\n");

    mergeSort(vetor, 0, n - 1);

    printf("\nDepois de arrumar os elementos:\n");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", vetor[i]);  
    }  
    printf("\n");

    return 0;  
}