#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define BAR_SYMBOL '.'
#define MAX_BAR_SIZE 48
#define MAX_ARRAY_SIZE 24

void wait(int seconds, long nano_seconds) {
  struct timespec req;
  struct timespec rem;
  req.tv_sec = seconds;
  req.tv_nsec = nano_seconds;

  nanosleep(&req, &rem);
}

void print_options(const char* options[], int n) {
  for (int i = 0; i < n; i++) {
    printf("\033[%d;1H%s", MAX_ARRAY_SIZE + i + 2, options[i]);
    printf("\033[K");
  }
}

void clear_screen() {
  for (int i = 1; i <= MAX_ARRAY_SIZE; i++) {
    printf("\033[%d;1H", i);
    printf("\033[K");
  }

  printf("\033[H");
}

void update_screen(char* bar, int* array, int array_size) {
  clear_screen();

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

  const char* options[] = {
    "1 - Bubble Sort",
    "2 - Selection Sort",
    "3 - Insertion Sort",
    "4 - Merge Sort",
    "0 - Exit"
  };

  print_options(options, sizeof(options)/sizeof(char*));
  update_screen(bar, array, MAX_ARRAY_SIZE);

  while (1) {
    char option = getchar();

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
    case '4':
      merge_sort(array, MAX_ARRAY_SIZE, bar, &update_screen);
      break;
    case '0':
      exit(EXIT_SUCCESS);
    default:
      printf("Invalid Option\n");
      exit(EXIT_FAILURE);
      break;
    }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF) {}

    shuffle(array);
  }
  
  return 0;
}
