/*
  MergeSort utilizando threads

  Autor: Vinicius Teixeira - 3057

  Descrição: 
    O código produz um array de tamanho TAM_ARRAY de números aleatórios e os ordena utilizando a função merge sort e múltiplas threads.
    Para funcionar como o mergesort deve, foi preciso criar uma thread inicial que chamaria
    função mergeSort. Ela fica responsável por começãr as chamadas recursivas utilizando novas threads para cada divisão do array principal.
*/

#include "merge.h"

int main() {
    int i, j;
    Merge params;
    pthread_t tid;

    //Cria um array preenchido com numeros aleatorios e mostra ele pro usuario
    srand(time(NULL));
    printf("Base array: ");
    params.arr = (int *) malloc(sizeof(int) * TAM_ARRAY);
    for(i = 0; i < TAM_ARRAY; i++) {
        params.arr[i] = rand() % 10;   
        printf("%d ", params.arr[i]);   
    }

    params.init = 0;
    params.end = TAM_ARRAY - 1;

    //cria a thread inicial para comecar a chamda da funcao mergeSort
    pthread_create(&tid, NULL, mergeSort, &params);
    pthread_join(tid, NULL);

    printf("\nArray ordenado: ");
    printArray(params.arr);

    return 0;
}