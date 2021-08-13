#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define TAM_ARRAY 8
#define NUM_THREADS 2

typedef struct {
  int *arr;
  int init;
  int end;
} Merge;

void merge(int arr[], int init, int end, int middle) ;
void *mergeSort(void *args);
void printArray();