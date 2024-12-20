#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merge(int *a, int s1, int e1, int s2, int e2, int* m1, int* m2){
    int len1=e1-s1+1;
    int len2=e2-s2+1;
    int p1=0;
    int p2=0;
    int p=s1;
    
    memcpy(m1,a+s1,sizeof(int)*len1);
    memcpy(m2,a+s2,sizeof(int)*len2);
    
    while (p1 < len1 && p2 < len2) {
        if(m1[p1] < m2[p2]){
            a[p++] = m1[p1++];
        }
        else{
            a[p++] = m2[p2++];
        }
    }
    
    while (p1 < len1) {
        a[p++] = m1[p1++];
    }
    
    while(p2 < len2){
        a[p++] = m2[p2++];
    }
    
    return 0;
}

int mergeSort(int* a,int len){
    int step = 1;
    int *m1 = (int *)malloc(len*sizeof(int));
    if(!m1) return -1;
    int *m2 = (int *)malloc(len*sizeof(int));
    if(!m2) return -1;
    
    while(step < len) {
        int i, s1, e1, s2, e2;
        
        for(i=0; (i+step-1) < (len-1); i+=2*step){
            s1=i;
            e1=i+step-1;
            s2=e1+1;
            (i+2*step-1) < (len-1) ? (e2=i+2*step-1) : (e2=len-1);
            merge(a, s1 , e1, s2, e2, m1, m2);
        }
        
        step=step<<1;
    }
    return 0;
}

int main(void){
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42, 10}; //vetor exemplo
    
    int len=7;
    mergeSort(a,len);
    
    int i;
        
    for (i=0; i<len; i++) {
        printf("%d\t", a[i]);
    }
    
    printf("\n");
    
    return 0;
}