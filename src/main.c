#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

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
    bar[array[i]] = '#';
  }

  wait(0, 10000000L);
}

int main(int argc, char* argv[]) {
  char bar[MAX_BAR_SIZE];
  for (int i = 0; i < MAX_BAR_SIZE; i++) bar[i] = '#';

  srand(time(NULL));
  int arr[MAX_ARRAY_SIZE];
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    arr[i] = (rand() % (MAX_BAR_SIZE - 1)) + 1;
  }

  insertion_sort(arr, MAX_ARRAY_SIZE, bar, &update_screen);
  // selection_sort(arr, bar, &update_screen);
  // bubble_sort(arr, bar, &update_screen);
  return 0;
}
