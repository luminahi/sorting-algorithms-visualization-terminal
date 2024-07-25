#include "sorting.h"

void bubble_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  for (int i = 0; i < array_size; i++) {
    for (int j = i + 1; j < array_size; j++) {
      if (array[i] > array[j]) {
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
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

    int aux = array[min_index];
    array[min_index] = array[i];
    array[i] = aux;
  }
}

void insertion_sort(int* array, int array_size, char* bar, void (*fn)(char*, int*, int)) {
  int i = 1;
  while (i < array_size) {
    int j = i;
    while (j > 0 && array[j] < array[j - 1]) {
      int aux = array[j];
      array[j] = array[j - 1];
      array[j - 1] = aux;
      j--;

      fn(bar, array, array_size);
    }

    i++;
  }
}