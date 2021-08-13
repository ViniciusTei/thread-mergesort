#include "merge.h"

void merge(int arr[], int init, int end, int middle) {
    // int tid = pthread_self();
    // printf("\nThread: %d", tid);

    int n1 = middle - init + 1;
    int n2 = end - middle;

    //cria dois sub arrays temporarios do array principal
    int tempL[n1], tempR[n2];

    for (int i = 0; i < n1; i++)
        tempL[i] = arr[init + i];
    for (int j = 0; j < n2; j++)
        tempR[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = init;


    //volta os arrays temporarios para o array principal
    while(i < n1 && j < n2) {
      if(tempL[i] <= tempR[j]) {
        arr[k] = tempL[i];
        i++;
      } else {
        arr[k] = tempR[j];
        j++;
      }
      k++;
    }

    //entao copia os items que sobraram em cada array
    while(i < n1) {
      arr[k] = tempL[i];
      i++;
      k++;
    }

    while(j < n2) {
      arr[k] = tempR[j];
      j++;
      k++;
    }

}

void *mergeSort(void *args) {
    Merge *item = (Merge *) args;
    Merge itemLeft, itemRigth;

    if(item->init < item->end) {
      int middle = item->init + (item->end - item->init) / 2;
      pthread_t tid[NUM_THREADS];

      itemLeft.arr = item->arr;
      itemLeft.init = item->init;
      itemLeft.end = middle;

      itemRigth.arr = item->arr;
      itemRigth.init = middle +1;
      itemRigth.end = item->end;
      //create threads
      pthread_create(&tid[0], NULL, mergeSort, &itemLeft);
      pthread_create(&tid[1], NULL, mergeSort, &itemRigth);

      //joining the threads
      pthread_join(tid[0], NULL);
      pthread_join(tid[1], NULL);

      merge(item->arr, item->init, item->end, middle);
      pthread_exit(NULL);
    
    } else {
      return 0;
    }

    
}
 
void printArray(int arr[]) {
    for (int i = 0; i < TAM_ARRAY; i++)
        printf("%d ", arr[i]);
    printf("\n");
}