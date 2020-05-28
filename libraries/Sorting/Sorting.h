/*
    This is a class for doing sorting operations.
    Josh Sullivan
    2020/05/27
*/
#ifndef SORTING_H
#define SORTING_H

namespace sorting_functions
{
    void swap(int *a, int *b);
    void swap(float *a, float *b);
    void quicksort(int array[], int left, int right);
    void quicksort(float array[], int left, int right);
}; // namespace sorting_functions

#endif