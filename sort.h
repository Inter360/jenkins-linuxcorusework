#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h> // strcmp
#include <stddef.h> // size_t
void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(char** arr, size_t length)
{
    if (arr == NULL || length < 2)
        return;

    size_t i = 0;
    size_t j = length - 1;
    char* pivot = arr[length / 2];

    while (i <= j)
    {
        while (strcmp(arr[i], pivot) < 0)
            i++;
        while (strcmp(arr[j], pivot) > 0)
        {
            if (j == 0) break; 
            j--;
        }

        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            if (j > 0) j--;
            else break;
        }
    }

    if (j > 0)
        quick_sort(arr, j + 1);
    if (i < length)
        quick_sort(arr + i, length - i);
}
#endif // !SORT