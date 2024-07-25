#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define BAR_SYMBOL '.'
#define MAX_BAR_SIZE 48
#define MAX_ARRAY_SIZE 32

void wait(int seconds, long nano_seconds) {
  struct timespec req;
  struct timespec rem;
  req.tv_sec = seconds;
  req.tv_nsec = nano_seconds;

  nanosleep(&req, &rem);
}

void update_screen(char* bar, int* array, int array_size) {
  system("clear");

  for (int i = 0; i < array_size; i++) {
    bar[array[i]] = '\0';
    printf("%s\n", bar);
    bar[array[i]] = BAR_SYMBOL;
  }

  wait(0, 10000000L);
}

void shuffle(int* array) {
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    array[i] = (rand() % (MAX_BAR_SIZE - 1)) + 1;
  }
}

int main(int argc, char* argv[]) {
  srand(time(NULL));

  char bar[MAX_BAR_SIZE];
  for (int i = 0; i < MAX_BAR_SIZE; i++) bar[i] = BAR_SYMBOL;

  int array[MAX_ARRAY_SIZE];
  shuffle(array);

  char option;
  while (1) {
    printf("1: Bubble Sort\n2: Selection Sort\n3: Insertion Sort\n0: Quit\n\n");
    option = getchar();

    printf("scanning...");

    switch (option) {
    case '1':
      bubble_sort(array, MAX_ARRAY_SIZE, bar, &update_screen);
      break;
    case '2':
      selection_sort(array, MAX_ARRAY_SIZE, bar, &update_screen);
      break;
    case '3':
      insertion_sort(array, MAX_ARRAY_SIZE, bar, &update_screen);
      break;
    case '0':
      exit(EXIT_SUCCESS);
    default:
      break;
    }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF) {}

    shuffle(array);
  }
  
  return 0;
}
