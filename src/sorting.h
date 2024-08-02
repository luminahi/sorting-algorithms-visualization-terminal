#ifndef _SORTING_H
#define _SORTING_H

void bubble_sort(int*, int, char*, void (*fn)(char*, int*, int));

void selection_sort(int*, int, char*, void (*fn)(char*, int*, int));

void insertion_sort(int*, int, char*, void (*fn)(char*, int*, int));

void merge_sort(int*, int, char*, void (*fn)(char*, int*, int));

#endif
