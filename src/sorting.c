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