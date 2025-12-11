#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Structure for doubly linked list used in insertion_sort_list */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

#endif /* SORT_H */

