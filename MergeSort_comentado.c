#include <stdio.h>
#include <stdlib.h>

// Função para mesclar subvetores do vetor principal
// o vetor principal é subdividido em dois
void merge(int vetor[], int inicio, int meio, int fim) {
    //indices que vão percorrer os subvetores
    int i = 0; //esquerdo
    int j = 0; //direito
    int k = inicio; //principal
    
    int n1 = meio - inicio + 1; //vetor esquerdo irá do início ao meio
    int n2 = fim - meio; //vetor direito irá do meio +1 ao fim

    // Subvetores temporários com elementos de tamanho n1 e n2
    int vet_esquerdo[n1], vet_direito[n2]; 

    // Copiar dados para subvetores temporários
    for (int x = 0; x < n1; x++) {
        vet_esquerdo[x] = vetor[inicio + x];
    }

    for (int x = 0; x < n2; x++) {
        vet_direito[x] = vetor[meio + 1 + x];
    }

    // Mesclar os dois subvetores de volta no vetor principal
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

    // Copiar os elementos restantes do subvetor esquerdo, se houver
    while (i < n1) {
        vetor[k] = vet_esquerdo[i];    
        i++;    
        k++;    
    }    

    // Copiar os elementos restantes do subvetor direito, se houver
    while (j < n2) {
        vetor[k] = vet_direito[j];    
        j++;    
        k++;    
    }    
}

void mergeSort(int vetor[], int inicio, int fim) {  
    if (inicio < fim) {  
        int meio = (inicio + fim) / 2; //cria dois subvetores
        mergeSort(vetor, inicio, meio); //subvetor 1
        mergeSort(vetor, meio + 1, fim); //subvetor 2
        merge(vetor, inicio, meio, fim); //depois de alinhados, são mesclados
    }  
}  
  
int main(void) {  
    int vetor[] = {12, 31, 25, 8, 32, 17, 40, 42, 10}; //vetor exemplo
    
    //n contém o número de elementos do vetor
    //sizeof(vetor) é o tamanho total do vetor
    //sizeof(vetor[0]) é o tamanho de um só elemento
    int n = sizeof(vetor) / sizeof(vetor[0]);

    //imprime vetor antes de ser ordenado
    printf("Antes de arrumar os elementos:\n");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", vetor[i]);  
    }  
    printf("\n");

    // Chamar o mergeSort para ordenar o vetor
    mergeSort(vetor, 0, n - 1);

    printf("\nDepois de arrumar os elementos:\n");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", vetor[i]);  
    }  
    printf("\n");

    return 0;  
}