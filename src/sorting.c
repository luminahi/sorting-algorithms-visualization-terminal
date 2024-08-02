#include <stdlib.h>
#include "sorting.h"

static void swap(int* a, int* b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubble_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  for (int i = 0; i < array_size; i++) {
    for (int j = i + 1; j < array_size; j++) {
      if (array[i] > array[j]) {
        swap(&array[i], &array[j]);
      }

      fn(bar, array, array_size);
    }
  }
}

void selection_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  for (int i = 0; i < array_size; i++) {
    int min_index = i;
    for (int j = i + 1; j < array_size; j++) {
      if (array[min_index] > array[j]) {
        min_index = j;
      }

      fn(bar, array, array_size);
    }

    swap(&array[min_index], &array[i]);
  }

  fn(bar, array, array_size);
}

void insertion_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  int i = 1;
  while (i < array_size) {
    int j = i;
    while (j > 0 && array[j] < array[j - 1]) {
      swap(&array[j], &array[j - 1]);
      j--;

      fn(bar, array, array_size);
    }

    i++;
  }
}

void merge(int* array, int start, int mid, int end) {
    int size = end - start + 1;
    int index_start = start;
    int index_mid = mid + 1;
    int index_aux = 0;

    int* array_aux = (int*) malloc(sizeof(int) * size);

    while (index_start <= mid && index_mid <= end) {
        if (array[index_start] < array[index_mid]) {
            array_aux[index_aux] = array[index_start];
            index_start++;
        } else {
            array_aux[index_aux] = array[index_mid];
            index_mid++;
        }

        index_aux++;
    }

    while (index_start <= mid) {
        array_aux[index_aux] = array[index_start];
        index_aux++;
        index_start++;
    }

    while (index_mid <= end) {
        array_aux[index_aux] = array[index_mid];
        index_aux++;
        index_mid++;
    }

    for (index_aux = start; index_aux <= end; index_aux++) {
        array[index_aux] = array_aux[index_aux - start];
    }

    free(array_aux);
}

void start_merge_sort(int* array, int start, int end, int array_size, char* bar, void (*fn)(char*, int*, int)) {
    if (start < end) {
        int mid = (end + start) / 2;

        start_merge_sort(array, start, mid, array_size, bar, fn);
        start_merge_sort(array, mid + 1, end, array_size, bar, fn);

        merge(array, start, mid, end);
        fn(bar, array, array_size);
    }
}

void merge_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  int end = array_size - 1;
  start_merge_sort(array, 0, end, array_size, bar, fn);
}
