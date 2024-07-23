#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAR_SIZE 64
#define MAX_ARRAY_SIZE 32

void update_screen(char* bar, int* array) {
  system("clear");

  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    bar[array[i]] = '\0';
    printf("%s\n", bar);
    bar[array[i]] = '#';
  }
}

void wait(int seconds, long nano_seconds) {
  struct timespec req;
  struct timespec rem;
  req.tv_sec = seconds;
  req.tv_nsec = nano_seconds;

  nanosleep(&req, &rem);
}

void bubble_sort(int* array, char* bar, void (*fn)(char*, int*)) {
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    for (int j = i + 1; j < MAX_ARRAY_SIZE; j++) {
      if (array[i] > array[j]) {
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }

      wait(0, 10000000L);
      fn(bar, array);
    }
  }
}

int main(int argc, char* argv[]) {
  char bar[MAX_BAR_SIZE];
  for (int i = 0; i < MAX_BAR_SIZE; i++) bar[i] = '#';


  srand(time(NULL));
  int arr[MAX_ARRAY_SIZE];
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    arr[i] = (rand() % (MAX_BAR_SIZE - 1)) + 1;
  }

  bubble_sort(arr, bar, &update_screen);
  return 0;
}
